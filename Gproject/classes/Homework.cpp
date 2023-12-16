#include "Homework.hpp"
#include "globals.hpp"

Homework::Homework()
    : duedate(0), point(0) {}

Homework::Homework(string nm)
    : name(nm), duedate(0), point(0) {}

Homework::Homework(string nm, int due, int pt)
    : name(nm), duedate(due), point(pt) {}

Homework::~Homework() {}

string Homework::getName() const {
    return name;
}

void Homework::setName(const string& nm) {
    name = nm;
}