#include "User.h"

bool User::signUp(const std::string& uname, const std::string& pass) {
    std::ofstream file("users.txt", std::ios::app);
    if (file) {
        file << uname << " " << pass << "\n";
        file.close();
        return true;
    }
    return false;
}

bool User::login(const std::string& uname, const std::string& pass) {
    std::ifstream file("users.txt");
    std::string u, p;

    while (file >> u >> p) {
        if (u == uname && p == pass) {
            userID = uname;
            username = uname;
            isLoggedIn = true;
            return true;
        }
    }
    return false;
}
