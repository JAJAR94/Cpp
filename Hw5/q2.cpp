#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using std::string;
using std::vector;

class Picture{
    private:
    int width;
    int hight;
    string realpic;
    public:

    Picture(int width_, int hight_, string realpic_){
        width = width_;
        hight = hight_;
        realpic = realpic_;
    }

    int getwidth(){
        return width;
    }

    int gethight(){
        return hight;
    }

    string vcat(){
        return realpic+=realpic;
    }

    string hcat(){
        std::ifstream file("../data.txt");
        string pic;
        std::string line;
        while (std::getline(file, line)) {
            pic += line;
            pic += "     ";
            pic += line + '\n';
    }
    return pic;
    }

};

std::ostream &print(std::ostream &os, Picture &pic){
    os<<"horizon combine"<<"\n";
    os << pic.hcat();
    os<<"vertical combine"<<"\n";
    os << pic.vcat();
    return os;
}


int main() {
    std::ifstream file("../data.txt");
    int hight = 0;
    int widght = 0;
    string pics;
    std::string line;
    while (std::getline(file, line)) {
        pics += line + '\n';
        int column_count = line.length();
        if (column_count > widght) {
            widght = column_count;
        }
        hight++;
    }
    Picture pic(widght,hight,pics);
    print(std::cout,pic);
}