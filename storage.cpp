#include <iostream>
#include <algorithm>
#include "product.h"
#include "date.h"
#include "storage.h"

using namespace std;

Storage::Storage()
{
    for (int i = 0; i <max_size; ++i)
    {
        array[i] = Product();
        array[i].SetAddress(Address());
    }
}

int Storage::GetIndex (int i, int j, int k) const
{
    return i * max_shelf * max_number + j * max_number + k; //tova ni vrushta adresa poneje shte ni e array 
}

int Storage::GetSlots() const
{
    for (int i = 0 ; i < max_section; ++i)
    {   
        for ( int j = 0; j < max_shelf; ++j)
        { 
            for (int k = 0; k < max_number; ++k)
            {   
                int index = GetIndex(i,j,k);
                double weight = array[index].GetWeight();
                int needed_slots = ceil(weight / slot_size); //2,6 go pravim na 3, za da izpolzvame enough space
                //cout<<needed_slots<<endl;
                return needed_slots;
            }
        } 
    }   
}



//problem in addProduct
//shifts products to the left
void Storage::ShiftProducts (int index)
{
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

void Storage::ShiftProductsRight(int index)
{
    if(index == max_size - 1)
    {
        cout<<"No more place in storage! "<<endl;
        // array[max_size-1] = Product();
        return;
    }

    Product temp;
    for (int i = index + 1; i < max_size-1; ++i)    
    {
        array[i].SetAddress(++array[i].GetAddress());
        temp = array[max_size-1];
        array[max_size-1] = array[i];
        array[i] = temp;
    }
    
}


// //this function adds a product to a free address
// bool Storage::addProduct(Product &product)
// {
//     for (int i = 0 ; i < max_section; ++i)
//     {   
//         for ( int j = 0; j < max_shelf; ++j)
//         { 
//             for (int k = 0; k < max_number; ++k)
//             {   
//                 int index = GetIndex(i,j,k);
//                 if (array[index].GetName() == product.GetName()) 
//                 {
//                     if (array[index].GetExpiration() == product.GetExpiration()) //if products have the same expiration date they should be on the same spot
//                     {
//                         addSame(product);
//                     } 
//                     else // if products have different expiration dates
//                     {

//                         add(product);
//                     }
//                 } else add(product);
//             }
//         }
//     }

//    // cout <<"No place left!"<< endl;
//     return false;
// }

// //this function adds a product to a free address
// bool Storage::add(Product &product)
// {
//     for (int i = 0 ; i < max_section; ++i)
//     {   
//         for ( int j = 0; j < max_shelf; ++j)
//         { 
//             for (int k = 0; k < max_number; ++k)
//             {   
//                 int index = GetIndex(i,j,k);
//                 if (array[index] == Product())
//                 {   
//                     int needed_slots = product.GetnSlots(product);

//                     if ((index + needed_slots) >= (max_section * max_shelf * max_number)) //this is needed so that we know if we have place
//                     {
//                        // cout <<"No place!!! left! "<< endl;
//                         return false;
//                     }

//                     product.SetAddress(Address(i,j,k)); //we give a product the address, nadpisvame
//                     for (int slot = 0; slot < needed_slots; slot++)
//                     {
//                         //cout<<"kaji mi kolko davash "<< index+slot<<endl;
//                         array[index+slot]  = product; //sig sme che v dqsno ot produkta e prazno

//                     }
//                     return true;
//                 }
//             }
//         }
//     }

//     //cout <<"No place left!"<< endl;
//     return false;
// }

// bool Storage::addSame(Product &product)
// {
//      for (int i = 0 ; i < max_section; ++i)
//     {   
//         for ( int j = 0; j < max_shelf; ++j)
//         { 
//             for (int k = 0; k < max_number; ++k)
//             {   
//                 int index = GetIndex(i,j,k);
//                 int needed_slots = product.GetnSlots(product);
//                 if (array[index + GetSlots()] == Product()) //if there is space right from our product we add the new one
//                         {   
//                             if ((index + GetSlots() + needed_slots) >= (max_section * max_shelf * max_number))
//                             {
//                                // cout <<"No place left!"<< endl;
//                                 return false;
//                             }
//                             else
//                             {
//                                 product.SetAddress(Address(i,j,k)); //we give a product the address, nadpisvame
//                                 for (int slot = 0; slot < needed_slots; slot++)
//                                 {
//                                     //cout<<"how much space left: "<< index+slot<<endl;
//                                     array[index+slot]  = product; //we are sure that there is space right from our product

//                                 }
//                             return true;
//                             }
//                         }
//                         else //if there is a product where we want to put the new product we shift them
//                         {
//                             ShiftProductsRight(index + needed_slots);
//                             product.SetAddress(Address(i,j,k)); //we give a product the address, nadpisvame
//                             for (int slot = 0; slot < needed_slots; slot++)
//                             {
//                                 array[index+slot]  = product; //we are sure that there is space right from our product
//                             }
//                             return true;
//                         }
//             }
//         }
//     }

//     //cout <<"No place left!"<< endl;
//     return false;
// }

//this function adds a product to a free address
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
                        cout <<"No place left!"<< endl;
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

    cout <<"No place left! "<< endl;
    return false;
}


Product Storage::removeProduct(string name, int quantity)
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
                if (array[index].GetName() == name) //shtoto produktite mi sa razhvurlqni
                {
                    
                    if(array[index].GetQuantity() >= quantity)
                    {
                        ShiftProducts(index);
                        removed = true;
                    } 
                    else
                    {
                        cout<<"Do you still want remove whatever is left?"<<endl;
                        char answer;
                        cin>>answer;
                        if(answer == 'Y' || answer == 'y')
                        {
                            ShiftProducts(index);
                            removed = true;
                        }
                    }
                    
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
                bool is_expired = false;
                Product product = array[index];

                if (array[index].GetExpiration().GetYear() < 0 ) continue;
                if (array[index].GetExpiration() < today)
                {
                    removeProduct(array[index].GetName(), array[index].GetQuantity());  
                }
            }
        }
    }
    return Product();        
}

//clean vrushta samo 1viq produkt s iztekul srok i ne produljava s drugite

//for log function 
void Storage::SortByDate(Storage storage) //sorts them by the date they came in storage
{
    sort(storage.array, storage.array+max_size, compare);
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
                if(!(storage.array[index] == storage.product)) //shtoto ne iskam da mi cout-va praznite produkti ama neshto ne se poluchava
                {
                    output<<storage.array[index]<<endl;
                }
            }
        }
    }
    return output;      
}

    
// //sq kolichestvo, partidi tuka se oburkah jestoko
// void Storage::IncreaseAvailability (Product product)
// {
//     for (int i = 0 ; i < max_section; ++i)
//     {
//         for ( int j = 0; j < max_shelf; ++j)
//         {
//             for (int k = 0; k < max_number; ++k)
//             {
//                 int index = GetIndex(i,j,k);
//                 Product product = array[index];
//                 int quantity = 0;
//                 while (array[index].GetName() == product.GetName())
//                 {
//                     quantity += array[index].GetQuantity();
//                 }
//                 product.SetQuantity(quantity);
//                 cout<<product.GetQuantity();
//             }
//         }
//     }
      
// }
