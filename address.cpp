#include <iostream>
#include "address.h"
#include "product.h"
#include "storage.h"
using namespace std;

//Storage has 26 sections, 200 shelves, 300 numbers - 1number can take up to 10kg/litres
    Address::Address ()
    {
        section = 0;
        shelf = 0;
        number = 0;
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


    bool Address::operator== (const Address &other)
    {
        return section == other.section && shelf == other.shelf && number == other.number;
    }

    ostream& operator << (ostream& output, const Address &address)
    {   
        output << address.section << "-" << address.shelf << "-" << address.number;
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

        Address& Address::operator --()
        { 
            if(number == (Storage::max_number - 1) )
            {
                if (shelf == (Storage::max_shelf - 1))
                {
                    if (section == (Storage::max_section -1))
                    {
                        //ako sme na 25 section 1 shelf 1 number
                        //otivamena 24 stilaj 299 shelf 199 number
                        //no tuk mai bi trqbvalo da se poqvi problem
                        //s tova kolko slots zaema nashiq produkt
                        
                    }
                }
            }
            return *this;
        }