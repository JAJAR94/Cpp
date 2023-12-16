#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include "User.hpp"

class Login : public User {
private:
    std::string statuslogin;

public:
    Login(std::string username = "", std::string password = "");

    std::string getstatus();
    std::string logingIn();
    void forgotPass();
    void passChange(std::string filename, std::string username, std::string newPass, std::string fullname);
};

#endif