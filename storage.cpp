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
    return i * max_shelf * max_number + j * max_number + k;  
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

void Storage::ShiftProductsRight(int index, Product product)
{
    if(index == max_size - 1)
    {
        cout<<"No more place in storage! "<<endl;
        // array[max_size-1] = Product();
        return;
    }

    int needed_slots = product.GetnSlots(product);
    for(int i = max_size - 1; i > index; --i)
    {
        array[i] = array[i-1];
        array[i].SetAddress(++array[i].GetAddress());
    }
    for (int space = 0; space < needed_slots; ++space)
    {
        array[index+space]  = product;
    }
    
}

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
                int needed_slots = product.GetnSlots(product);
                int slots = array[index].GetnSlots(array[index]);

                if(array[index].GetName() == product.GetName())
                {
                    if(array[index].GetExpiration() == product.GetExpiration())
                    {
                        if(array[index + slots] == Product())
                        {
                            if ((index + slots + needed_slots) >= max_size) 
                            {
                                cout<<"No more space left"<<endl;
                                return false;
                            }
                            else //ako v dqsno ot produkta ni e prazno da go zapishem tam
                            {
                                product.SetAddress(Address(i,j,k));
                                for (int space = 0; space < needed_slots; ++space)
                                {
                                    array[index+space]  = product;
                                }
                                return true;
                            }  
                        }
                        else //ako v dqsno ot produkta ne ni e prazno shiftvame za da go zapishem
                        {
                            ShiftProductsRight(index+slots, product);
                            product.SetAddress(Address(i,j,k)); 
                            return true;
                        } 
                    }
                    else
                    {
                        if(array[index] == Product())
                        {
                            if(index + needed_slots > max_size)
                            {
                                cout<<"The storage is full"<<endl;
                                return false;
                            }
                            else
                            {
                                for (int space = 0; space < needed_slots; ++space)
                                {
                                    array[index+space]  = product;
                                    product.SetAddress(Address(i,j,k));
                                }
                                return true;
                            }
                        } else return false;
                    }

                    array[index].SetQuantity(array[index].GetQuantity()+1); 
                    return false;  
                }

                else if(array[index] == Product())
                {
                    if(index + needed_slots > max_size)
                    {
                        cout<<"The storage is full"<<endl;
                        return false;
                    }
                    else
                    {
                        product.SetAddress(Address(i,j,k));
                        for (int space = 0; space < needed_slots; ++space)
                        {
                            array[index+space]  = product;
                        }
                        return true;
                    }
                }
                
            
            }
        }
    }
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
                if (array[index].GetName() == name)
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
    return Product();   
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
                    return product;  
                    removeProduct(array[index].GetName(), array[index].GetQuantity());
                }
            }
        }
    }
    return Product();        
}



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
                if(!(storage.array[index] == storage.product))
                {
                    output<<storage.array[index]<<endl;
                }
            }
        }
    }
    return output;      
}

    