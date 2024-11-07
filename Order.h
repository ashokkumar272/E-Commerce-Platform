#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <unordered_set>
#include "Product.h"
#include "User.h"

class Order {
public:
    std::string orderID;
    std::string userID;
    std::vector<std::pair<Product, int>> products;
    double totalPrice;

    Order(const std::string& oid, const std::string& uid, const Product& product, int qty);
    void addProduct(const Product& product, int quantity);
    void calculateTotal();
    void displayOrder() const;

    static void placeOrder(const User& user, const Product& product, int quantity);
    static void showOrderHistory(const std::string& userID);
    static void recommendProducts(const std::string& userID, const std::vector<Product>& allProducts);
};

#endif
