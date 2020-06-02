#include <iostream>
#include <fstream>
#include "string.h"
#include "product.h"
#include "date.h"
#include "storage.h"


using namespace std;

Storage storage;


void Open ()
{//ofstream???
    
    ifstream StorageFile;
    //first we check whether the file is already opened
    if(StorageFile.is_open())
    {
        cout<<"File is already opened! ";
    } else StorageFile.open("storage.txt", ios::in); //("", ios::app/ios::out)?

    //then we check for errors
    if (StorageFile.fail())
    {
        cout<<"Error opening file! ";
        exit(1); //we close the program exit(0) - successfully executed, exit(1) - closed because of fail
    }

    
}

void Close()
{
    //StorageFile.close();
}

void Save ()
{
    ofstream StorageFile;
    if (StorageFile.is_open())
    {
        StorageFile.open("storage.txt", ios::trunc);
        StorageFile << storage;
    } else StorageFile.open("storage.txt", ios::out);

    if (StorageFile.fail())
    {
        cout<< "Error opening file! ";
        exit(1);
    } else StorageFile << storage;

}

void SaveAs ()
{
    ofstream NewStorageFile;
    
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
    
    NewStorageFile << storage;
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

void add ()
{   //ako si pravq produkta kato vektor s push_back shte stane
    string name; //ili * ili []
    Date expiration;
    Date in_storage;
    string manufacturer;
    double weight;
    string comment;

    cout<<"You are adding a new product to storage! "<<endl;
    cout<<"Add the name of the product: "<<endl; //no space people!!
    cin>>name;
    cout<<"\n Enter the expiration date of the product: "<<endl;
    cin>>expiration;
    cout<<"\n Enter the date when the product came in: "<<endl;
    cin>>in_storage;
    cout<<"\n Enter the name of the manufacturer: "<<endl; //sloji da ne slagat space
    cin>>manufacturer;
    cout<<"\n Enter weight: "<<endl;
    cin>>weight;
    cout<<"\n Enter a comment about the product: "<<endl;
    cin.get();
    getline(cin,comment);
    cout<<endl;

    Product current = Product(name, expiration, in_storage, manufacturer, weight, comment);
    storage.addProduct(current);
    cout<<current<<endl;
}


void print()
{
    cout<<storage;
}


void remove()
{//tuk trqbva da poluchava availability, a ne weight ppc
    string name;
    double weight;
    //int quantity;
    cout<<"You are removing a product from storage!"<<endl;
    cout<<"Enter the name of the product you want removed: "<<endl;
    cin>>name;
    cout<<"Enter the quantity you want removed: "<<endl;
    cin>>weight;
    cout<<storage.removeProduct(name, weight);
}

void log()
{
    Date from;
    Date to;
    cout<<"Enter date from which you want to see information: "<<endl;
    cin>>from;
    cout<<"Enter date up to which you want to see information: "<<endl;
    cin>>to;
    storage.SortByDate(storage, storage.max_size);
    

}

void clean()
{
    Product removed;
    cout<<"Expired products! "<<endl;
    while (true)
    {
        removed = storage.expired();
        if (removed == Product())
        {
            break;
        } else cout<<removed<<endl;
    } 
}

  
