#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

class Product {
public:
    std::string productID;
    std::string name;
    double price;

    Product(std::string id, std::string n, double p) : productID(id), name(n), price(p) {}
    void display() const;
};

// Declare the loadProducts function to be defined in Product.cpp
std::vector<Product> loadProducts();

#endif
