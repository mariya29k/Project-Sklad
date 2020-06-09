#include <iostream>
#include "date.h"
#include "product.h"
#include "address.h"
#include <cstring>

using namespace std;
    

Product::Product ()
{
    SetName("default");
    this->expiration_date = Date();
    this->in_storage = Date();
    SetManufacturer("default");
    this->weight = 0.0;
    this->availability = 0;
    this->address = Address();
    SetComment("default");
    
    
}


Product::Product (const Product &other)
{
    SetName(other.name);
    expiration_date = other.expiration_date;
    in_storage = other.in_storage;
    SetManufacturer(other.manufacturer);
    weight = other.weight;
    availability = other.availability;
    address = other.address;
    comment = other.comment;
 
}

Product:: Product (string name_, Date expiration_, Date inStorage_, string manufacturer_, double weight_, string comment_)
{
    SetName(name_);
    SetExpiration(expiration_);
    SetinStorage(inStorage_);
    SetManufacturer(manufacturer_);
    SetWeight(weight_);
    availability = 1;
    SetComment(comment_);
    address = Address();
    

}

string Product::GetName () const
{
    return this->name;
}

void Product::SetName (const string name_) 
{
    this->name = name_;
}


void Product::SetExpiration(const Date expiration)
{   
    if(expiration.isValid())
    {
        this->expiration_date = expiration; 
    }  else cout<<"Expiration date is not valid! ";
}

Date Product::GetExpiration() const
{
    return this->expiration_date;
}

void Product::SetinStorage(const Date storage)
{  
    if(storage.isValid())
    {
        this->in_storage = storage;
    } else cout<<"Date is not valid! "<<endl;
}

Date Product::GetinStorage() const
{
    return this->in_storage;
}

string Product::GetManufacturer() const
{
    return this->manufacturer;
}

void Product::SetManufacturer (string manufacturer_)
{
    this->manufacturer = manufacturer_;
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
    if(availability_>0)
    {
        availability = availability_;
    } else cout<<"Quantity must be a positive number! "<<endl;
}

string Product::GetComment () const
{
    return this->comment;
}

void Product::SetComment (string comment_)
{
    comment = comment_;
}

bool Product::compareProduct(const Product &product)
{
    return name == product.GetName() && expiration_date == product.GetExpiration();
}

bool Product::operator== (const Product &other) const
{
    return name == other.name && expiration_date == other.expiration_date && in_storage == other.in_storage && manufacturer == other.manufacturer 
            && weight == other.weight && availability == other.availability && address == other.address && comment == other.comment;
}

bool Product::operator!=(const Product &other) const
{
    return !(this == &other);
}


bool Product::operator< (const Product &other)
{
    if (expiration_date < other.expiration_date)
    {
        return true;
    } else return false;
}



void Product::SetAddress (Address address)
{
    this->address = address;
}

Address Product::GetAddress () const
{
    return this->address;
}

ostream& operator << (ostream& out, const Product &product)
{   
    if(product != Product())
    {
        out<<"Name: "<<product.GetName()<<endl;
        out<<"Expiration date: "<<product.GetExpiration()<<endl;
        out<<"Came in storage: "<<product.GetinStorage()<<endl;
        out<<"Manufacturer: "<<product.GetManufacturer()<<endl;
        out<<"Weight: "<<product.GetWeight()<<endl;
        out<<"Availability: "<<product.GetAvailability()<<endl;
        out<<"Address: "<<product.GetAddress()<<endl;
        out<<"Comment: "<<product.GetComment()<<endl;
    }
    return out;
}

//so i can easily sort my array by the date products came in storage
bool compare (const Product &p1, const Product &p2)
{
    return compareDate(p1.GetinStorage(), p2.GetinStorage());
}
