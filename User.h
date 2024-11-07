#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

class User {
    std::string userID;
    std::string username;
    std::string password;
    bool isLoggedIn = false;

public:
    User() = default;

    bool signUp(const std::string& uname, const std::string& pass);
    bool login(const std::string& uname, const std::string& pass);
    bool isUserLoggedIn() const { return isLoggedIn; }
    std::string getUserID() const { return userID; }
    std::string getUsername() const { return username; }
};

#endif
