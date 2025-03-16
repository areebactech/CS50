#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_key(string s);
string caesar_cipher(string text, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!is_valid_key(argv[1]))
    {
        printf("Key must be a positive integer.\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    string ciphertext = caesar_cipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool is_valid_key(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

string caesar_cipher(string text, int key)
{
    int n = strlen(text);
    string ciphertext = text;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            char offset = isupper(text[i]) ? 'A' : 'a';
            ciphertext[i] = (text[i] - offset + key) % 26 + offset;
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }

    return ciphertext;
}
