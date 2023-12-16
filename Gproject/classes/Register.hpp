#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include "User.hpp"
using namespace std;
namespace fs = std::filesystem;

class Register : public User {
public:
    Register(std::string username = "", std::string password = "");

    void registering();
    void passQuestion(std::string filename);
};

#endif  