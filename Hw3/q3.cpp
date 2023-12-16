#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
using std::string;
using std::vector;

struct Word{
    vector<string> with;
    vector<string> without;
};

void seperate(Word &word,vector<string> words){
    for (auto i:words){
        if (i.front() == '*' && i.back() == '*'){
            word.with.push_back(i);
        }
        else{
            word.without.push_back(i);
        }
    }
}

void cartesian_pair(Word &word){
    for (int i=0; i<=word.with.size()-1; i++){
        std::cout<<"\n";
        for (int k=0; k<=word.without.size()-1; k++){
            std::cout<<"("<<word.with[i]<<", "<<word.without[k]<<"), ";
        }
    }
}

int main(){
    Word word;
    vector<string> words  {"Red","*Green*","Blue","Cyan","*Black*","White"};
    seperate(word,words);
    cartesian_pair(word);
}