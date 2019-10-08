#include <iostream>
#include "stdlib.h"
using namespace std;

union double_data {
    unsigned char ch[8];
    double data;
};

//Union structure in which data is stored in two different types
void ShowCharBin(unsigned char var)
{

    for (int i = 7; i >= 0; i--)
    {
        cout << ((var >> i) & (char)1);

    }
}
//Displays the binary code of the symbol, in order to clearly see how the data is stored in the computer
void OutChar(unsigned char simbol)
{
    cout << "\n" << "|Char|DataByte|\n";
    cout << "|";
    cout.width(4);cout << simbol;
    cout<<"|";
    ShowCharBin(simbol);
    cout << "|\n";
}//Sets binary information of char data into a table

void InvertCharBin(unsigned char &var,int number)
{
    int tmp3;
    int tmp = 1;
    int tmp2 = 255;
    tmp = tmp << (8-number);
    ShowCharBin(var);
    cout << "--->";


    if (((var >>(8-number))&(char)1))
    {
        tmp2 = tmp2 ^ tmp;
        tmp3 = (unsigned char)var & tmp2;
        var = (unsigned char)tmp3;
    }
    else
    {
        tmp3 = (unsigned char)var | tmp;
        var = (unsigned char)tmp3;
    }
    ShowCharBin(var);
    cout << endl;
}
//Inverts a specific byte of a binary character code
void ShowDouble(double_data var)
{
    cout << "\n|    DoubleNumber|1st Byte|2nd Byte|3rd Byte|4th Byte|5th Byte|6th Byte|7th Byte|8th Byte|\n|";
    cout.width(16);cout << var.data;
    cout << "|";
    for (int i = 7; i >= 0; i--)
    {
        ShowCharBin(var.ch[i]);
        cout << "|";
    }
    cout << "\n";
}
//Displays the binary code of the double type number, in order to clearly see how the data is stored in the computer
void InvertDouble(double_data &var, int number)
{
    div_t d;
    d = div(number,8);
    unsigned char tmp = var.ch[7-d.quot];
    InvertCharBin(tmp,d.rem);
    var.ch[7-d.quot] = tmp;
}
//Inverts a specific byte of a binary character code

int main()
{
    int cases,invert;
    cout << "1. Char\n2. Double\n";
    cin >> cases;
    switch (cases)
    {
        case 1:
            unsigned char simbol;
            cout << "Enter symbol:";
            cin >> simbol;
            OutChar(simbol);

            cout << "\nInvert?\n";
            cin >> invert;
            if (invert == 1)
            {
                int number;
                bool flag = 1;

                while (flag==1)
                {
                    cout << "Enter number of bit\n";
                    cin >> number;
                    InvertCharBin(simbol, number);
                    OutChar(simbol);
                    cout << "Invert else?\n";
                    bool cont;
                    cin >> cont;
                    if (cont == 0)
                    {
                        flag = 0;
                    }
                }
            }

            cout << "\n";
            break;
        case 2:
            double_data A;
            cout << "Enter number:";
            cin >> A.data;
            ShowDouble(A);

            cout << "\nInvert?\n";
            cin >> invert;
            if (invert == 1)
            {
                int number;
                bool flag = 1;
                while (flag == 1)
                {
                    cout << "Enter number of bit\n";
                    cin >> number;

                    InvertDouble(A, number);
                    ShowDouble(A);
                    cout << "Invert else?\n";
                    bool cont;
                    cin >> cont;
                    if (cont == 0)
                    {
                        flag = 0;
                    }
                }
            }
            cout << "\n";
            break;
        default:
            break;
    }
    return 0;
}