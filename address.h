#pragma once
#include <iostream>

using namespace std;

class Address 
{
    private :
    char section;
    int raft;
    int number;

    public :
    Address ();
    Address (char section, int raft, int number);
    Address &operator= (const Address &other);
    void SetSection (char section_);
    char GetSection () const;
    void SetRaft (const int &raft_);
    int GetRaft () const;
    void SetNumber (const int &number_);
    int GetNumber () const;
    void setaddress (const Product& product);
};