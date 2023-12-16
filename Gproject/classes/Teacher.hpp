#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include "Homework.hpp"
#include "Student.hpp"

class Teacher {
public:
    void command();
    void gradingHomework(const Homework& hw, const Student& stu);
    void displayStudentsInCourse();
    void assignHomeworkToStudentInteractive();
    void assignCourseToStudentInteractive();

private:
    void assignHomeworkToStudent(const string* studentName, const string* homeworkName);
    void assignCourseToStudent(const string& studentName, const string& courseName);
};

#endif