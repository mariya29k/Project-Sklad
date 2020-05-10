#pragma once

#include <iostream>
#include "date.h"
#include <string>
using namespace std;

class Product
{
    private:
    string name;
    Date expiration_date;
    Date in_storage;
    char *manufacturer;
    double weight;
    int availability;

    public:
    
    Product ();
    Product (string name, char *product_manufacturer, double product_weight, int product_availability);
    void  GetName () const;
    void SetName (string name_);
    const char *GetManufacturer() const;
    void SetManufacturer (char *manufacturer_);
    double GetWeight () const;
    void SetWeight (double weight_);
    int GetAvailability () const;
    void SetAvailability (int availability_);
    void print();
};