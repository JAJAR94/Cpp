#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using namespace std;


void extract_attrs(vector<string> vec,vector<string>& attrs,vector<string>& non_attrs){

    for(auto i:vec){
        if(i.front() == '[' && i[1] == '[' && i.back() == ']' ){
            attrs.push_back(i);
        }
        else{
            non_attrs.push_back(i);
        }
    }
   
}

ostream& print_words( ostream &out,vector<string> test_words){
    out << "{";
    for (auto i:test_words){
        out << "\"";
        out << i;
        out << "\"";
        out << ",";
    }
    out << "}";
    return out;

}

int main(){
    const vector<string> test_words{
    "switch", "[[noreturn]]",
    "if", "[[maybe_unused",
    "for", "[[fallthrough]]"
    };
    vector<string> attrs, non_attrs;

    extract_attrs(test_words, attrs, non_attrs);
    cout << "Test words: ";
    print_words(cout, test_words) << endl;
    cout << "Attributes: ";
    print_words(cout, attrs) << endl;
    cout << "Non attributes: ";
    print_words(cout, non_attrs) << endl;
    cout << "Attributes: ";
    print_words(cout, attrs) << endl;

}