#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "product.h"
#include "date.h"

using namespace std;

class Storage
{
    private:
    static const int max_section = 26;
    static const int max_shelf = 200;
    static const int max_number = 300;
    static const int slot_size = 10;

    vector<Product> products;
    Date today;
    Product array [max_section * max_shelf * max_number];

    int GetIndex (int i, int j, int k);
    void ShiftProducts (int index);

    public:
    Storage();
    bool addProduct(Product &product);
    Product removeProduct(string name, double weight);
    void expired ();
    

    
};