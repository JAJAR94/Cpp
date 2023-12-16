#include <iostream>
#include <string>
using std::string;

string unstylize(string word){
    
    if (word.front() == '*' && word.back() == '*' ){
        string words = {};
        return word.substr(1,word.size()-2);
    }

    else {
        return word;
    }

}

int main(){
    string words[] = {"c","*c++*","Rust*","*Python*","*Java"};
    int n = sizeof(words) / sizeof(words[0]);
    
    for (n-=1;n>=0;n--){
        std::cout << unstylize(words[n]);
        }
    
    return 0;
}
