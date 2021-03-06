#include <stdio.h>
#include <stdlib.h>

char getMode();
void getAccNum(char accNum[12]);
void deposit();
void withdraw();
void writeBal();
void readBal();

double bal = 0;

int main ()
{
    readBal();

    char accountStr[12];
    getAccNum(accountStr);
    printf("Your account number is %s.\n", accountStr);

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
        else if (mode == 'E' || mode == 'e')
        {
            writeBal();
            break;
        }
    }

    return 0;
}

char getMode()
{
    char m, n;

    printf("Please select an action:\n");
    printf("[D]eposit\n");
    printf("[W]ithdraw\n");
    printf("[E]xit\n");
    
    m = getchar();
    n = getchar(); /*Remove enter from standard in*/

    return m;
}

void getAccNum(char accnum[12])
{
    printf("Enter your account number:\n");
    if (fgets(accnum, 12, stdin))
    {
        accnum[strcspn(accnum, "\n")] = 0;
    }
}

void deposit()
{
    double d;
    char buf[1024];

    printf("How much would you like to deposit?\n");
    do
    {
        printf("$");
        if (!fgets(buf, 1024, stdin))
        {
            /*Reading failed*/
            return;
        }

        d = atof(buf);


    } while (d <= 0);

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
        printf("$");
        if (!fgets(buf, 1024, stdin))
        {
            /*Reading failed*/
            return;
        }

        d = atof(buf);


    } while (d <= 0);

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

void writeBal()
{
    FILE *fptr;
    fptr = fopen("bal.txt", "w");
    fprintf(fptr, "%.2lf", bal);
    fclose(fptr);
}

void readBal()
{
    FILE *fptr;

    if ((fptr = fopen("bal.txt", "r")) == NULL)
    {
        printf("No bal.txt was found\n");
        return; /*Do nothing if there is no bal.txt file*/
    }

    fscanf(fptr, "%lf", &bal);
    fclose(fptr);
    return;
}