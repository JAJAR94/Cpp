#ifndef HEADER2_hpp
#define HEADER2_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
struct student {
  	string name;
  	int score;
};
int getmax(vector<int> num);
int getmin(vector<int> num);
double getava(vector<int> num);
void sortvec(vector<student> &students);

#endif