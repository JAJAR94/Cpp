#include "Teacher.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <limits>
#include <filesystem>
#include "globals.hpp"

namespace fs = filesystem;

bool isEqualIgnoreCase(const string &str1, const string &str2)
{
    return ::equal(str1.begin(), str1.end(), str2.begin(), str2.end(),
                   [](const char &c1, const char &c2)
                   {
                       return ::tolower(c1) == ::tolower(c2);
                   });
}

bool fileExists(const string &filePath)
{
    ifstream file(filePath);
    return file.good();
}

void Teacher::command()
{
    int choice;

    cout << "What do you want to do?" << endl;
    cout << "1. Assign homework" << endl;
    cout << "2. Check students in a course" << endl;
    cout << "3. Assign Course" << endl;
    cout << "4. Grading Homework" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";

    if (!(cin >> choice))
    {
        cout << "Please enter a number not string." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    string hwNameForGrade;
    string studentName;
    Homework hw("");
    Student stu("");

    switch (choice)
    {
    case 1:
        assignHomeworkToStudentInteractive();
        break;

    case 2:
        displayStudentsInCourse();
        break;

    case 3:
        assignCourseToStudentInteractive();
        break;

    case 4:
        cout << "Enter Homework you want to grade: ";
        cin >> hwNameForGrade;

        cout << "Enter Student you want to grade: ";
        cin >> studentName;

        hw.setName(hwNameForGrade);
        stu.setname(studentName);
        gradingHomework(hw, stu);
        break;

    case 5:
        exit(0);
        break;

    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }

    cout << endl;
}

void Teacher::gradingHomework(const Homework &hw, const Student &stu)
{
    string filePath = directorypath_s + stu.getname() + "/" + hw.getName() + ".txt";
    ifstream file(filePath);

    // Try to open the file
    if (file)
    {
        // Move the file pointer to the end of the file
        file.seekg(0, ios::end);

        // Get the file size
        streampos fileSize = file.tellg();

        // Check if the file is empty
        if (fileSize > 0)
        {
            cout << "You already graded this Homework" << endl;
            file.close();
            return;
        }
        file.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
        return;
    }

    int score, fullscore;
    cout << "Enter the score for your student: ";
    cin >> score;
    cout << "Enter the full score: ";
    cin >> fullscore;

    ofstream outputFile(filePath);

    if (outputFile)
    {
        outputFile << score << "/" << fullscore;
        outputFile.close();
    }
    else
    {
        cout << "Can't find that Hw " << filePath << endl;
    }
}

void Teacher::displayStudentsInCourse()
{
    string directoryPath = directorypath_s;
    vector<string> studentFiles;

    for (const auto &entry : fs::directory_iterator(directoryPath))
    {
        if (entry.path().extension() == ".txt")
        {
            studentFiles.push_back(entry.path().string());
        }
    }

    string searchCourse;
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the name of the course to search for students: ";
    cin >> searchCourse;

    vector<string> studentsInCourse;

    for (const string &file : studentFiles)
    {
        ifstream inputFile(file);
        if (!inputFile)
        {
            cout << "Error opening file: " << file << endl;
            continue;
        }

        string studentName;
        int lineNumber = 1;

        while (getline(inputFile, studentName) && lineNumber <= 4)
        {
            if (lineNumber == 4)
            {
                vector<string> courses;
                istringstream iss(studentName);
                copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(courses));

                transform(courses.begin(), courses.end(), courses.begin(),
                          [](string course)
                          {
                              transform(course.begin(), course.end(), course.begin(), ::tolower);
                              return course;
                          });

                string lowercaseCourse = searchCourse;
                transform(lowercaseCourse.begin(), lowercaseCourse.end(), lowercaseCourse.begin(), ::tolower);

                if (find_if(courses.begin(), courses.end(),
                            [lowercaseCourse](const string &course)
                            {
                                return isEqualIgnoreCase(course, lowercaseCourse);
                            }) != courses.end())
                {
                    // Remove the ".txt" extension from the file name
                    string fileName = fs::path(file).filename().string();
                    fileName = fileName.substr(0, fileName.length() - 4);
                    studentsInCourse.push_back(fileName);
                    break;
                }
            }
            ++lineNumber;
        }

        inputFile.close();
    }

    if (studentsInCourse.empty())
    {
        cout << "No students found in " << searchCourse << " course." << endl;
    }
    else
    {
        cout << "Students enrolled in " << searchCourse << " course:" << endl;
        for (const string &studentName : studentsInCourse)
        {
            cout << studentName << endl;
        }
    }
}

void Teacher::assignHomeworkToStudentInteractive()
{
    string directoryPath = directorypath_s; // Replace with directory path
    vector<string> studentFiles;

    for (const auto &entry : fs::directory_iterator(directoryPath))
    {
        if (entry.path().extension() == ".txt")
        {
            studentFiles.push_back(entry.path().string());
        }
    }

    string homeworkName;

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the name of the homework: ";
    getline(cin, homeworkName);

    vector<string> studentsToAssign;

    while (true)
    {
        string studentName;
        cout << "Enter the name of a student to assign homework (or enter 'done' to finish): ";
        getline(cin, studentName);

        if (studentName == "done")
        {
            break;
        }

        string studentFileName = directoryPath + studentName + ".txt";

        if (!fileExists(studentFileName))
        {
            cerr << "File does not exist for student '" << studentName << "'. Skipping assignment." << endl;
            continue;
        }

        studentsToAssign.push_back(studentName);
    }

    for (const auto &student : studentsToAssign)
    {
        // Create pointers to student name and homework name
        const string *studentPtr = &student;
        const string *homeworkPtr = &homeworkName;

        assignHomeworkToStudent(studentPtr, homeworkPtr);
    }
}

void Teacher::assignCourseToStudentInteractive()
{
    string directoryPath = directorypath_s; // Replace with directory path
    vector<string> studentFiles;

    for (const auto &entry : fs::directory_iterator(directoryPath))
    {
        if (entry.path().extension() == ".txt")
        {
            studentFiles.push_back(entry.path().string());
        }
    }

    string studentName;
    string courseName;

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the name of the student to assign course: ";
    getline(cin, studentName);

    cout << "Enter the name of the course: ";
    getline(cin, courseName);

    string studentFileName = directoryPath + studentName + ".txt";
    ofstream outputFile(studentFileName, ios::app);

    assignCourseToStudent(studentName, courseName);
}

void Teacher::assignHomeworkToStudent(const string *studentName, const string *homeworkName)
{
    string studentFile = directorypath_s + *studentName + ".txt";

    ifstream inputFile(studentFile);
    if (!inputFile)
    {
        cout << "Error opening file: " << studentFile << endl;
        return;
    }

    vector<string> lines;
    string line;

    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }

    inputFile.close();

    if (lines.size() >= 5)
    {
        // Append new homework
        istringstream iss(lines[4]);
        vector<string> homeworks(istream_iterator<string>{iss}, istream_iterator<string>());
        homeworks.push_back(*homeworkName);
        ostringstream oss;
        copy(homeworks.begin(), homeworks.end(), ostream_iterator<string>(oss, " "));
        lines[4] = oss.str();
    }
    else
    {
        while (lines.size() < 5)
        {
            lines.push_back("");
        }
        lines[4] = *homeworkName;
    }

    ofstream outputFile(studentFile);
    if (!outputFile)
    {
        cout << "Error opening file for writing: " << studentFile << endl;
        return;
    }

    for (const string &line : lines)
    {
        outputFile << line << endl;
    }

    outputFile.close();

    cout << "Homework \"" << *homeworkName << "\" assigned to student \"" << *studentName << "\" successfully." << endl;
}

void Teacher::assignCourseToStudent(const string &studentName, const string &courseName)
{
    string studentFile = directorypath_s + studentName + ".txt";

    if (!fs::exists(studentFile))
    {
        cout << "No file found for student: " << studentName << endl;
        return;
    }

    ifstream inputFile(studentFile);
    if (!inputFile)
    {
        cout << "Error opening file: " << studentFile << endl;
        return;
    }

    vector<string> lines;
    string line;

    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }

    inputFile.close();

    if (lines.size() >= 4)
    {
        // Append new course
        istringstream iss(lines[3]);
        vector<string> homeworks(istream_iterator<string>{iss}, istream_iterator<string>());
        homeworks.push_back(courseName);
        ostringstream oss;
        copy(homeworks.begin(), homeworks.end(), ostream_iterator<string>(oss, " "));
        lines[3] = oss.str();
    }
    else
    {
        while (lines.size() < 4)
        {
            lines.push_back("");
        }
        lines[3] = courseName;
    }

    ofstream outputFile(studentFile);
    if (!outputFile)
    {
        cout << "Error opening file for writing: " << studentFile << endl;
        return;
    }

    for (const string &line : lines)
    {
        outputFile << line << endl;
    }

    outputFile.close();

    cout << "Course \"" << courseName << "\" assigned to student \"" << studentName << "\" successfully." << endl;
}