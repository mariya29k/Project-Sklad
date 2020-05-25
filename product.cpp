#include <iostream>
#include "date.h"
#include "date.cpp"
#include "product.h"
#include "address.h"
#include "address.cpp"
#include <cstring>

using namespace std;
    
    //int Product:: product_id =1000;

    Product::Product ()
    {
        SetName("default");
        this->expiration_date = Date();
        this->in_storage = Date();
        SetManufacturer("default");
        this->weight = 0.0;
        this->availability = 0.0;
        this->address = Address();
        SetComment("default");
        //this->id = product_id++;
        
    }


    Product:: Product (const Product &other)
    {
        SetName(other.name);
        expiration_date = other.expiration_date;
        in_storage = other.in_storage;
        SetManufacturer(other.manufacturer);
        weight = other.weight;
        availability = other.availability;
        address = other.address;
        comment = other.comment;
        //id = other.id;
    }

    Product:: Product (char *name_, Date expiration_, Date inStorage_, char* manufacturer_, double weight_, string comment_)
    {
        name = name_;
        expiration_date = expiration_;
        in_storage = inStorage_;
        manufacturer = manufacturer_;
        weight = weight_;
        availability = 1;
        comment = comment_;
        address = Address();
        

    }



    const char* Product::GetName () const //tova moje bi tr da e string
    {
        return this->name;
    }

    void Product::SetName (const char* name_) 
    {
        this->name=new char[strlen(name_)+1]; //tuk moje bi ne tr ima_
        strcpy(this->name, name_);
    }

//how to do that thingy here
    void Product::SetExpiration()//tuk tr proverq dali datata, koqto setvame e validna, no nz kak, sushtoto i za instorage mai tr pri samiq  operator>> na dates
    {   
        cin>>expiration_date;
    }

    Date Product::GetExpiration() const
    {
        return this->expiration_date;
    }

    void Product::SetinStorage()
    {  
        cin>>in_storage;
    }

    Date Product::GetinStorage() const
    {
        return this->in_storage;
    }

    const char* Product::GetManufacturer() const
    {
        return this->manufacturer;
    }
    
    void Product::SetManufacturer (const char* manufacturer_)
    {
        this->manufacturer=new char[strlen(manufacturer_)+1]; //tuk moje bi ne tr ima_
        strcpy(this->manufacturer, manufacturer_);
    }

    double Product::GetWeight () const
    {   
        return this->weight;
    }

    void Product::SetWeight (double weight_)
    {   if(weight_> 0.0) {
        weight = weight_;
        } else cout<< "weight must be positive";
    }

    int Product::GetAvailability () const
    {
        return this->availability;
    }

    void Product::SetAvailability (int availability_)
    {
        availability = availability_;
    }

    string Product::GetComment () const
    {
        return this->comment;
    }

    void Product::SetComment (string comment_)
    {
        comment = comment_;
    }

    // int Product::GetID () const
    // {
    //     return this->id;
    // }

    // void Product::print()
    // {
    //     cout<<product.GetName()
    // }

    bool Product::operator== (const Product &other)
    {
        return name == other.name && expiration_date == other.expiration_date && in_storage == other.in_storage && manufacturer == other.manufacturer 
                && weight == other.weight && availability == other.availability && address == other.address && comment == other.comment;
    }

    void Product::setAddress (Address address)
    {
        this->address = address;
    }
    
    Address Product::getAddress () const
    {
        return this->address;
    }

