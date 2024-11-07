#include "Product.h"
#include <iostream>
#include <fstream>

// Implement display function for Product
void Product::display() const {
    std::cout << "ID: " << productID << ", Name: " << name << ", Price: $" << price << "\n";
}

// Implement loadProducts to read from a file
std::vector<Product> loadProducts() {
    std::vector<Product> products;
    std::ifstream file("products.txt");
    std::string id, name;
    double price;
    while (file >> id >> name >> price) {
        products.push_back(Product(id, name, price));
    }
    return products;
}
