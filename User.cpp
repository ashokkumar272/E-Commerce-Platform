#include "User.h"
#include <iostream>
#include <fstream>

// Helper function to check if the credentials are valid
bool User::validateCredentials(const std::string& id, const std::string& pass) {
    std::ifstream file("users.txt");
    std::string uid, pwd, uname;
    while (file >> uid >> pwd >> uname) {
        if (uid == id && pwd == pass) {
            return true;
        }
    }
    return false;
}

// Helper function to register a new user
bool User::registerUser(const std::string& id, const std::string& pass, const std::string& name) {
    // Check if user already exists
    std::ifstream file("users.txt");
    std::string uid, pwd, uname;
    while (file >> uid >> pwd >> uname) {
        if (uid == id) {
            std::cout << "User ID already exists. Please try logging in.\n";
            return false;
        }
    }

    // If user doesn't exist, register the user
    std::ofstream outfile("users.txt", std::ios::app);
    outfile << id << " " << pass << " " << name << "\n";
    std::cout << "User registered successfully!\n";
    return true;
}

// Implementation of login function
bool User::login() {
    std::cout << "Enter User ID: ";
    std::string id;
    std::cin >> id;

    std::cout << "Enter Password: ";
    std::string pass;
    std::cin >> pass;

    if (validateCredentials(id, pass)) {
        userID = id;
        password = pass;
        std::cout << "Login successful!\n";
        return true;
    }

    std::cout << "User ID not found or password incorrect.\nWould you like to sign up? (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        std::cout << "Enter a username for the new account: ";
        std::string name;
        std::cin >> name;
        if (registerUser(id, pass, name)) {
            userID = id;
            password = pass;
            username = name;
            return true;
        }
    }

    return false;  // Return false if login or registration fails
}
