#include <time.h>
#include <iostream>

double random(){
    double random;
    srand( (unsigned)time( NULL ) );
    random = (float) rand()/RAND_MAX;
    return random;
}



int main()
{

    int n;

    std::cout<<"Type in random number: ";
    std::cin>>n;
    double sum;
    for (int i = 0; i < n; i++) {
    
    sum += (0.5 - random()) * (0.5 - random());
  }
    double mse = sum/ n;

    std::cout<<mse;
    
    return 0;
}