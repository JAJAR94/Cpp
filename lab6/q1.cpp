#include <iostream>
#include <string>
#include <vector>
#include <array>
using std::vector;
using std::array;
using std::string;

void to_upper(char *s){
   for (char *p = s; *p!=NULL;*p++){
    char upper = *p;
    upper-=32;
    std::cout<<upper;
   }
   
}

void rev_dup(const char *s){
    int count = 0;
    for(; s[count] != 0; count++);
    
    const char *p = s;
    
    for (int i=count;i>=0;i--){
    
    std::cout<<*(p+i);
   
}
}

char* read_text(std::istream& in){
    char* s = new char[1];
    int len = 0;
    char c;

    while(in.get(c)){
        if (c == '!') {
            break;
        }

        char* new_s = new char[len + 1];

        for (int i = 0; i < len; ++i) {
            new_s[i] = s[i];
        }

        new_s[len] = c;
        delete[] s;
        s = new_s;
        len++;
    }

    s[len] = '\0';
    return s;
}

int main() {

    
    char s[] = "helloxab";
    
    to_upper(s);
    
    //std::cout<<read_text(std::cin);
    
}
