/** Jennifer Byrne
    02/10/2017
    Lab 6
    Decimal / Binary Conversion */

/** Preprocessor directives */
#include <iostream>
#include <iomanip>
/** allows getchar() */
#include <cstdio>
/** allows system(cls) */
#include <windows.h>
#include <math.h>

/** Enables cout, cin and endl */
using namespace std;

/** Declaring sub functions */
void bin_2_dec(void);
void dec_2_bin(void);
char displaymenu(void);


/** Main function */
int main()
{
    char choice;

    do
    {
        choice = displaymenu();


        /** User options to select which conversion is needed, invalid input or quit */
        switch (choice)
        {
            case 'b' :      bin_2_dec();
                            break;

            case 'd' :      dec_2_bin();
                            break;

            case 'q' :      system("cls");
                            cout << "Goodbye" << endl;
                            break;

            default  :      cout << "Invalid selection" << endl;
                            break;

        }

    }
     /** Conditions for while loop */
    while (choice != 'q');

    /** Terminate main function */
    return 0;
}


/** function header */
    char displaymenu(void)
{
    /** declaring variable type char */
    char choice;
    /** turns previous screen off */
    system("cls");
    /** user enters which command they want to use */
    cout << "Conversion Calculator \n\n";
    cout << "Press b for bin-dec conversion \n";
    cout << "Press d for dec-bin conversion \n";
    cout << "Press q to quit \n\n";

    choice = getchar();
    return choice;
}

/** bin to dec sub-function */
void bin_2_dec()
{
    /** declaring int and long int variables */
    long int bin, dec = 0, remainder = 0;
    int i = 0;

    /** turns previous screen off */
    system("cls");

    /** display headin on console and read in value */
    cout << "Enter Binary number to be converted : \t" ;
    cin >> bin;
    /** while bin is greater than 0 */
    while (bin != 0)
    {
        /** remainder = binary number / 10 */
        remainder = bin % 10;
        /** binary = binary / 10 */
        bin /= 10;
        /** decimal = remainder * 2^i (i = 0 on first loop, 1 on second etc */
        dec = dec + remainder  * pow(2, i);
        i++;
    }
    /** Display binary = decimal value */
    cout << "\n\t\t    Decimal value :   " << dec ;

    cout << "\n\nPress enter to return to the main menu...";

    fflush(stdin);
    getchar();


    /** return to main function */
    return ;
}

/** decimal to binary sub-function */
void dec_2_bin()
{
    /** declaring int and long int variables */
    long int decimal, binary = 0, rem=0, arrayval[8]={0};
    int i = 0;

    /** turns previous screen off */
    system("cls");

    /** display headin on console and read in value */
    cout << "Enter Decimal number to be converted : \t" ;
    cin >> decimal;
    /** while decimal is greater than 0 */
    while (decimal != 0)
    {
        /** rem = the remainder of decimal after its been divided by 2 */
        rem = decimal % 2;
        /** decimal = decimal /2 */
        decimal /= 2;
        /** binary = binary + rem */
        //binary += rem;
        /** increment i each loop */
        arrayval[i]=rem;
        i++;
    }

    /** condition for for loop to dipsplay bin num backwards */
    for(i=7; i>=0; i--)
    {
        cout << arrayval[i];
    }

    cout << "\n\nPress enter to return to the main menu...";

    fflush(stdin);
    getchar();

    /** Return to main function */
    return ;
}
