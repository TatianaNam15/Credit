#include <cs50.h>
#include <stdio.h>

//function prototypes
int digits(long a);
int checksum(long b);
string type(long c, int d, int f);

long n;
int count;
int check;

int main(void)
{
    // Get card number from user
    do
    {
        n = get_long("Card number: ");
    }
    while (n < 0);

    // Count number of digits
    digits(n);

    // Count the checksum
    checksum(n);

    // Check type of the card
    type(n, count, check);
}

// Define a function to count number of digits in card number
int digits(long a)
{
    count = 0;
    long m = n;
    do
    {
        count++;
        m /= 10;

    }
    while (m > 0);

    return count;
}

// Define a function to count the checksum
int checksum(long b)
{
    int sumodd = 0;
    int sumeven = 0;
    long m = n;

    // Using loop to get odd and even digits of card number
    do
    {
        // Getting last (odd) digit from card number and assigning it ot a new variable 'o'
        int o = m % 10;

        // Removing last digit from card number
        m /= 10;

        // Getting last (even) digit from card number and assigning it ot a new variable 'e'
        // Multiplying 'e' by 2
        int e = (m % 10) * 2;

        // Checking if 'e' includes more than one digit
        if (e >= 10)
        {
            // Adding digits
            int a = e % 10;
            e /= 10;
            e = e + a;
        }

        // Removing last digit from card number
        m /= 10;

        // Defining the summary of odd and the summary of even digits
        sumodd += o;
        sumeven += e;
    }
    while (m != 0);

    check = sumodd + sumeven;

    return check;
}

// Define a function to check type of the card
string type(long c, int d, int f)
{
    long m = n;

    if (check % 10 == 0)
    {
        for (int i = 0; i < count - 2; i++)
        {
            m /= 10;
        }

        if ((count == 15) && (m == 34 || m == 37))
        {
            printf("AMEX\n");
        }

        else if ((count == 16) && (m == 51 || m == 52 || m == 53 || m == 54 || m == 55))
        {
            printf("MASTERCARD\n");
        }

        else if ((count == 13 || count == 16) && (m / 10 == 4))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

    return 0;
}
