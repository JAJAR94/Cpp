#include <iostream>
#include <string>
#include <vector>

using std::vector;

using std::string;

class Nd_vec{
    private:
    vector<int> vec;
    public:
    
    Nd_vec(vector<int> vec1)
    {
        vec = vec1;
    };

    ~Nd_vec(){
    //appropriate desturctor here
    };

    vector<int> getvec(){
        return vec;
    }

    int getsize(vector<int>  vec){
        int length = 0;
    
    for (int element: vec)
        length++;
   
    return length;
    }

    void printvec(){
        for (auto i:vec){
            std::cout<<i;
        }
    }
};