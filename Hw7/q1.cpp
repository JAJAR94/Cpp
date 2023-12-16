#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

struct Person
{
    string name;
    int age;
};

void  name_ascending(vector<Person> &person){
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < person.size() - 1; i++)
        {
            if (person[i].name > person[i + 1].name)
            {
                sorted = false;
                Person temp = person[i];
                person[i] = person[i + 1];
                person[i + 1] = temp;
            }
        }
    }
}

void  name_decending(vector<Person> &person){
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < person.size() - 1; i++)
        {
            if (person[i].name < person[i + 1].name)
            {
                sorted = false;
                Person temp = person[i];
                person[i] = person[i + 1];
                person[i + 1] = temp;
            }
        }
    }
}

void  age_ascending(vector<Person> &person){
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < person.size() - 1; i++)
        {
            if (person[i].age > person[i + 1].age)
            {
                sorted = false;
                Person temp = person[i];
                person[i] = person[i + 1];
                person[i + 1] = temp;
            }
        }
    }
}

void  age_dscending(vector<Person> &person){
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < person.size() - 1; i++)
        {
            if (person[i].age < person[i + 1].age)
            {
                sorted = false;
                Person temp = person[i];
                person[i] = person[i + 1];
                person[i + 1] = temp;
            }
        }
    }
}

vector<Person> combine_fields(vector<string> names, vector<int> ages){
    vector<Person> newvec;
    for (int i = 0; i <= names.size() - 1; i++){
        Person p;
        p.name = names[i];
        p.age = ages[i];
        newvec.push_back(p);
    }
    return newvec;
}

void extract_names(vector<Person> &person_list){
    
    for (int i = 0; i <= person_list.size() - 1; i++){
        std::cout<<person_list[i].name<<std::endl;
}
}

void extract_ages(vector<Person> &person_list){
    int size=0;
    for (Person element: person_list)
        size++;
    for (int i = 0; i <= size - 1; i++){
        std::cout<<person_list[i].age<<std::endl;
}
}

int main() {

    vector<string> n = {"a","b","c","d"};
    vector<int> a = {17,28,19,20};
    vector<Person> personlist = combine_fields(n,a);
    name_ascending(personlist);
    age_ascending(personlist);
    extract_names(personlist);
    extract_ages(personlist);
}
