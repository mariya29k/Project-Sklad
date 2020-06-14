#include <iostream>
#include "address.h"
#include "product.h"
#include "storage.h"
using namespace std;

//Storage has 5 sections, 10 shelves, 10 numbers - 1number(slot) can take up to 10kg/litres
    Address::Address ()
    {   //by default my products should be on address -1 -1 -1 because it gives me an error with shift products
        section = -1;
        shelf = -1;
        number = -1;
    }

    Address::Address (int section, int shelf, int number)
    {
        this->section = section;
        this->shelf = shelf;
        this->number = number;
    }
    
    Address::Address (const Address &other)
    {
        this->section = other.section;
        this->shelf = other.shelf;
        this->number = other.number;
    }


    bool Address::operator== (const Address &other) const
    {
        return section == other.section && shelf == other.shelf && number == other.number;
    }

    bool Address::operator!= (const Address &other) const
    {
        return !(this == &other);
    }

    ostream& operator << (ostream& output, const Address &address)
    {   
        if(address != Address())
        {
            output << address.section << "-" << address.shelf << "-" << address.number;
        }
        return output;
       
    }

    Address &Address::operator= (const Address &other)
    {
        if (this!=&other)
        {
            this->section=other.section;
            this->shelf=other.shelf;
            this->number=other.number;
        }
        
        return *this;
    }

    Address Address::operator --()
    { 

        Address address(section, shelf, number);

        if (section !=0) 
        {
            if (shelf != 0)
            {
                if (number == 0)
                {
                    shelf--;
                    number+=(Storage::max_number - 1);
                } else number--;
            } 
            else if (shelf == 0)
            {
                section--;
                shelf+=(Storage::max_shelf -1);
            } else shelf--;
        } 
        else if (section == 0) 
        {
            if (shelf == 0 && number == 0)
            {
                cout<<"No placе";
            } 
            else
            {
                if (shelf != 0)
                {
                    if (number == 0)
                    {
                        shelf--;
                        number+=(Storage::max_number - 1);
                    } else number--;
                } else number--;   
            }
            
        } 


        return address;

    }

    Address Address::operator++()
    {
        Address address(section, shelf, number);

        if (section < Storage::max_section) 
        {
            if (shelf < Storage::max_shelf)
            {
                if (number == Storage::max_number)
                {
                    shelf++;
                    number-=(Storage::max_number - 1);
                } else number++;
            } 
            else if (shelf == Storage::max_shelf)
            {
                section++;
                shelf-=(Storage::max_shelf -1);
            } else shelf++;
        } 
        else if (section == Storage::max_section) 
        {
            if (shelf == Storage::max_shelf && number == Storage::max_number)
            {
                cout<<"No place! ";
            } 
            else
            {
                if (shelf != Storage::max_shelf)
                {
                    if (number == Storage::max_number)
                    {
                        shelf++;
                        number-=(Storage::max_number - 1);
                    } else number++;
                } else number++;   
            }
            
        } 


        return address;
    }