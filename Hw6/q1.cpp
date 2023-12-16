#include <iostream>

void replace(char *s,char c1, char c2){
    char* letter = s;
    while (*letter!='\0'){
        if (*letter == c1){
            *letter= c2;
        }
        letter++;
    }
}

void inverse_numbers(double* v,size_t n){
    for(int i=0; i<n;i++){
        v[i]*=-1;
    }
}

char *encode_hex(const char *s)
{
    size_t size = 0;
    while (s[size] != '\0')
    {
        size++;
    }

    char *hex = new char[size * 2 + 1];
    int count = 0;
    while (*s != '\0')
    {
        int ascii;

        ascii = (int)(*s);
        char t = ascii / 16 + '0';
        int m = ascii % 16;

        char char_m[1];
        if (m >= 10)
        {
            switch (m)
            {
            case 10:
                char_m[0] = 'A';
                break;
            case 11:
                char_m[0] = 'B';
                break;
            case 12:
                char_m[0] = 'C';
                break;
            case 13:
                char_m[0] = 'D';
                break;
            case 14:
                char_m[0] = 'E';
                break;
            case 15:
                char_m[0] = 'F';
                break;
            }
        }
        else
        {
            char_m[0] = m + '0';
        }

        hex[count] = t;
        hex[count + 1] = char_m[0];

        count += 2;
        s++;
    }
    hex[count] = '\0';
    return hex;
}

int main() {
    char s1[] ="Hello world!";
    double v[]={6,-9,-6,9};
    char s2[]="Hello, world!";
    
    std::cout<<"Output for 1.1"<<'\n';
    inverse_numbers(v,4);
    double *p = v;
    for (int i=0;i<4;i++){
        std::cout<<*(p+i);
    }
    std::cout<<'\n';
    std::cout<<"Output for 1.2"<<'\n';
    replace(s1,'l','a');
    std::cout<<s1<<'\n';
    std::cout<<"Output for 1.3"<<'\n';
    std::cout<<encode_hex(s2);

    return 0;
}
