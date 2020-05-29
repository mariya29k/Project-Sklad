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
            case 1:
                Open();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                SaveAs();
                break;
            case 5: 
                help();
                break;
            case 6:
                cout << "Bye!";
                exit(0);
                break;
            case 7:
                print();
                break;
            case 8:
                add();
                break;
            case 9:
                remove();
                break;
            case 10:
                log();
                break;
            case 11:
                clean();
                break;
            default: 
                cout << "Please enter a valid number"<<endl;
                break;
        }
    }
}