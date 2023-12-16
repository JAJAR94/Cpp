#include <iostream>
#include <string>
using std::string;
string unstylize(string word){
    
    if (word.front() == '*' && word.back() == '*' ){
        return word.substr(1,word.size()-2);
    }

    else {
        return word;
    }

}

int main(){
    //std::ofstream myfile("test.html");
    auto words = {"c","*c++*","Rust*","*Python*","*Java"};
 
    
    for (const auto& w: words){
        std::cout << unstylize(w);
        }
    
    return 0;
}
