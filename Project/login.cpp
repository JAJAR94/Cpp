#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class UserSignUp 
{
    protected:
        map<string, string>* name_password_map;
        map<string, string>* question_answer_map;
        string dataFilePath;

    public:
        UserSignUp(const string& filePath) : dataFilePath(filePath) 
        {
            name_password_map = new map<string, string>();
            question_answer_map = new map<string, string>();
        }

        void set_username(const string& newuser) 
        {
            (*name_password_map)[newuser]="";
        }

        void set_password(const string& newpassword) 
        {
            auto count = name_password_map->rbegin();
            if (count != name_password_map->rend()) 
            {
                count->second = newpassword;
            }
        }

        void set_recovery_password(const string& question, const string& answer) 
        {
            auto count = name_password_map->rbegin();
            if (count != name_password_map->rend()) 
            {
                (*question_answer_map)[count->first] = question;
                (*question_answer_map)[question] = answer;
            }
        }

        string getPassword(const string& username,const string& password) 
        {
            loadDataFromFile();
            auto it = name_password_map->find(username);
            cout<<"triggered"<<endl;
            //cout<<it->second<<"1"<<endl;
            
            if ((*name_password_map)[username]==password) 
            {
                cout<<(*name_password_map)[username]<<"2"<<endl;
                
                return it->second;
            }
            return "";
        }

        void registerUser() 
        {
            cout << "Enter username: ";
            string username;
            cin.ignore();
            getline(cin,username);
            set_username(username);

            cout << "Enter password: ";
            string password;
            getline(cin,password);
            set_password(password);

            cout << "Enter recovery question: ";
            string question;
            getline(cin, question, '\n');

            cout << "Enter recovery answer: ";
            string answer;
            getline(cin, answer, '\n');

            set_recovery_password(question, answer);

            saveDataToFile();
            cout << "User registered successfully!" << endl;
        }
       void forget_password() 
        {
            cout << "Enter username: ";
            string username;
            cin.ignore();
            getline(cin, username);


        }

        void loadDataFromFile() 
        {
            ifstream dataFile(dataFilePath);
            if (dataFile.is_open()) 
            {
                string username;
                string password;
                string question;
                string answer;
                while (dataFile >> username >> password >> question >> answer) 
                {
                    (*name_password_map)[username] = password;
                    (*question_answer_map)[username] = question;
                    (*question_answer_map)[question] = answer;
                }
                dataFile.close();
            }
            else 
            {
                cout << "Error: Unable to open file " << dataFilePath << endl;
            }
        }

        void saveDataToFile() 
        {
            ofstream dataFile(dataFilePath);
            if (dataFile.is_open()) 
            {
                for (const auto& entry : *name_password_map) 
                {
                    const string& username = entry.first;
                    const string& password = entry.second;
                    const string& question = (*question_answer_map)[username];
                    const string& answer = (*question_answer_map)[question];
                    dataFile << username << " " << password << " " << question << " " << answer << endl;
                }
                dataFile.close();
            }
            else 
            {
                cout << "Error: Unable to open file " << dataFilePath << endl;
            }
        }

        ~UserSignUp() 
        {
            delete name_password_map;
            delete question_answer_map;
        }

        void printNameAndPassword()
        {
            for (const auto& entry : *name_password_map) 
            {
                const string& username = entry.first;
                const string& password = entry.second;
                cout << "Username: " << username << ", Password: " << password << endl;
            }
        }
};

class Login : public UserSignUp 
{ 
public:
    Login(const string& filePath) : UserSignUp(filePath){}

    bool authenticate() 
    {
        cin.ignore();
        while (true) 
        {
            cout << "Enter username: ";
            string username;

            getline(cin,username);

            cout << "Enter password: ";
            string password;
            getline(cin,password);

            string storedPassword = getPassword(username, password);
            cout<<storedPassword<<"3"<<endl;
            
            if(!storedPassword.empty()&&storedPassword == password) 
            {
                cout << "Login successful!" << endl;
                return true;
            }
            else
            {
                cout<<storedPassword<<"4"<<endl;
                cout << "Invalid username or password. Please try again." << endl;
            }
            
        }
    }
};

int main() 
{
    string dataFilePath = "user_data.txt";
    UserSignUp* signup = new UserSignUp(dataFilePath);
    signup->loadDataFromFile();
    Login* login = new Login(dataFilePath);

    while (true) 
    {
        cout << "Select the number" << endl << "1. Sign up" << endl << "2. Login" << endl<<"3. Forget password?";
        string selection;
        cin >> selection;

        if (selection == "1")
        {
            signup->registerUser();
        }
        else if (selection == "2") 
        {
            if (login->authenticate()) 
            {
                break; 
            }
        }
        else if(selection == "3")
        {
            signup->forget_password();
        }
        else if(selection == "4")
        {
            signup->printNameAndPassword();
        }
        else 
        {
            cout << "Please enter the correct number" << endl;
        }
    }

    delete signup;
    delete login;
    return 0;
}