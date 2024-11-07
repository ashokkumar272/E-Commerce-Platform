#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string userID;
    std::string password;
    std::string username;

public:
    User() = default;
    User(const std::string& id, const std::string& pass, const std::string& name)
        : userID(id), password(pass), username(name) {}

    bool login();  // Declaration for the login function
    std::string getUserID() const { return userID; }

    // Helper functions for user management
    static bool validateCredentials(const std::string& id, const std::string& pass);
    static bool registerUser(const std::string& id, const std::string& pass, const std::string& name);
};

#endif
