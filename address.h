#pragma once
#include <iostream>

using namespace std;

class Address 
{
    private :
    int section;
    int shelf;
    int number;

    public :
    Address ();
    Address (int section, int shelf, int number);
    Address (const Address &other);
    Address GetAddress() const;
    bool operator== (const Address &other) const;
    bool operator!= (const Address &other) const;
    friend ostream& operator << (ostream& output, const Address &address);
    Address &operator= (const Address &other);
    Address operator--();
    Address operator++();
  
};