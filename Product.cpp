#include "Product.h"
#include <iostream>
#include <fstream>

// Display function for Product
void Product::display() const {
    std::cout << "ID: " << productID << ", Name: " << name << ", Category: " << category 
              << ", Price: $" << price << "\n";
}

// loadProducts implementation: reads from a file and includes categories
std::vector<Product> loadProducts() {
    std::vector<Product> products;
    std::ifstream file("products.txt");
    std::string id, name, category;
    double price;
    while (file >> id >> name >> category >> price) {
        products.push_back(Product(id, name, category, price));
    }
    return products;
}

