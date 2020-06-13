#include <iostream>
#include "date.h"
#include "product.h"
#include "address.h"
#include <cstring>
#include <cmath>

using namespace std;
    

Product::Product ()
{
    SetName("default");
    this->expiration_date = Date();
    this->in_storage = Date();
    SetManufacturer("default");
    this->weight = 0.0;
    this->quantity = 0;
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
    quantity = other.quantity;
    address = other.address;
    comment = other.comment;
 
}

Product:: Product (string name_, Date expiration_, Date inStorage_, string manufacturer_, double weight_, string comment_)
{
    this->name=name_;
    this->expiration_date=expiration_;
    this->in_storage=inStorage_;
    this->manufacturer=manufacturer_;
    this->weight=weight_;
    this->comment = comment_;
    this->quantity = 1;
    this->address = Address();
   
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

int Product::GetQuantity () const
{
    return this->quantity;
}

void Product::SetQuantity (int quantity_)
{
    if(quantity_>0)
    {
        quantity = quantity_;
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
            && weight == other.weight && quantity == other.quantity && address == other.address && comment == other.comment;
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

int Product::GetnSlots(const Product &product) const
{
    double weight = product.GetWeight();
    int needed_slots = ceil(weight / slot_size);
    return needed_slots;
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
        out<<"Availability: "<<product.GetQuantity()<<endl;
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
