#include <iostream>
#include <iomanip>

int main(){
    double celcius;
    std::cout<< "Fahr" << "  " << "Celcius" << std::endl;
    for (int f = 300;f>=0;f-=20){
        
        celcius = (f-32) * 5.0 / 9.0;
        std::cout << std::fixed;
        std::cout << std::setprecision(1);
        std::cout << f << "     " << celcius << std::endl;
    }
    return 0;
}