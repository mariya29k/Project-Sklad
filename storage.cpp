#include <iostream>
#include <vector>
#include <cmath>
#include "product.h"
#include "product.cpp"
#include "date.h"

using namespace std;
const int max_section = 26;
const int max_shelf = 200;
const int max_number = 300;
const int slot_size = 10;

class Storage
{
    private:
    vector<Product> products;
    Date today;
    Product array [max_section * max_shelf * max_number];
    //i*26,j*200,k*300

    int GetIndex (int i, int j, int k)
    {
        return i * max_section + j * max_shelf + k * max_number; //tova ni vrushta adresa poneje shte ni e array 
    }
    
    public:

//this function adds a product to a given address
    bool addProduct(Product &product)
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
                        int needed_slots = ceil(weight) / slot_size; //2,6 go pravim na 3, za da izpolzvame enough space
                        

                        if ((index + needed_slots) >= (max_section * max_shelf * max_number))
                        {
                            cout <<"No place left! "<< endl;
                            return false;
                        }

                        product.setAddress(Address(i,j,k));

                        for (int slot = 0; slot < needed_slots; slot++)
                        {
                            array[index+slot]  = product; //sig sme che v dqsno ot produkta e prazno

                        }
                    }
                }
            }
        }

        cout <<"No place left! "<< endl;
        return false;

    }

    
    

    
};