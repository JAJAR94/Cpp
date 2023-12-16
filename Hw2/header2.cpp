#include "header2.hpp"

int getmax(vector<int> num) {
	int max = num[0];
  	for (int i = 1; i < num.size(); i++) {
    if (num[i] > max) {
      	max = num[i];
    }
  }
  	return max;
}

int getmin(vector<int> num) {
	int min = num[0];
  	for (int i = 1; i < num.size(); i++) {
    if (num[i] < min) {
      	min = num[i];
    }
  }
  	return min;
}

double getava(vector<int> num) {
    double total,avarage = 0;
	int s = num.size();
  	for (int i = 1; i < num.size(); i++) {
    total += num[i];
  }
    avarage+= total/s;
  	return avarage;
}

void sortvec(vector<student> &students) {
  	int n = students.size();
  	for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      	if (students[j].score < students[j + 1].score) {
        
        student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
}