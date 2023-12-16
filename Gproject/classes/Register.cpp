#include "Register.hpp"
#include "globals.hpp"

Register::Register(std::string username, std::string password)
    : User(username, password) {}

void Register::registering()
{
    string status;
    string fullname;
    cout << "Registering!" << endl;
    cout << "Enter your full name: ";
    getline(cin >> ws, fullname);
    toLower(fullname);
    noSpace(fullname);

    string filename;
    while (true)
    {
        cout << "Enter your status (student or teacher): ";
        cin >> status;
        toLower(status);

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        if (status == "student")
        {
            filename = directorypath_s + username + ".txt";
            if (checkUsername(filename))
            {
                cout << "This username is already used." << endl;
                continue;
            }
            break;
        }
        else if (status == "teacher")
        {
            filename = directorypath_t + username + ".txt";
            if (checkUsername(filename))
            {
                cout << "This username is already used." << endl;
                continue;
            }
            break;
        }
        else
        {
            cout << "Please enter a valid status!" << endl;
            continue;
        }
    }

    ofstream createfile(filename.c_str(), ios::app);

    while (true)
    {
        if (createfile.is_open())
        {
            createfile << fullname << endl;
            createfile << username << " " << password << endl;
            createfile.close();
            passQuestion(filename);
            (fs::create_directory(directorypath_s + username));
            cout << "Register complete!" << endl;
            break;
        }
        else
        {
            cerr << "Error! Could not register!" << endl;
            continue;
        }
    }
}

void Register::passQuestion(std::string filename)
{
    ofstream createfile(filename.c_str(), ios::app);
    if (createfile.is_open())
    {
        cout << "Security Question:" << endl;
        cout << "1. What was your favorite subject?" << endl;
        cout << "2. What is your ID number?" << endl;
        cout << "3. Where were you born?" << endl;
        cout << "4. What is the name of your pet?" << endl;
        cout << "5. Who was your most favorite hero?" << endl;

        int questionChoice;
        string answer;
        bool validChoice = false;
        string questionstr;

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

        while (!validChoice)
        {
            cout << "Choose a security question (1-5): ";
            if (!(cin >> questionChoice))
            {
                cout << "Please enter a number, not a string." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore();

            switch (questionChoice)
            {
            case 1:
                questionstr = question1;
                break;
            case 2:
                questionstr = question2;
                break;
            case 3:
                questionstr = question3;
                break;
            case 4:
                questionstr = question4;
                break;
            case 5:
                questionstr = question5;
                break;
            default:
                cout << "Invalid question choice!" << endl;
                break;
            }

            createfile << questionstr;
            cout << "Answer: ";
            getline(cin, answer);
            noSpace(answer);
            toLower(answer);
            createfile << " " << answer << endl;
            validChoice = true;
            break;
        }

        string confirmation;
        cout << "Are you sure that your answer is correct? (yes/no): ";
        getline(cin >> ws, confirmation);
        toLower(confirmation);
        if (confirmation == "no" || confirmation == "n")
        {
            passQuestion(filename);
        }

        createfile.close();
    }
}