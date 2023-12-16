#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>

using namespace std;

class User {
protected:
    std::string username;
    std::string password;

public:
    User(std::string username = "", std::string password = "");

    std::string getUsername();
    std::string getPassword();
    void toLower(std::string& word);
    void noSpace(std::string& word);
    bool checkUsername(std::string filename);
};

#endif  