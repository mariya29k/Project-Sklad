#include <iostream>
#include <algorithm>
#include "product.h"
#include "date.h"
#include "storage.h"

using namespace std;

Storage::Storage()
{
    for (int i = 0; i < max_section * max_shelf * max_number; ++i)
    {
        array[i] = Product();
        array[i].SetAddress(Address(max_section, max_shelf, max_number));
    }
}

int Storage::GetIndex (int i, int j, int k) const
{
    return i * max_shelf * max_number + j * max_number + k; //tova ni vrushta adresa poneje shte ni e array 
}

Product Storage::GetStorage() const
{

}

//problem in addProduct
//shifts products to the left
void Storage::ShiftProducts (int index)
{
    int max_size =  max_section * max_shelf * max_number;
    if (index == max_size - 1)
    {
        array[max_size-1] = Product();
        return;
    }


    for (int i = index + 1; i < max_size ; ++i)
    {
        array[i].SetAddress(--array[i].GetAddress());
        array[i-1] = array[i];
    }

    array[max_size -1] = Product();
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

                    product.SetAddress(Address(i,j,k)); //we give a product the address, nadpisvame
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

    //tozi cout izobshto trqbva li da bude tuk
    cout <<"No place left! beeee "<< endl;
    return false;

}

Product Storage::removeProduct(string name, double weight)
{
    for (int i = 0 ; i < max_section; ++i)
    {
        for ( int j = 0; j < max_shelf; ++j)
        {
            for (int k = 0; k < max_number; ++k)
            {
                int index = GetIndex(i,j,k);
                Product product = array[index];
                bool removed = false;
                while (array[index].GetName() == name && array[index].GetWeight() == weight) //shtoto produktite mi sa razhvurlqni
                {
                    ShiftProducts(index);
                    removed = true;
                }
                if (removed)
                {
                    return product;
                }
            }
        }
    } 
    return Product();  //ako ne nameri takuv produkt     
}


Product Storage::expired()
{
    for (int i = 0 ; i < max_section; ++i)
    {
        for ( int j = 0; j < max_shelf; ++j)
        {
            for (int k = 0; k < max_number; ++k)
            {
                Date today;
                today.today_date();
                int index = GetIndex(i,j,k);
                Product product = array[index];
                bool is_expired = false;

                if (array[index].GetExpiration().GetYear() < 0 ) continue;
                while (array[index].GetExpiration() < today) //not sure if <= is suitable 
                {                    
                    ShiftProducts(index);
                    is_expired = true;
                }
                if (is_expired)
                {
                    cout<<"Deleted product! ";
                    return product;
                } 
            }
        }

    }
    return Product();        
}

//clean vrushta samo 1viq produkt s iztekul srok i ne produljava s drugite
//sq kolichestvo, partidi tuka se oburkah jestoko
void Storage::IncreaseAvailability (Product product)
{
    for (int i = 0 ; i < max_section; ++i)
    {
        for ( int j = 0; j < max_shelf; ++j)
        {
            for (int k = 0; k < max_number; ++k)
            {
                int index = GetIndex(i,j,k);
                Product product = array[index];
                int quantity = 1;
                while (array[index].GetName() == product.GetName())
                {
                    quantity++;
                }
                product.SetAvailability(quantity);
                cout<<product.GetAvailability();
            }
        }
    }
      
}

//for log function 
void SortByDate(Storage array[], int max_size)
{
    sort(array, array+max_size, compare);
}

ostream& operator << (ostream& output, const Storage &storage)
{
    for (int i = 0 ; i < storage.max_section; ++i)
    {
        for ( int j = 0; j < storage.max_shelf; ++j)
        {
            for (int k = 0; k < storage.max_number; ++k)
            {
                int index = storage.GetIndex(i,j,k);
                output<<storage.array[index]<<endl;
            }
        }
    }
    return output;      
}

    
