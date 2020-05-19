#include <iostream>
#include "address.h"
#include "product.h"
using namespace std;

    Address::Address ()
    {
        SetSection('A');
        SetRaft(0);
        SetNumber(0);
    }

    Address::Address (char section, int raft, int number)
    {
        SetSection(section);
        SetRaft(raft);
        SetNumber(number);
    }

    Address &Address::operator= (const Address &other)
    {
        if (this!=&other)
        {
            this->section=other.section;
            this->raft=other.raft;
            this->number=other.number;
        }
        
        return *this;
    }

    void Address::SetSection (char section_)
    {
        if(section_ < 'A' || section_ > 'Z')
        {
            cout<<"Section must be an upper letter!";
        }
        else this->section=section_;
    }

    char Address::GetSection () const
    {
        return this->section;
    }

    void Address::SetRaft (const int &raft_)
    {
        if(raft_ < 1 || raft > 200)
        {
            cout<< "No place left in storage";
        }
            else raft = raft_;
    }

    int Address::GetRaft () const
    {
        return this->raft;
    }

    void Address::SetNumber (const int &number_)
    {
        if (number_ < 1 || number_ > 300)
        {
            cout<< "No place left in storage";
        }
            else number = number_;
    }

    int Address::GetNumber () const
    {
        return this->number;
    }

    
    void Address::setaddress (const Product& product)
    {
        for (char a = 'A'; a <= 'Z'; ++a)
        {
            for (int i = 1; i<=200; i++) 
            {
                for (int j = 1;)
            }
        }
    }