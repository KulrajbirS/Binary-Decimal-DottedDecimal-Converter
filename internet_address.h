//The interface file internet_address.h defining the class Internet_Address
#include <iostream>
using namespace std;

#ifndef INTERNET_ADDRESS_H
#define INTERNET_ADDRESS_H

class Internet_Address
{
    private:
        string decimal_address;
        string binary_address;
        string dotted_address;

    public:
        //Contructors
        Internet_Address (string address);
        Internet_Address ();
        Internet_Address (const Internet_Address& address);
        ~Internet_Address ();

        //Mutators for Member Functions
        void setBinaryAd(string a);
        void setDottedAd(string a);
        void setDecimalAd(string a);

        //Accessors for Member Functions
        string getBinaryAd();
        string getDottedAd();
        string getDecimalAd();

        //To print the Addresses
        void print();

    private:
        //Convert Address from decimal to binary
        string convertDecimaltoBinary(string a);

        //Convert Address from binary to decimal
        string convertBinarytoDecimal(string a);

        //Convert Address from decimal to dotted decimal
        string convertDecimaltoDottedDecimal(string a);

        //Convert Address from binary to dotted decimal
        string convertBinarytoDottedDecimal(string a);

        //Convert Address from dotted decimal to decimal
        string convertDottedDecimaltoDecimal(string a);

        //Convert Address from dotted decimal to binary
        string convertDottedDecimaltoBinary(string a);

        //To Check if value entered is Binary
        bool isBinary(string n);

        //To check if value entered is Dotted Decimal
        bool isDottedDecimal(string n);
        
        //Remove spaces from binary
        static string removeSpace(string s);

};

#endif