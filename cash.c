#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    int coins = 0;

    do
    {
        printf("Change owed : ");
        scanf("%d", &cents);
    }

    while (cents < 0);

    // Calculate quarters
    coins += cents / 25;
    cents %= 25;

    // Calculate dimes
    coins += cents / 10;
    cents %= 10;

    // Calculate nickels
    coins += cents / 5;
    cents %= 5;

    // Calculate pennies
    coins += cents;

    printf("%d\n", coins);

    return 0;
}
