#include <iostream>
int main()
{

    int a = 5, b = 8, i, sum = 0;
    int ArrayS[5], *p;

    a = 10 + (2 * b + 7) % 10;
    b = 10 + (a + 5) % 10;

    ArrayS[0] = a;
    ArrayS[1] = b;

    for (i = 2; i < 5; i++)
    {
        ArrayS[i] = ArrayS[i - 1] + ArrayS[i - 2];
    }
    
    p = &ArrayS[4];
    
    sum = *p;
    
    // printf("\n %d", *p);
    for (i = 1; i < 5; i++)
    {
        p--;
        // printf(" + %d", *p);
        sum += *p;
    }
    printf(" = %d", sum);
}