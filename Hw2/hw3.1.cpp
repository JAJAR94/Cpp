#include "header3.hpp"

int main(){
    int n;
    std::cout << "Type me n number";
    
    std::cin>>n;

    std::ofstream Myfile("../circle.svg");
    string text = "<svg width=\"500\" height=\"500\" xmlns=\"http://www.w3.org/2000/svg\">\n"
                          "<rect width=\"100%\" height=\"100%\" fill=\"#EEEEEE\" />\n"
                          "<circle cx=\"250\" cy=\"250\" r=\"250\"\n"
                          "stroke=\"black\" stroke-width=\"2\" fill=\"none\" />\n";

    Myfile << text;

    std::srand(std::time(nullptr));
    for (int start=0;start<=n;start++){
        double x = random();
        double y = random();
        if((x - 250) * (x - 250) + (y - 250) * (y - 250) <= 250 * 250){
    Myfile << "<circle cx=\""<<x<<"\" cy=\""<<y<<"\" r=\"10\" fill=\"#00FFFF\" />\n";
    }
    }

    Myfile << "</svg>";
}
