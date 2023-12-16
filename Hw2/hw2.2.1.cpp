#include "header2.hpp"
int main() {
	std::ifstream infile("score.txt");
  	vector<student> students;
  	string line;
  	while (std::getline(infile, line)) {
    	std::istringstream iss(line);
  	  	student s;
  		iss >> s.name;

    int score;
    vector<int> scores;
    while (iss >> score) {
      scores.push_back(score);
    }
	if (scores.empty()) {
    continue;
  	}
    s.score = getmax(scores);
    students.push_back(s);
  	}

	sortvec(students);

	std::cout<<"Max Score Rankings"<<std::endl;
	int rank = 1;
  	for(const auto& s : students) {
    std::cout << rank << ". " << s.name << " " << s.score << std::endl;
	rank++;
  }

  return 0;
}