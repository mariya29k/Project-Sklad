#include <iostream>
#include <vector>
#include "product.h"
#include "product.cpp"
#include "date.h"

using namespace std;

class Storage
{
    private:
    vector<Product> products;
    Date today;
    
    public:
    void addProduct(Product &product)
    {
        products.push_back(product);
    }

    void print()
    {
        products.print();
    }

    

    
};