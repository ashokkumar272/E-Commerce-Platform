#include <iostream>
#include <vector>
#include "User.h"
#include "Product.h"
#include "Order.h"

void displayProducts(const std::vector<Product>& products) {
    for (const auto& product : products) {
        product.display();
    }
}

void showRecommendations(const std::string& userID) {
    std::cout << "Recommended products based on past orders:\n";
    // For simplicity, show all products (in a real system, recommendations would be filtered)
    displayProducts(loadProducts());
}

int main() {
    User user;
    std::string username, password;
    int choice;
    
    // Authentication Menu
    std::cout << "1. Login\n2. Sign Up\nChoose an option: ";
    std::cin >> choice;

    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;

    if (choice == 1) {
        if (!user.login(username, password)) {
            std::cout << "Invalid credentials. Exiting...\n";
            return 1;
        }
    } else if (choice == 2) {
        user.signUp(username, password);
        std::cout << "User registered successfully. Please log in.\n";
        return 0;
    }

    // Main Menu
    std::vector<Product> products = loadProducts();
    do {
        std::cout << "\n1. Browse Products\n2. Show Order History\n3. Show Recommendations\n4. Place Order\n5. Exit\nChoose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            displayProducts(products);
        } else if (choice == 2) {
            Order::showOrderHistory(user.getUserID());
        } else if (choice == 3) {
            showRecommendations(user.getUserID());
        } else if (choice == 4) {
            std::string productID;
            int quantity;
            std::cout << "Enter Product ID: ";
            std::cin >> productID;
            std::cout << "Enter Quantity: ";
            std::cin >> quantity;

            for (const auto& product : products) {
                if (product.productID == productID) {
                    Order::placeOrder(user, product, quantity);
                    break;
                }
            }
        }
    } while (choice != 5);

    std::cout << "Thank you for using the platform.\n";
    return 0;
}
