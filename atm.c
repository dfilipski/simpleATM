#include <stdio.h>
#include <stdlib.h>

char getMode();
void deposit();
void withdraw();

double bal = 0;

int main ()
{
    while (1)
    {
        char mode;

        printf("\n\n");

        printf("Your current balance is $%.2f.\n", bal);
        mode = getMode();

        if (mode == 'D' || mode == 'd')
        {
            deposit();
        }
        else if (mode == 'W' || mode =='w')
        {
            withdraw();
        }
    }

    return 0;
}

char getMode()
{
    char m;

    printf("Please select an actoin:\n");
    printf("[D]eposit\n");
    printf("[W]ithdraw\n");
    
    m = getchar();

    return m;
}

void deposit()
{
    double d;
    char buf[1024];

    printf("How much would you like to deposit?\n");
    do
    {
        if (!fgets(buf, 1024, stdin))
        {
            /*Reading failed*/
            return;
        }

        d = atof(buf);
        printf("$");

    } while (d == 0);

    printf("You deposited %.2f.", d);
    bal += d;
}

void withdraw()
{
    double d;
    char buf[1024];

    printf("How much would you like to withdraw?\n");
    do
    {
        if (!fgets(buf, 1024, stdin))
        {
            /*Reading failed*/
            return;
        }

        d = atof(buf);
        printf("$");

    } while (d == 0);

    if (d > bal)
    {
        printf("\nSorry, you can only withdraw money that you have.\n");
        return;
    }
    else {
        printf("You withdrew %.2f.", d);
        bal -= d;
    }
}
