#include <iostream>
#include <string>
using std::cin;         
using std::endl;
using std::cout;        
using std::string;



// int main() {
//     // ask for the person's name
//     cout << "Please enter P1 name: ";
//     // read the name
//     string name1;
//     cin >> name1;
//     cout << "Please enter P2 name: ";
//     string name2;
//     cin >> name2;
// const string greeting1 = "Player1: " + name1; 
// const string greeting2 = "Player2: " + name2;
//     const int pad = 1;
//     // the number of rows and columns to write
//     const int rows = pad * 2 + 7;
//     const string::size_type cols = (greeting1.size()+ pad * 2 + 2);
//     // write a blank line to separate the output from the input
// cout << endl; 
// // ...
// // write `rows' rows of output
// // invariant: we have written `r' rows so far 
// for (int r = 0; r != rows; ++r) {
//         string::size_type c = 0;
// // invariant: we have written `c' characters // so far in the current row 
// while (c != cols) {
//             if (r == pad + 1 && c == pad + 1) {
//                 cout << greeting1;
//                 c += greeting1.size();
//             }
//             if (r == pad +5 && c== pad +1){
//                 cout << greeting2;
//                 c += greeting2.size();
//             }
//  else {
//                 // are we on the border?
//                 if (r == 0 || r == rows - 1 ||
//                     c == 0 || c == cols - 1 ||
//                     r == 4)
//                     cout << "*";
// else
//                     cout << " ";
//                 ++c;
// } }
//         cout << endl;
//     }
// return 0; 
// }


int main() {
    // ask for the person's name
    cout << "Please enter P1 name: ";
    // read the name
    string name1;
    cin >> name1;
    cout << "Please enter P2 name: ";
    string name2;
    cin >> name2;
const string greeting1 = "Player1: " + name1; 
const string greeting2 = "Player2: " + name2;
    const int pad = 1;
    // the number of rows and columns to write
    const int rows = pad * 2 + 7;
    const string::size_type cols = (greeting1.size()+ pad*2 + 2);
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
 else {
                // are we on the border?
                if (r == 0 || r == rows - 1 ||
                    r == 4){
                        if (c == 0 || c == cols-1)
                        {
                            cout << "+";
                        }
                        else{
                            cout << "-";
                        }
                    }
                else{
                    if (c == 0|| c== cols -1)
                    cout << "|";
                    else{
                        cout << " ";
                    }
                }
                ++c;
} }
        cout << endl;
    }
return 0; }

