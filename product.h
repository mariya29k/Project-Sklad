#pragma once

#include <iostream>
#include "date.h"
#include "address.h"
#include <string>
using namespace std;

class Product
{
    private:
    char* name;
    Date expiration_date;
    Date in_storage;
    char* manufacturer;
    double weight;
    int availability;
    Address address;
    string comment;
    
    int id;
    static int product_id;

    public:
    
    Product ();
    Product (const Product &other);
    Product (char *name_, Date expiration_, Date inStorage_, char* manufacturer_, double weight_, string comment_);
    const char* GetName () const;
    void SetName (const char* name_);
    void SetExpiration();
    Date GetExpiration() const;
    void SetinStorage();
    Date GetinStorage() const;
    const char* GetManufacturer() const;
    void SetManufacturer (const char* manufacturer_);
    double GetWeight () const;
    void SetWeight (double weight_);
    int GetAvailability () const;
    void SetAvailability (int availability_);
    string GetComment();
    void SetComment(string comment_);
    int GetID () const;
    void print();
};