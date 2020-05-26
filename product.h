#pragma once

#include <iostream>
#include "date.h"
#include "address.h"
#include <string>
using namespace std;

class Product
{
    private:
    string name;
    Date expiration_date;
    Date in_storage;
    string manufacturer;
    double weight;
    int availability;
    Address address;
    string comment;
    
    //int id;
    //static int product_id;

    public:
    
    Product ();
    Product (const Product &other);
    Product (string name_, Date expiration_, Date inStorage_, string manufacturer_, double weight_, string comment_);
    string GetName () const;
    void SetName (string name_);
    void SetExpiration(const Date expiration);
    Date GetExpiration() const;
    void SetinStorage(const Date storage);
    Date GetinStorage() const;
    string GetManufacturer() const;
    void SetManufacturer (string manufacturer_);
    double GetWeight () const;
    void SetWeight (double weight_);
    int GetAvailability () const;
    void SetAvailability (int availability_);
    string GetComment() const;
    void SetComment(string comment_);
    int GetID () const;
    void print();
    void SetAddress (Address address);
    Address GetAddress () const;
    bool operator== (const Product &product);
    friend ostream& operator << (ostream& output, const Product &product);
};
