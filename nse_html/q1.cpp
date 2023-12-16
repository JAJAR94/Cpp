#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class Hero
{
protected:
    string Name;

public:
    Hero()
    {
        Name = "Nameless hero";
    }

    virtual ~Hero() {}

    string name() const
    {
        return Name;
    }

    virtual string greeting() const = 0;

    virtual ostream &print(ostream &os) const
    {
        return os << Name;
    }


};

class Warrior : public Hero
{
public:
    Warrior()
    {
        Name = "Nameless Warrior";
    }

    Warrior(string aname)
    {
        Name = aname;
    }

    string greeting() const override
    {
        return "I'm " + Name + ", I will save the world.";
    }

    ostream &print(ostream &os) const override
    {
        return os << Name << ": Warrior";
    }
};

class Fighter : public Hero
{
public:
    Fighter()
    {
        Name = "Nameless Fighter";
    }

    Fighter(string aname)
    {
        Name = aname;
    }

    string greeting() const override
    {
        return "I'm " + Name + ", my fists will crush the evil.";
    }

    ostream &print(ostream &os) const override
    {
        return os << Name << ": Fighter";
    }
};

class Mage : public Hero
{
public:
    Mage()
    {
        Name = "Nameless Mage";
    }

    Mage(string aname)
    {
        Name = aname;
    }

    string greeting() const override
    {
        return "I'm " + Name + ", I can cook with fire magic.";
    }

    ostream &print(ostream &os) const override
    {
        return os << Name << ": Mage";
    }
};
int main()
{

    using Hero_ptr = std::unique_ptr<Hero>;

    vector<Hero_ptr> vec;

    vec.push_back(std::make_unique<Warrior>("Cecil"));
    vec.push_back(std::make_unique<Fighter>());
    vec.push_back(std::make_unique<Mage>("Vivi"));

    

    std::cout << "<table>" << std::endl;
    for(auto &v: vec){
        std::cout << "<tr>" << " <td>"<< v->name() << "</td>" << " <td>"<< v->greeting() << "</td>"<< " </tr>" << std::endl;
    }
    std::cout << "</table>";

    return 0;
}