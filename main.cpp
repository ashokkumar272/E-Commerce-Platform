#include "User.h"
#include "Product.h"
#include "Order.h"
#include <iostream>
#include <vector>

int main() {
    // Load all products
    std::vector<Product> products = loadProducts();

    User currentUser;

    // User login and menu
    bool isLoggedIn = currentUser.login();
    if (isLoggedIn) {
        bool running = true;
        while (running) {
            std::cout << "\nMenu:\n";
            std::cout << "1. Browse Products\n";
            std::cout << "2. Show Order History\n";
            std::cout << "3. Show Recommendations\n";
            std::cout << "4. Place Order\n";
            std::cout << "5. Exit\n";
            std::cout << "Select an option: ";
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Available products:\n";
                    for (const auto& product : products) {
                        product.display();
                    }
                    break;

                case 2:
                    Order::showOrderHistory(currentUser.getUserID());
                    break;

                case 3:
                    Order::recommendProducts(currentUser.getUserID(), products);
                    break;

                case 4: {
                    std::string productId;
                    int quantity;
                    std::cout << "Enter product ID: ";
                    std::cin >> productId;
                    std::cout << "Enter quantity: ";
                    std::cin >> quantity;
                    bool found = false;
                    for (const auto& product : products) {
                        if (product.productID == productId) {
                            Order::placeOrder(currentUser, product, quantity);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        std::cout << "Product not found!\n";
                    }
                    break;
                }

                case 5:
                    running = false;
                    break;

                default:
                    std::cout << "Invalid choice, try again.\n";
                    break;
            }
        }
    } else {
        std::cout << "Login failed.\n";
    }

    return 0;
}
