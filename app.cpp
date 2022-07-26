//The application file app.cpp uses the Internet_Address Objects
#include <iostream>

//Including interface and implementation file
#include "internet_address.h"
#include "internet_address.cpp"
using namespace std;

int main()
{
    string addressC = "";
    string bin = "";
    addressC = '0'
    int count = 1;
    
    while(addressC != "-1"){
        cout << "Which Address do you want to Enter (to quit: -1)" << endl;
        cout << "1. Binary Address" << endl;
        cout << "2. Decimal or Dotted Decimal Address" << endl;
        cout << "Your Choice: ";
        cin >> addressC;
        if(addressC == "1")
        {
            cout << endl << "Please Enter Binary Address in 4 separate 8bit Sections" << endl;
            while(count < 5)
            {
                cout << to_string(count) << " :";
                cin >> addressC;
                bin += addressC;
                count++;
            }
            count = 0;
            addressC = bin;
            Internet_Address address(addressC);
            address.print();
        }
        else if(addressC == "2")
        {
            cout << endl << "Enter your Internet Address: ";
            cin >> addressC;
            Internet_Address address(addressC);
            address.print();
        }
        else if(addressC == "-1")
        {
            break;
        }
    }
    cout << endl << "Thank You for using my program. Bye for now!" << endl;
    return 0;
}