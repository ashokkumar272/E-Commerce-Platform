#include "Order.h"
#include <fstream>
#include <iostream>

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

    std::ofstream file("orders.txt", std::ios::app);
    file << user.getUserID() << " " << product.productID << " " << quantity << " " << newOrder.totalPrice << "\n";
    std::cout << "Order placed successfully!\n";
}

void Order::showOrderHistory(const std::string& userID) {
    std::ifstream file("orders.txt");
    std::string uid, pid;
    int quantity;
    double total;
    bool found = false;

    while (file >> uid >> pid >> quantity >> total) {
        if (uid == userID) {
            std::cout << "Product ID: " << pid << ", Quantity: " << quantity << ", Total: $" << total << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No order history found.\n";
    }
}
