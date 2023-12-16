#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <string>
using namespace std;

class Homework {
private:
    std::string name;
    int duedate;
    int point;

public:
    Homework();
    Homework(std::string nm);
    Homework(std::string nm, int due, int pt);
    ~Homework();

    std::string getName() const;
    void setName(const std::string& nm);
};

#endif  // HOMEWORK_H