#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

struct Point
{
    int x;
    int y;
};

vector<Point> create_point_list(vector<int> xlist, vector<int> ylist){
    vector<Point> newvec;
    int size=0;
    for (int element: xlist)
        size++;
    for (int i = 0; i <= size - 1; i++){
        Point p;
        p.x = xlist[i];
        p.y = ylist[i];
        newvec.push_back(p);
    }
    return newvec;
}

void split_point_fields(vector<Point> point_list){
    int size=0;
    for (Point element: point_list)
        size++;
    for (int i = 0; i <= size - 1; i++){
    std::cout<<point_list[i].x<<" "<<point_list[i].y<<std::endl;
}
}

int main(){
    vector<int> xlist = {1,2,3,4,5};
    vector<int> ylist = {6,7,8,9,10};
    vector<Point> pointlist = create_point_list(xlist,ylist);
    split_point_fields(pointlist);
}