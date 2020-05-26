#include <iostream>
#include <fstream>
#include <string>
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
    } else StorageFile.open("storage.txt"); //("", ios::app/ios::out)?

    //then we check for errors
    if (StorageFile.fail())
    {
        cout<<"Error opening file! ";
        exit(1); //we close the program 
    }

    int x,y;
    StorageFile>>x>>y;
    cout<<"num1 : "<< x<< "num 2: "<<y;
}

//void Close () - moje bi prosto shte go sloja v if-a s komandite?



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

    void remove()
    {
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

    /*void clean (Product &product) //ama tva trie samo edin produkt mai mai, shtoto tr da izvurti vs produkti v sklada i za vseki da proveri
    {
        Date today;
        if(product.GetExpiration()==today.today_date())
        {
            products.erase(products.begin()+product.GetID());
        }
    }*/

  
