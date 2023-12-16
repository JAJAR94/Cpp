#include <iostream>
#include <string>
#include <array>
#include <vector>
using std::vector;
using std::string;
using std::array;

void substitute(string &text,string word, string rep){
    while(true){
    size_t s = text.find(word);
    if (s==string::npos){
        break;
    
    }
    text.replace(text.find(word),word.length(),rep);
    }
}

bool streq(char* str1, char* str2){
    while(*str1!= '\0' && *str2 != '\0'){
        if(*str1 != *str2){
            return 0;
        }
        str1++;
        str2++;
    }
    return 1;
}

char* substitute2(char* text, char* word, char* rep){
    int textlen = 0;
    while(text[textlen] != '\0'){
        textlen++;
    }

    int wordlen = 0;
    while(word[wordlen] != '\0'){
        wordlen++;
    }

    int replen = 0;
    while(rep[replen] != '\0'){
        replen++;
    }

    char* str = new char[(textlen*(replen+1)) + 1];
    char* start = str;
    while(*text != '\0'){
        if(streq(text,word)){
            while(*rep != '\0'){
                *str = *rep;
                str++;
                rep++;
            }
            rep-=replen;
            text+=wordlen-1;
            text++;
        }else{
            *str = *text;
            str++;
            text++;
        }
    }
    *str = '\0';
    

    return start;
}

vector<vector<double>> create_pairs(vector<double> vec){
    vector<vector<double>> newvec;
    if (vec.size()%2!=0){
        vec.pop_back();
    }
    int count=0;
    while(true){
        vector<double> temp;
        if (count==vec.size()){
            break;
        }
        temp.push_back(vec[count]);
        temp.push_back(vec[count+1]);
        count+=2;
        newvec.push_back(temp);
    }
    return newvec;

}



int main() {
    char text1[] = "abc python javapythonx";
    string texts = "abc python javapythonx";

    char word[] = "python";
    char rep []= "rust";
    substitute(texts, word,rep);
    std::cout<< texts;
    std::cout<<"\n";
    std::cout<<substitute2(text1, word,rep);
    vector<double> vec = {1.2,2.3,5,2,1.1,3,7};
    for (auto i:create_pairs(vec)){
        for (auto k:i){
            std::cout<<k<<" ";
        }
        
    }

    
}
