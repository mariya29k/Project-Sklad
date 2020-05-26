#include <iostream>
#include <vector>
#include <cmath>
#include "product.h"
#include "date.h"
#include "storage.h"

using namespace std;


Storage::Storage()
{
    for (int i = 0; i < max_section * max_shelf * max_number; ++i)
    {
        array[i] = Product();
    }
}

int Storage::GetIndex (int i, int j, int k)
{
    return i * max_shelf * max_number + j * max_number + k; //tova ni vrushta adresa poneje shte ni e array 
}


//this function adds a product to a given address
bool Storage::addProduct(Product &product)
{
    for (int i = 0 ; i < max_section; ++i)
    {
        for ( int j = 0; j < max_shelf; ++j)
        {
            for (int k = 0; k < max_number; ++k)
            {
                int index = GetIndex(i,j,k);
                if (array[index] == Product())
                {   
                    double weight = product.GetWeight();
                    int needed_slots = ceil(weight / slot_size); //2,6 go pravim na 3, za da izpolzvame enough space
                    //cout<<needed_slots<<endl;

                    if ((index + needed_slots) >= (max_section * max_shelf * max_number))
                    {
                        cout <<"No place left! "<< endl;
                        return false;
                    }

                    product.SetAddress(Address(i,j,k));

                    for (int slot = 0; slot < needed_slots; slot++)
                    {
                        //cout<<"kaji mi kolko davash "<< index+slot<<endl;
                        array[index+slot]  = product; //sig sme che v dqsno ot produkta e prazno

                    }

                    return true;
                }
            }
        }
    }

    cout <<"No place left! "<< endl;
    return false;

}

void Storage::expired ()  {}


    
