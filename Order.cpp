#include "Order.h"
#include <fstream>
#include <iostream>
#include <unordered_set>

// Constructor that initializes order details
Order::Order(const std::string& oid, const std::string& uid, const Product& product, int qty)
    : orderID(oid), userID(uid), totalPrice(0.0) {
    addProduct(product, qty);
}

void Order::addProduct(const Product& product, int quantity) {
    products.push_back({product, quantity});
}

void Order::calculateTotal() {
    totalPrice = 0.0;
    for (const auto& p : products) {
        totalPrice += p.first.price * p.second;
    }
}

void Order::displayOrder() const {
    std::cout << "Order ID: " << orderID << "\n";
    std::cout << "User ID: " << userID << "\n";
    for (const auto& p : products) {
        std::cout << "Product: " << p.first.name << ", Quantity: " << p.second
                  << ", Price: $" << p.first.price * p.second << "\n";
    }
    std::cout << "Total Price: $" << totalPrice << "\n";
}

void Order::placeOrder(const User& user, const Product& product, int quantity) {
    static int orderCount = 1;
    std::string orderID = "ORD" + std::to_string(orderCount++);
    Order newOrder(orderID, user.getUserID(), product, quantity);
    newOrder.calculateTotal();

    // Save order details including category to orders.txt
    std::ofstream file("orders.txt", std::ios::app);
    file << user.getUserID() << " " << product.productID << " " << product.category 
         << " " << quantity << " " << newOrder.totalPrice << "\n";
    std::cout << "Order placed successfully!\n";
}

void Order::showOrderHistory(const std::string& userID) {
    std::ifstream file("orders.txt");
    std::string uid, pid, category;
    int quantity;
    double total;
    bool found = false;

    while (file >> uid >> pid >> category >> quantity >> total) {
        if (uid == userID) {
            std::cout << "Product ID: " << pid << ", Category: " << category 
                      << ", Quantity: " << quantity << ", Total: $" << total << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No order history found.\n";
    }
}

void Order::recommendProducts(const std::string& userID, const std::vector<Product>& allProducts) {
    // Step 1: Extract unique categories from user's order history
    std::ifstream file("orders.txt");
    std::string uid, pid, category;
    int quantity;
    double total;
    std::unordered_set<std::string> orderedCategories;

    while (file >> uid >> pid >> category >> quantity >> total) {
        if (uid == userID) {
            orderedCategories.insert(category);
        }
    }

    if (orderedCategories.empty()) {
        std::cout << "No recommendations available.\n";
        return;
    }

    // Step 2: Recommend products from the ordered categories
    std::cout << "Recommended products:\n";
    for (const auto& product : allProducts) {
        if (orderedCategories.count(product.category)) {
            product.display();
        }
    }
}
