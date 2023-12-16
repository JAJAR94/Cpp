#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;


vector<string> unstylize(vector<string> word){
    vector<string> vec1;
    for (auto i:word){
        if (i.front() == '*' && i.back() == '*' ){
        
        vec1.push_back( i.substr(1,i.size()-2));
    }
        else{
            vec1.push_back(i);
        }
    }
    return vec1;

}


void sortvec(vector<string> & new_words){
    int n = new_words.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
      if (new_words[j] > new_words[j + 1]) {
        
        std::string temp = new_words[j];
        new_words[j] = new_words[j + 1];
        new_words[j + 1] = temp;
      }
        }
    }
}

int main(){
    std::vector <string> words{"c","*c++*","Rust*","*Python*","*Java"};
    std::vector <string> new_words = unstylize(words);

    sortvec(new_words);
    for (auto k:new_words){
        std::cout<<k<<std::endl;
    }
    
    
    return 0;
}