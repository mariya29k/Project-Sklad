#include <iostream>
#include "address.h"
#include "product.h"
using namespace std;

//Storage has 26 sections, 200 shelves, 300 numbers - 1number can take up to 10kg/litres
    Address::Address ()
    {
        section = 0;
        shelf = 0;
        number = 0;
    }

    Address::Address (int section, int raft, int number)
    {
        this->section = section;
        this->shelf = shelf;
        this->number = number;
    }
    
    //kopikonstruktor

    bool Address::operator== (const Address &other)
    {
        return section == other.section && shelf == other.shelf && number == other.number;
    }

    ostream& operator << (ostream& output, const Address &address)
    {   
        output << address.section << "-" << address.shelf << "-" << address.number;
        return output;
       
    }



    // Address &Address::operator= (const Address &other)
    // {
    //     if (this!=&other)
    //     {
    //         this->section=other.section;
    //         this->raft=other.raft;
    //         this->number=other.number;
    //     }
        
    //     return *this;
    // }
