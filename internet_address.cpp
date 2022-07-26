//The implementation file internet_address.cpp consisting of Data Member Function Definitions
#include <iostream>

//Including interface file
#include "internet_address.h"
using namespace std;

//Parametric Contuctor
Internet_Address :: Internet_Address(string a)
{
    //Conditional Statment to check if the value passed to the
    //Constructor is Decimal, Binary or Dotted Decimal

    //Removes any spaces
    string s = removeSpace(a);
    if(isDottedDecimal(s)) //Checks if the value is Dotted Decimal
    {
        dotted_address = s;
        //Get Binary and Decimal Values
        binary_address = convertDottedDecimaltoBinary(dotted_address);
        decimal_address = convertDottedDecimaltoDecimal(dotted_address);
    }
    else if(isBinary(s)) //Checks if the value is Binary
    {
        //Adds 0s in front if the value entered is not 32 bits
        while(s.length() < 32)
            {
                s = "0" + s;
            }
        binary_address = s;
        //Get Dotted Decimal and Decimal Values
        decimal_address = convertBinarytoDecimal(binary_address);
        dotted_address = convertBinarytoDottedDecimal(binary_address);
    }
    else
    {
        decimal_address = s;
        //Get Binary and Dotted Decimal Values
        string add = convertDecimaltoBinary(decimal_address);
        while(add.length() < 32)
        {
            add = "0" + add;
        }
        binary_address = add;
        dotted_address = convertDecimaltoDottedDecimal(decimal_address);
    }
    
}

//Default Constrcutor
Internet_Address :: Internet_Address()
: decimal_address("12345678")
{
    binary_address = convertDecimaltoBinary(decimal_address);
    dotted_address = convertDecimaltoDottedDecimal(decimal_address);
}

//Copy Constructor
Internet_Address :: Internet_Address(const Internet_Address& address)
: decimal_address (address.decimal_address), binary_address(address.binary_address), dotted_address(address.dotted_address)
{}

//Destructor
Internet_Address :: ~Internet_Address ()
{}

//Mutators
void Internet_Address :: setBinaryAd(string a)
{
    binary_address = a;
}

void Internet_Address :: setDecimalAd(string a)
{
    decimal_address = a;
}

void Internet_Address :: setDottedAd(string a)
{
    dotted_address = a;
}

//Accessors
string Internet_Address :: getBinaryAd()
{
    return binary_address;
}

string Internet_Address :: getDecimalAd()
{
    return decimal_address;
}

string Internet_Address :: getDottedAd()
{
    return dotted_address;
}

//Remove Spaces
string Internet_Address :: removeSpace(string s)
{
    string result = "";
    for(char c: s)
    {
        if(c != ' ')
        {
            result += c;
        }
    }
    return result;
}

//To Check if the number is Binary
bool Internet_Address :: isBinary(string n)
{
    bool binary = false;
    for(char c: n)
    {
        if(c == '0' || c == '1')
        {
            binary = true;
        }
        else
        {
            binary = false;
            break;
        }
    }
    return binary;
}

//Convert Address from Binary to Decimal
string Internet_Address :: convertBinarytoDecimal(string s)
{
    long long int base = 1;
    long long int binary_result = 0;
    if(s.length() == 32)
    {
        string a[4];
        int k = 0;
        string b;
        for(int i = 0; i < s.length(); i = i + 8)
        {
            a[k] = s.substr(i,8);
            k++;
        }
        for(int j = 3; j >= 0; j--)
        {
            int count = 0;
            long num = stol(a[j]);
            long temp = num;
            while(temp) {
                int last = temp%10;
                temp /= 10;

                binary_result += last * base;

                base *= 2;
                count++;
            }
            if(count < 8)
            {
                while(count < 8)
                {
                    base *=2;
                    count++;
                }
            }
        }
    }
    else{
        long num = stol(s);
            long temp = num;
            while(temp) {
                int last = temp%10;
                temp /= 10;

                binary_result += last * base;

                base *= 2;
            }
    }

    string address = to_string(binary_result);
    return address;
}

//Convert Address from Decimal to Binary
string Internet_Address :: convertDecimaltoBinary(string s)
{
    long num = stol(s);
    string a = "";
    while(num>0)
    {
        a = to_string(num%2) + a;
        num /= 2;
    }

    return a;
}

//Convert Address from Dotted Decimal to Binary
string Internet_Address :: convertDottedDecimaltoBinary(string s)
{
    int a[4];
    int i = 0;
    string dec;
    int pos;
    //Stores 4 values of Dotted Decimal number separately
    while(i < 4)
    {
        pos = s.find(".");
        dec = s.substr(0, pos);
        a[i] = stoi(dec);
        s.erase(0, s.find(".") + 1);
        i++;
    }

    string binary = "";
    string medium = "";
    //Converts the separated values in Binary
    for(int k = 0; k < 4; k++)
    {
        medium = convertDecimaltoBinary(to_string(a[k]));
        while(medium.length() < 8)
            {
                medium = "0" + medium;
            }
        binary += medium;
    }

    //Adds 0s if the binary string is not 32 bits
    while(binary.length() < 32)
    {
        binary = "0" + binary;
    }

    return binary;
}

//Convert Address from Dotted Decimal to Decimal
string Internet_Address :: convertDottedDecimaltoDecimal(string a)
{
    string binary = convertDottedDecimaltoBinary(a);
    string decimal = convertBinarytoDecimal(binary);
    return decimal;
}

//Convert Address from Binary to Dotted Decimal
string Internet_Address :: convertBinarytoDottedDecimal(string s)
{
    //Splits the Binary in separate smaller sections
    //And stored in an integer array
    int a[4];
    int j =0;
    string b;
    for(int i = 0; i < s.length(); i = i + 8)
    {
        a[j] = stoi(s.substr(i,8));
        j++;
    }

    //Goes through the array and converts small sections into decimals
    //And concatenates them into string by adding dots
    string dotted = "";
    for(int k = 0; k < 4; k++)
    {
        dotted += convertBinarytoDecimal(to_string(a[k]));
        if(k !=3)
        {
            dotted += ".";
        }
    }

    return dotted;
}

//Convert Decimal to Dotted Decimal
string Internet_Address :: convertDecimaltoDottedDecimal(string s)
{
    string binary = convertDecimaltoBinary(s);
    //Adds 0s to the front of binary if it is not 32 bits
    while(binary.length() < 32)
    {
        binary = "0" + binary;
    }
    string dotted = convertBinarytoDottedDecimal(binary);
    return dotted;
}

//To Check if the value entered is Dotted Decimal
bool Internet_Address :: isDottedDecimal(string n)
{
    for(char c : n)
    {
        if(c == '.')
        {
            return true;
        }
    }
    return false;
}

//To print the Addresses
void Internet_Address :: print()
{
    cout << endl << "Your Internet address in three different formats:" << endl;
    cout << "Decimal Format: " << decimal_address << endl;
    cout << "Binary Format: ";
    //Prints the Binary Format with spaces separating 32 bits into 4 groups of 8 bits
    for(int i = 0; i < binary_address.length(); i = i + 8)
    {
        cout<< binary_address.substr(i,8) << " ";
    }
    cout << endl;
    cout << "Dotted Decimal Format: " << dotted_address << endl << endl;
}