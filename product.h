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
    int quantity;
    Address address;
    string comment;
    static const int slot_size = 10;


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
    int GetQuantity () const;
    void SetQuantity (int quantity_);
    string GetComment() const;
    void SetComment(string comment_);
    int GetID () const;
    void SetAddress (Address address);
    Address GetAddress () const;
    int GetnSlots (const Product &product) const;
    bool compareProduct(const Product &product);
    bool operator== (const Product &product) const;
    bool operator!=(const Product &other) const; //if there is no const gives me errors pls send help
    bool operator< (const Product &product);
    friend ostream& operator << (ostream& out, const Product &product);
};
    bool compare (const Product &p1, const Product &p2);
