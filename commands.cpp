#include <iostream>
#include <fstream>
#include "string.h"
#include "product.h"
#include "date.h"
#include "storage.h"


using namespace std;

Storage storage;
ofstream StorageFile;
ofstream NewStorageFile;


void Open ()
{
    //first we check whether the file is already opened
    if(StorageFile.is_open())
    {
        cout<<"File is already opened! "<<endl;
    } 
    else 
    {   
        cout<<"File is now opened! "<<endl;
        StorageFile.open("storage.txt", ios::out);
    }
    
    //then we check for errors
    if (StorageFile.fail())
    {
        cout<<"Error opening file! "<<endl;
        exit(1); //we close the program exit(0) - successfully executed, exit(1) - closed because of fail
    }
  
}

void Close()
{
    if(StorageFile.is_open())
    { 
        StorageFile.close();
        cout<<"File is closed"<<endl;
    }
    else if(NewStorageFile.is_open())
    {
        NewStorageFile.close();
        cout<<"File is closed"<<endl;
    }
    else cout<<"There are no opened files!"<<endl;

}

bool is_saved = false;

void Save ()
{
    
    if (StorageFile.is_open())
    {
        StorageFile.open("storage.txt", ios::trunc);
    } else StorageFile.open("storage.txt", ios::out);

    if (StorageFile.fail())
    {
        cout<< "Error opening file! ";
        exit(1);
    } 
    else
    {
        StorageFile << storage;
        cout<<"Info is safed! "<<endl;
        is_saved = true;
    }
        

}

void SaveAs ()
{
    
    if (NewStorageFile.is_open())
    {
        cout << "File is already opened!"<<endl;
        cout << "Do you want to overwrite it? Y/N"<<endl;
        char answer;
        cin>>answer;
        if (answer == 'y' || answer == 'Y')
        {
            NewStorageFile.open("newfile.txt", ios::trunc);
        } else  NewStorageFile.close(); //maybe cout "File is closed, choose another function"
    } else  NewStorageFile.open("newfile.txt", ios::out);

    if(NewStorageFile.fail())
    {
        cout<<"Error opening file! ";
        exit(1);
    }
    
    is_saved = true;
    NewStorageFile << storage;
    cout<<"Info is saved in new file! "<<endl;
//PONEJE ARRAY E FULL OF EMPTY PRODUCTS MI EBE MAIKATA NA TEKSTOVIQ FAIL FIKS IT
    NewStorageFile.close();

}



void help ()
{
    cout <<"---------------------------------------------------------------------------\n";
    cout <<"| 1.  Open <file>           opens the file                                 |\n"
         <<"| 2.  Close                 closes currently opened file                   |\n"
         <<"| 3.  save                  saves the currently open file                  |\n"
         <<"| 4.  save as <file>        saves the currently open file in a <file>      |\n"
         <<"| 5.  help                  prints this information                        |\n"
         <<"| 6.  exit                  exists the program                             |\n"
         <<"| 7.  print                 prints all the products in storage             |\n"
         <<"| 8.  add                   adds a new product to storage                  |\n"
         <<"| 9.  remove                removes a product from storage                 |\n"
         <<"| 10. log <from> <to>       shares all changes made to a certain product   |\n"
         <<"| 11. clean                 removes all soon-to-be expired products        |\n";
    cout <<"---------------------------------------------------------------------------\n";
}

void exit()
{
    if(is_saved == 0)
    {
        cout<<"File isn't saved! Do you want to save it? Y/N"<<endl;
        char answer;
        cin>>answer;
        if(answer == 'Y' || answer == 'y')
        {
            Save();
            cout<<"File is saved!"<<endl;
            cout<<"Bye! "<<endl;
            exit(0);
        } else exit(0);
    } else exit(0);
}


void print()
{
    cout<<storage;
}

void add ()
{  
    string name;
    Date expiration;
    Date in_storage;
    string manufacturer;
    double weight;
    string comment;
    Date today;
    today.today_date();

    cout<<"You are adding a new product to storage! "<<endl;
    cout<<"Add the name of the product: "<<endl;
    cin.get();
    getline(cin,name);
    cout<<"\n Enter the expiration date of the product: "<<endl;
    do{
        cin>>expiration;
    } while ((!(expiration.isValid())) || expiration < today);
    cout<<"\n Enter the date when the product came in: "<<endl;
    do{
        cin>>in_storage;
    } while (!(in_storage.isValid()));
    cout<<"\n Enter the name of the manufacturer: "<<endl;
    cin.get();
    getline(cin,manufacturer);
    cout<<"\n Enter weight: "<<endl;
    cin>>weight;
    cout<<"\n Enter a comment about the product: "<<endl;
    cin.get();
    getline(cin,comment);
    cout<<endl;

    Product current = Product(name, expiration, in_storage, manufacturer, weight, comment);
    //storage.IncreaseAvailability(current);
    storage.addProduct(current);
    cout<<current<<endl;
}




void remove()
{//tuk trqbva da poluchava availability, a ne weight ppc
    string name;
    int quantity;
    cout<<"You are removing a product from storage!"<<endl;
    cout<<"Enter the name of the product you want removed: "<<endl;
    cin>>name;
    cout<<"Enter the quantity you want removed: "<<endl;
    cin>>quantity;
    cout<<storage.removeProduct(name, quantity);
}

void log()
{
    Date from;
    Date to;
    cout<<"Enter date from which you want to see information: "<<endl;
    cin>>from;
    cout<<"Enter date up to which you want to see information: "<<endl;
    cin>>to;
    storage.SortByDate(storage);
    cout<<storage;

}

void clean()
{
    // Product removed;
    // cout<<"Expired products! "<<endl;
    // while (true)
    // {
    //     removed = storage.expired();
    //     if (removed == Product())
    //     {
    //         break;
    //     } else cout<<removed<<endl;
    // } 
    while(true)
    {
    cout<<storage.expired();
    }
}

  
