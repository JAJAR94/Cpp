#include <iostream>
#include <string>
using std::cin;         
using std::endl;
using std::cout;        
using std::string;


string tri_pattern(int level){
    string s;
    int i,j;
    for (i=1;i<=level;i++)
    {
        for (j=level;j>=1;j--)
        {
            if (j>i)
            {
                s+= " ";
            }
            else
            {
                s+= "*";
            }
        }
        s+= "\n";
    }
    for (i=level-1;i>=1;i--)
    {
        for (j=level;j>=1;j--)
        {
            if(j>i)
            {
                s+=  " ";
            }
            else
            {
                s+=  "*";
            }
        }
        s+= "\n";
    }
    return s;

}


int main(){
    int level;
    cout << "Enter level: ";
    cin >> level;
    auto s =tri_pattern(level);
    cout << s;
    return 0;
}