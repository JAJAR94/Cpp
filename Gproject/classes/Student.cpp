#include "Student.hpp"
#include "globals.hpp"

using namespace std;
namespace fs = std::filesystem;


Student::Student() : score(0), fullscore(0) {}

Student::Student(const string& _name, int _score, int _fullscore)
    : name(_name), score(_score), fullscore(_fullscore) {}

Student::Student(const string& _name) : name(_name), score(0), fullscore(0) {}

string Student::getname() const {
    return name;
}

int Student::getfullscore() const {
    return fullscore;
}

int Student::getscore() const {
    return score;
}

void Student::setname(const string& _name) {
    name = _name;
}

void Student::setscore(int _score) {
    score = _score;
}

void Student::setfullscore(int _fullscore) {
    fullscore = _fullscore;
}

void Student::command() {
    cout << "Choose option:" << endl;
    cout << "1. Submission Homework" << endl;
    cout << "2. Display your Course" << endl;
    cout << "3. Display your Homework" << endl;
    cout << "4. Check your current score" << endl;
    cout << "9. exit" << endl;

    int command_choice;
    if (!(cin >> command_choice)) {
        cout << "Please enter a number, not a string." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    string hwname;
    Homework hw("");

    switch (command_choice) {
        case 1:
            cout << "Enter the name of the homework: ";
            cin >> hwname;

            hw.setName(hwname);
            submission_homework(hw);
            break;

        case 2: {
            string directoryPath = directorypath_s;
            displayCoursesorHomeworkForStudent(directoryPath + getname() + ".txt", 4);
            break;
        }

        case 3: {
            string directoryPath = directorypath_s;
            displayCoursesorHomeworkForStudent(directoryPath + getname() + ".txt", 5);
            break;
        }

        case 4:
            showgrade();
            break;

        case 9:
            exit(0);

        default:
            cout << "Please enter a correct option." << endl;
    }
}

void Student::readfileoneonly(const string& filePath) {
    ifstream file(filePath);
    if (file) {
        string fileContent;
        getline(file, fileContent);
        size_t slashPos = fileContent.find('/');
        if (slashPos != string::npos) {
            string scoreStr = fileContent.substr(0, slashPos);
            string fullScoreStr = fileContent.substr(slashPos + 1);

            // Convert the substrings to integers
            int scoreint = stoi(scoreStr);
            int fullScoreint = stoi(fullScoreStr);

            score += scoreint;
            fullscore += fullScoreint;
        }

        file.close();
    }
}

void Student::showgrade() {
    string folderPath = directorypath_s + name;

    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            string filePath = entry.path().string();
            readfileoneonly(filePath);
        }
    }
    cout << "Your current score is: " << score << endl;
    cout << "Full score is: " << fullscore << endl;
}

void Student::submission_homework(const Homework& hw) {
    string hw_name = hw.getName();
    filesystem::path folderPathforhw(directorypath_s + name);
    filesystem::path filePath = folderPathforhw / (hw_name + ".txt");

    if (filesystem::exists(filePath) && filesystem::is_regular_file(filePath)) {
        string filepath_stu = directorypath_s + name + ".txt";
        ifstream inFile(filepath_stu);

        string deleteWord = hw_name;

        string content, line;
        while (getline(inFile, line)) {
            size_t found = line.find(deleteWord);
            if (found != string::npos) {
                line.erase(found, deleteWord.length());
            }
            content += line + '\n';
        }
        inFile.close();

        ofstream outFile(filepath_stu);
        if (!outFile) {
            cout << "Failed to open file: " << filepath_stu << endl;
            return;
        }

        outFile << content;
        outFile.close();

        cout << "Homework submission successful." << endl;
    } else {
        cout << "Your Homework does not exist in the folder." << endl;
    }
}

void Student::displayCoursesorHomeworkForStudent(const string& fileName, const int& lv) {
    string studentName = fs::path(fileName).stem().string();
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "No student named " << studentName << endl;
        return;
    }

    string courseLine;
    int lineNumber = 1;

    while (getline(inputFile, courseLine) && lineNumber < lv) {
        ++lineNumber;
    }

    if (lineNumber == lv) {
        vector<string> courses;
        istringstream iss(courseLine);
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(courses));

        cout << "Homework for " << studentName << ":" << endl;
        for (const string& course : courses) {
            cout << course << endl;
        }
    } else {
        cout << "No Homework found in " << fileName << "." << endl;
    }

    inputFile.close();
}
