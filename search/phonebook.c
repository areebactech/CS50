#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Umer", "Areesha", "Ahmed", "Tuba"};
    string numbers[] = {"0321-6928133", "0300-0765547", "0307-0561327","+92 305 2662894" };

    string name = get_string("Name: ");
    for (int i = 0; i < 4; i++)
    {
        if(strcmp(names[i],name) == 0)
        {
            printf("Found %s\n" , numbers[i]);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
