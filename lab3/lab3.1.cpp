#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <conio.h>
using std::list;
using std::vector;


void lshift(vector<double>& vec,int n){
    vec.erase(vec.begin(),vec.begin()+n);
}

void rshift(vector<double>& vec,int n){
    n-=1;
    for (int k=0;k<=n;k++){
        vec.insert(vec.begin(),0);

    }
}

void remove_negative(vector<double>& vec){
    for (int k=0;k<=vec.size();k++){
        if (vec[k]<=0){
            vec.erase(vec.begin()+k);
        }
    }
}

vector<double> scale(vector<double> v,double n){
    transform(v.begin(), v.end(), v.begin(), [&n](auto& c){return c*n;});
    return v;
}                   

vector<double> add(vector<double> vec2, vector<double> vec3){
    vector <double> vec4;
    int n = std::max(vec2.size(),vec3.size());
    n-=1;
    for (int k=0;k<=n;k++){
        double a,b;
        a,b = vec3[k],vec4[k];
        if (a == NULL){
            a == 0;
        }
        if (b == NULL){
            b == 0;
        }
        vec4.push_back(vec2[k]+vec3[k]);
    }
    return vec4;
    
}

list<double> removelist(list <double>& list1){
     auto it = remove_if(list1.begin(), list1.end(),  [](const int i) {return i < 0; });

     list1.erase(it, list1.end());
return list1;
}

int main(){
    std::vector <double> vec1{2,1,4,3,7};
    std::vector <double> vec2{1,3,2,5};
    std::list <double> list1 = {0.8, -5.1, 1.6, -6.5, 10.5};
    // lshift(vec1,3);
    // rshift(vec1,2);
    // remove_negative(vec1);
    // auto vec3 = scale(vec1,1.5);
    // auto vec4 = add(vec2, vec3);
    // auto vec5 = add(vec3, scale(vec2, -2.2));
    auto list2 = removelist(list1);
    for (auto i:list2){
       std::cout<<i;
       std::cout<<"\n";
   }
}