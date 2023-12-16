#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "classes/Homework.hpp"
#include "classes/Login.hpp"
#include "classes/Register.hpp"
#include "classes/Student.hpp"
#include "classes/Teacher.hpp"
#include "classes/User.hpp"
using namespace std;
namespace fs = std::filesystem;

int main()
{
    cout << " ___       __       _______       ___           ________      ________      _____ ______       _______        \n";
    cout << "|\\  \\     |\\  \\    |\\  ___ \\     |\\  \\         |\\   ____\\    |\\   __  \\    |\\   _ \\  _   \\    |\\  ___ \\       \n";
    cout << "\\ \\  \\    \\ \\  \\   \\ \\   __/|    \\ \\  \\        \\ \\  \\___|    \\ \\  \\|\\  \\   \\ \\  \\\\__\\ /\\  \\   \\ \\   __/|      \n";
    cout << " \\ \\  \\  __\\ \\  \\   \\ \\  \\_|/__   \\ \\  \\        \\ \\  \\        \\ \\  \\ \\  \\   \\ \\  \\__| \\ \\  \\   \\ \\  \\_|/__    \n";
    cout << "  \\ \\  \\|\\__\\_\\  \\   \\ \\  \\_|\\ \\   \\ \\  \\____    \\ \\  \\____    \\ \\  \\_\\  \\   \\ \\  \\    \\ \\  \\   \\ \\  \\_|\\ \\   \n";
    cout << "   \\ \\____________\\   \\ \\_______\\   \\ \\_______\\   \\ \\_______\\   \\ \\_______\\   \\ \\__\\    \\ \\__\\   \\ \\_______\\  \n";
    cout << "    \\|____________|    \\|_______|    \\|_______|    \\|_______|    \\|_______|    \\|__|     \\|__|    \\|_______|  \n";
    cout << "Choose an option:" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Forgot Password" << endl;
    cout << "4. Exit" << endl;

    while(true){
    int choice;
    
    if (!(cin >> choice)) {
        cout << "Please enter a number, not a string." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }
    if (choice == 1)
    {
        Register register1;
        register1.registering();
        choice=2;
    }
    if (choice == 2)
    {
        Login login1;

        string n = login1.logingIn();

        string status = login1.getstatus();

        if (status == "student")
        {

            Student* stu = new Student(n);
            while (true)
            {
                stu->command();
            }
            delete stu;
        }
        else if (status == "teacher")
        {
            Teacher* AjSun = new Teacher();
            while (true)
            {
                AjSun->command();
            }
            delete AjSun;
        }
    }
    if (choice == 3)
    {
        Login login1;
        login1.forgotPass();
        login1.getstatus();
    }
    if (choice == 4)
    {
        break;;
    }
    else{
        continue;
    }
    }
}
