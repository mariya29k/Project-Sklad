#include <iostream>
#include "date.h"
#include "product.h"

using namespace std;

    Product::Product ()
    {
    }

   Product:: Product (string GivenName, Date product_expiry, Date product_storage, char *product_manufacturer, double product_weight, int product_availability)
    {
        name = GivenName;
        expiration_date = product_expiry;
        in_storage = product_storage;
        manufacturer = product_manufacturer;
        weight = product_weight;
        availability = product_availability;

    }

    string Product::GetName () const //tova moje bi tr da e string
    {
        return Product::name;
    }

    void Product::SetName (char *name_) //tova sushto tr poluchava string
    {
        Product::name = name_;
    }

//how to do that thingy here
    Date Product::SetExpiration(int year, int month, int day)
    {
        
    }

    const char Product::*GetManufacturer() const
    {
        Product::return manufacturer;
    }
    
    void Product::SetManufacturer (char *manufacturer_)
    {
        Product::manufacturer = manufacturer_;
    }

    double Product::GetWeight () const
    {
        return Product::weight;
    }

    void Product::SetWeight (double weight_)
    {
        Product::weight = weight_;
    }

    int Product::GetAvailability () const
    {
        return Product::availability;
    }

    void Product::SetAvailability (int availability_)
    {
        Product::availability = availability_;
    }

    /*const char *GetComment () const //this should be a sentence or a couple of sentences maybe idk
    {
        return comment;
    } //za comment dali mi tr set ili kak da se vuvejda inache hmmm

    void deleteProduct (char* name, Date expiration_date, int id) --maybe I need an ID of a product so that I can erase it easily
    {
        if (expiration_date == today_date)
        {
            product.erase(product.begin()+id)
        }
    }*/

