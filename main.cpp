#include <iostream>
#include "commands.h"

using namespace std;


int main ()
{
    int number;
    help();
    
    while (true)
    {
        cout << "Which number do u giv me?? "<<endl;
        cin >> number;

        switch (number)
        {
            
            case 5: 
                help();
                break;
            case 6:
                cout << "Bye!";
                exit(0);
                break;
            case 8:
                add();
                break;
            default: 
                cout << "Please enter a valid number"<<endl;
                break;
        }
    }
}