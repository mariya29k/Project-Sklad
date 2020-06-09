#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "product.h"
#include "date.h"

using namespace std;

class Storage
{
    public:
    static const int max_section = 5;
    static const int max_shelf = 10;
    static const int max_number = 10;
    static const int slot_size = 10;
    static const int max_size = max_section * max_shelf * max_number;

    private:
    int GetIndex (int i, int j, int k) const;
    Date today;
    Product array [max_section * max_shelf * max_number];

    void ShiftProducts (int index);
    void ShiftProductsRight(int index);

    public:

    Storage();
    Product GetStorage() const;
    bool addProduct(Product &product);
    Product removeProduct(string name, double weight);
    Product expired ();
    void IncreaseAvailability(Product product);
	void SortByDate(Product storage[], int max_size);
    
    friend ostream& operator << (ostream& output, const Storage &storage);

    
};