#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
using std::string;
using std::vector;
struct Data
{
    vector<double> first;
    vector<double> middle;
    vector<double> last;
};

void read(Data &data, string filename)
{
    string mytext, d;
    std::ifstream Myreadfile(filename);

    while (getline(Myreadfile, mytext))
    {
        std::stringstream ss(mytext);

        string s;
        double num, num1, num2;

        if (std::getline(ss, s, ';'))
        {
            
            std::stringstream ss1(s);
            while (ss1 >> num)
            {
                data.first.push_back(num);
            }
        }
        if (std::getline(ss, s, ';'))
        {
            
            std::stringstream ss2(s);

            while (ss2 >> num1)
            {
                data.middle.push_back(num1);
            }
        }

        if (std::getline(ss, s, ';'))
        {
            
            std::stringstream ss3(s);

            while (ss3 >> num2)
            {
                data.last.push_back(num2);
            }
        }
    }
}

double findave(vector<double> vec){
    double sum=0;
    int divide = vec.size();
    for (int i=0; i<=divide-1; i++){
        sum+=vec[i];
    }
    return sum/divide;

}

void cartesian_product(Data& data){
  
  for (int i=0; i<=data.first.size()-1; i++){
    for (int k=0; k<=data.middle.size()-1; k++){
        std::cout << "\n";
        for (int j=0; j<=data.last.size()-1; j++){
            std::cout<<"("<<data.first[i]<<", "<<data.middle[k]<<", "<<data.last[j]<<"), ";
        }
    }
  }

}


std::ostream &printing(std::ostream &os, Data &data){
    os<<"Output for 2.1"<<"\n";
    os<<findave(data.first)<<findave(data.middle)<<findave(data.last);
    os<<"\n";
    os<<"Output for 2.2";
    cartesian_product(data);
    return os;
}

int main()
{
    Data data;
    read(data, "../data3.txt");
    printing(std::cout,data);
    
}