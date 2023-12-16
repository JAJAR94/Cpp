#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>
#include <iterator>
#include "Homework.hpp"
using namespace std;
namespace fs = ::filesystem;


class Student {
private:
    string name;
    int score;
    int fullscore;

public:
    Student();
    Student(const string& _name, int _score, int _fullscore);
    Student(const string& _name);

    string getname() const;
    int getfullscore() const;
    int getscore() const;

    void setname(const string& _name);
    void setscore(int _score);
    void setfullscore(int _fullscore);

    void command();
    void readfileoneonly(const string& filePath);
    void showgrade();
    void submission_homework(const Homework& hw);
    void displayCoursesorHomeworkForStudent(const string& fileName, const int& lv);
};

#endif  