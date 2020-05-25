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
    bool operator== (const Address &other);
    friend ostream& operator << (ostream& output, const Address &address);
    //Address &operator= (const Address &other);
    //void SetSection (char section_);
    // char GetSection () const;
    // void SetShelf (const int &shelf_);
    // int GetShelf () const;
    // void SetNumber (const int &number_);
    // int GetNumber () const;
    //void setAddress (const Product& product);
};