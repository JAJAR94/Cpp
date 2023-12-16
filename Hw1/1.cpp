#include <iostream>
#include <string>
using std::cin;         
using std::endl;
using std::cout;        
using std::string;
using std::max;
int main() {
    // ask for the person's name
    cout << "Please enter Warrior name: ";
    // read the name
    string name1;
    cin >> name1;
    cout << "Please enter Ninja name: ";
    string name2;
    cin >> name2;
    cout << "Please enter Mage name: ";
    string name3;
    cin >> name3;
    cout << "Please enter Fighter name: ";
    string name4;
    cin >> name4;

const string greeting1 = "Warrior: " + name1; 
const string greeting2 = "Ninja: " + name2;
const string greeting3 = "Mage: " + name3;
const string greeting4 = "Fighter: " + name4;
    const int pad = 1;
    // the number of rows and columns to write
    const int rows = pad * 2 + 7;
    const string::size_type cols = (max(greeting1.size(),max(greeting2.size(),max(greeting3.size(),greeting4.size())))+ pad * 2 + 2)*2;
    // write a blank line to separate the output from the input
cout << endl; 
// ...
// write `rows' rows of output
// invariant: we have written `r' rows so far 
for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
// invariant: we have written `c' characters // so far in the current row 
while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting1;
                c += greeting1.size();
            }
            if (r == pad +5 && c== pad +1){
                cout << greeting2;
                c += greeting2.size();
            }
            if (r == pad + 1 && c == (2*pad) + max(greeting1.size(),max(greeting2.size(),max(greeting3.size(),greeting4.size())))+ 4){
                cout << greeting3;
                c += greeting3.size();
            }
            if (r == pad + 5 && c == (2*pad) + max(greeting1.size(),max(greeting2.size(),max(greeting3.size(),greeting4.size())))+ 4){
                cout << greeting4;
                c += greeting4.size();
            }
 else {
                // are we on the border?
                if (r == 0 || r == rows - 1 ||
                    c == 0 || c == cols - 1 ||
                    r == 4 || c == cols /2)
                    cout << "*";
else
                    cout << " ";
                ++c;
} }
        cout << endl;
    }
return 0; }