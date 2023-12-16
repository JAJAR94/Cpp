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
    vector<int> firsthalf;
    vector<int> lasthalf;
};

vector<int> combine(Data &data)
{
    vector<int> combinevec;
    vector<int> tempfirsthalf = data.firsthalf;
    vector<int> templasthalf = data.lasthalf;

    while (true) {
        if (tempfirsthalf.empty() || templasthalf.empty()){
            break;
        }
        combinevec.push_back(tempfirsthalf[0]);
        combinevec.push_back(templasthalf[0]);
        tempfirsthalf.erase(tempfirsthalf.begin());
        templasthalf.erase(templasthalf.begin());
    }

    combinevec.insert(combinevec.end(), tempfirsthalf.begin(), tempfirsthalf.end());
    combinevec.insert(combinevec.end(), templasthalf.begin(), templasthalf.end());

    return combinevec;
}

void cartesian_product(Data& data){
  
  for (int i=0; i<=data.firsthalf.size()-1; i++){
        std::cout<<"\n";
    for (int k=0; k<=data.lasthalf.size()-1; k++){
        std::cout << "(" << data.firsthalf[i] << "," << data.lasthalf[k] << "), " ;
    }
  }

}


int sop(Data &data){
    int sum = 0;
    vector<int> tempfirsthalf = data.firsthalf;
    vector<int> templasthalf = data.lasthalf;
    while (true) {
        
        if (tempfirsthalf.empty() || templasthalf.empty()){
            break;
        }
        sum+=tempfirsthalf[0]*templasthalf[0];

        tempfirsthalf.erase(tempfirsthalf.begin());
        templasthalf.erase(templasthalf.begin());
    }

    return sum;
}

void read(Data &data, string filename)
{
    string mytext, d;
    std::ifstream Myreadfile(filename);

    while (getline(Myreadfile, mytext))
    {
        std::stringstream ss1(mytext);
        string s;
        int num;

        std::getline(ss1, s, ';');
        std::stringstream ss2(s);
        while (ss2 >> num)
        {
            data.firsthalf.push_back(num);
        }

        while (ss1 >> num)
        {
            data.lasthalf.push_back(num);
        }
    }
}

std::ostream &printing(std::ostream &os, Data &data1, Data &data2){
    os<<"Output for 1.1 data1"<<"\n";
    for (auto i:combine(data1)){
        os<<i<<" ";
    }
    os<<"\n";
    os<<"Output for 1.1 data2"<<"\n";
    for (auto i:combine(data2)){
        os<<i<<" ";
    }
    os<<"\n";
    os<<"Output for 1.2 data1"<<"\n";
    os<<sop(data1);
    os<<"\n";
    os<<"Output for 1.2 data2"<<"\n";
    os<<sop(data2);
    os<<"\n";
    os<<"Output for 1.3 data1";
    cartesian_product(data1);
    os<<"\n";
    os<<"Output for 1.3 data2";
    cartesian_product(data2);
    return os;
}

int main()
{
    Data data1, data2;
    read(data1, "../data1.txt");
    read(data2,"../data2.txt");
    printing(std::cout,data1,data2);


    return 0;
}
