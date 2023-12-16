#include "Login.hpp"
#include "globals.hpp"
// Implementation of Login class member functions



Login::Login(string username, string password) : User(username, password) {}

string Login::getstatus()
{
    return statuslogin;
}

string Login::logingIn()
{
    bool loggedIn = false;
    string filename;
    string status;

    while (!loggedIn)
    {
        cout << "Logging in!" << endl;
        cout << "Enter your status (student or teacher): ";
        cin >> status;
        toLower(status);

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        if (status == "student" || status == "stu" || status == "s" || status == "students")
        {
            filename = directorypath_s + username + ".txt";
            statuslogin = "student";
        }
        else if (status == "teacher" || status == "tea" || status == "t" || status == "teachers")
        {
            filename = directorypath_t + username + ".txt";
            statuslogin = "teacher";
        }
        else
        {
            cout << "Please enter a valid status!" << endl;
            continue;
        }

        ifstream readFile(filename);
        if (readFile.is_open())
        {
            string userfullname;
            string storedUsernameAndPassword;
            string storedUsername, storedPassword;
            getline(readFile, userfullname);
            getline(readFile, storedUsernameAndPassword);

            int spacePos = storedUsernameAndPassword.find(' ');
            int stringsize = storedUsernameAndPassword.size();
            storedUsername = storedUsernameAndPassword.substr(0, spacePos);
            storedPassword = storedUsernameAndPassword.substr(spacePos + 1, stringsize);

            if (storedUsername == username && storedPassword == password)
            {
                cout << "Login successful!" << endl;
                loggedIn = true;
            }
            else
            {
                cout << "Invalid username or password. Please try again." << endl;
                continue;
            }
            readFile.close();
        }
        else
        {
            cout << "Invalid username or password. Please try again." << endl;
            continue;
        }
    }

    return username;
}

void Login::forgotPass()
{
    string filename;
    string status;
    string fullname;
    string confirm;
    cout << "Forgot your password?" << endl;
    cout << "Would you like to reset your password? (yes/no):";
    cin >> confirm;
    toLower(confirm);
    if (confirm == "y" || confirm == "yes")
    {

        cout << "Changing password!" << endl;
        cout << "Enter your status (student or teacher): ";
        cin >> status;
        toLower(status);

        cout << "Enter your fullname: ";
        getline(cin >> ws, fullname);
        toLower(fullname);
        noSpace(fullname);

        cout << "Enter username: ";
        cin >> username;

        string newPass;
        cout << "Enter your new password: ";
        cin >> newPass;

        if (status == "student")
        {

            filename = directorypath_s + username + ".txt";
            statuslogin = "student";
        }
        else if (status == "teacher")
        {

            filename = directorypath_t + username + ".txt";
            statuslogin = "teacher";
        }

        passChange(filename, username, newPass, fullname);
    }
}

void Login::passChange(string filename, string username, string newPass, string fullname)
{
   string question;
        int questionChoice;
        string answer;

        string question1 = "What was your favorite subject?";
        noSpace(question1);
        string question2 = "What is your citizen ID number?";
        noSpace(question2);
        string question3 = "Where were you born?";
        noSpace(question3);
        string question4 = "What is the name of your pet?";
        noSpace(question4);
        string question5 = "Who was your most favorite hero?";
        noSpace(question5);

        cout << "Pick the question that you register" << endl;
        ;
        cout << "Security Question:" << endl;
        cout << "1. What was your favorite subject?" << endl;
        cout << "2. What is your ID number?" << endl;
        cout << "3. Where were you born?" << endl;
        cout << "4. What is the name of your pet?" << endl;
        cout << "5. Who was your most favorite hero?" << endl;
        cout << "Which is your question(1-5): ";
        cin >> questionChoice;
        switch (questionChoice)
        {
        case 1:
            question = question1;
            break;
        case 2:
            question = question2;
            break;
        case 3:
            question = question3;
            break;
        case 4:
            question = question4;
            break;
        case 5:
            question = question5;
            break;
        default:
            cout << "Invalid question choice!" << endl;
        }

        cout << "Enter the answer that you register: ";
        getline(cin >> ws, answer);
        toLower(answer);
        noSpace(answer);

        string storeduserandpass;
        string storedQuestionAnswer;
        string storedQuestion;
        string storedAnswer;

        ifstream readFile(filename);
        if (readFile.is_open())
        {
            getline(readFile, fullname);
            getline(readFile, storeduserandpass);
            getline(readFile, storedQuestionAnswer);

            int spacePos = storedQuestionAnswer.find(' ');
            int stringsize = storedQuestionAnswer.size();
            storedQuestion = storedQuestionAnswer.substr(0, spacePos);
            storedAnswer = storedQuestionAnswer.substr(spacePos + 1, stringsize);

            if (storedQuestion == question && storedAnswer == answer)
            {
                ofstream writeFile(filename);
                writeFile << fullname << endl;
                writeFile << username << " " << newPass << endl;
                writeFile << question << " " << answer << endl;
                writeFile.close();
                cout << "Your password have been successfully change." << endl;
                return;
            }
            cout << "Question and answer do not match. Please try again." << endl;
        }
        else
        {
            cout << "Failed to open the file. Question and answer check failed." << endl;
        }
}
