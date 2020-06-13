#include <iostream>
#include "commands.h"

using namespace std;


int main ()
{

    int number;
    help();
    
    while (true)
    {
        cout << "Choose an option from the menu.. "<<endl;
        cin >> number;

        switch (number)
        {
            case 1:
                Open();
                break;
            case 2:
                Close();
                break;
            case 3:
                Save();
                break;
            case 4:
                SaveAs();
                break;
            case 5: 
                help();
                break;
            case 6:
            cout<<"Bye! ";
                exit();
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