#include "User.hpp"
#include "globals.hpp"

User::User(std::string username, std::string password)
    : username(username), password(password) {}

std::string User::getUsername() {
    return username;
}

std::string User::getPassword() {
    return password;
}

void User::toLower(std::string& word) {
    for (char &c : word)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c + 32;
            }
        }
}

void User::noSpace(std::string& word) {
    for (char &c : word)
        {
            if (c == ' ')
            {
                c = '_';
            }
        }
}

bool User::checkUsername(std::string filename) {
    ifstream readfile(filename);
    return readfile.good();
    return false;
}