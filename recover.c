#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define the block size
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL; // File pointer for the JPEG
    char filename[8]; // Buffer to store the filename
    int file_counter = 0; // Counter to name the JPEG files

    // Read blocks of data from the memory card
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        // Check if the block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If a file is already open, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new JPEG file
            sprintf(filename, "%03i.jpg", file_counter);
            img = fopen(filename, "w");
            file_counter++;
        }

        // If a JPEG file is open, write the buffer to it
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    // Close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }

    // Close the memory card
    fclose(card);

    return 0;
}
