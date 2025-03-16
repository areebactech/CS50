#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length = 0;
    int first_two_digits;
    long n;
    int sum = 0;
    int counter = 0;
    int answer = 0;


    do
    {
        n = get_long("Number: ");
    }
    while (n <= 0);
    while ( n != 0)
    {
        first_two_digits = n;
        n /= 10;
        length++;
    }
    for (; n != 0; n /= 10)
    if (counter % 2 == 0);
        {n += sum;}

     else
     {
      n = n * 2;
     if (answer > 9);
     (n = answer - 9);
     (n = answer + sum);
     (counter++);
     }
    }


