#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

class Product {
public:
    std::string productID;
    std::string name;
    std::string category; // Category field added
    double price;

    Product(std::string id, std::string n, std::string cat, double p) 
        : productID(id), name(n), category(cat), price(p) {}

    void display() const;
};

// Declaration of loadProducts to be defined in Product.cpp
std::vector<Product> loadProducts();

#endif
