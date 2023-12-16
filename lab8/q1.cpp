#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class Hero {
protected:
    string Name;

public:
    Hero() {
        Name = "Nameless hero";
    }

    virtual ~Hero() {}

    string name() const {
        return Name;
    }

    virtual string greeting() const = 0;

    virtual void read(istream& is) {
        is >> Name;
    }

    virtual ostream& print(ostream& os) const {
        return os << Name;
    }
};

class Warrior : public Hero {
public:
    Warrior() {
        Name = "Nameless Warrior";
    }

    Warrior(string aname) {
        Name = aname;
    }

    string greeting() const override {
        return "I'm " + Name + ", I will save the world.";
    }

    void read(istream& is) override {
        char c;
        is >> c >> Name;
    }

    ostream& print(ostream& os) const override {
        return os << Name << ": Warrior";
    }
};

class Fighter : public Hero {
public:
    Fighter() {
        Name = "Nameless Fighter";
    }

    Fighter(string aname) {
        Name = aname;
    }

    string greeting() const override {
        return "I'm " + Name + ", my fists will crush the evil.";
    }

    void read(istream& is) override {
        char c;
        is >> c >> Name;
    }

    ostream& print(ostream& os) const override {
        return os << Name << ": Fighter";
    }
};

class Mage : public Hero {
public:
    Mage() {
        Name = "Nameless Mage";
    }

    Mage(string aname) {
        Name = aname;
    }

    string greeting() const override {
        return "I'm " + Name + ", I can cook with fire magic.";
    }

    void read(istream& is) override {
        char c;
        is >> c >> Name;
    }

    ostream& print(ostream& os) const override {
        return os << Name << ": Mage";
    }
};
int main() {

    // Warrior warrior1("Cecil"); 
    // Fighter fighter1;
    // Mage mage1("Vivi");
    // const Hero& hero1 = warrior1; 
    // const Hero& hero2 = fighter1; 
    // const Hero& hero3 = mage1;
    // // "Cecil"
    // auto name = hero1.name(); // "Nameless Fighter" name = hero2.name();
    // // "Vivi"
    // name = hero3.name();
    // std::cout << hero1.greeting() << std::endl; // "I'm Nameless Fighter, I will crush the evil."
    // std::cout << hero2.greeting() << std::endl; // "I'm Vivi, I can cook with fire magic."
    // std::cout << hero3.greeting() << std::endl;

    // istringstream iss("W Cecil F Ryu M Vivi"); 
    // auto hero1 = make_unique<Warrior>(); 
    // auto hero2 = make_unique<Fighter>(); 
    // auto hero3 = make_unique<Mage>();

    // hero1->read(iss);
    // hero2->read(iss);
    // hero3->read(iss);

    // // [Cecil: Warrior] 
    // hero1->print(cout) << endl; 
    // // [Ryu: Fighter] 
    // hero2->print(cout) << endl; 
    // // [Vivi: Mage] 
    // hero3->print(cout) << endl;

    vector<unique_ptr<Hero>> heroes;
    string input;

    while (true) {
        cout << "Enter hero name and type ('quit' to exit): ";
        getline(cin, input);
        if (input == "quit") {
            break;
        }

        stringstream ss(input);
        char heroType;
        string heroName;
        ss >> heroType >> heroName;

        unique_ptr<Hero> hero;
        if (heroType == 'W') {
            hero = make_unique<Warrior>(heroName);
        }
        else if (heroType == 'F') {
            hero = make_unique<Fighter>(heroName);
        }
        else if (heroType == 'M') {
            hero = make_unique<Mage>(heroName);
        }
        else {
            cout << "Unknown hero type '" << heroType << "'.\n";
            continue;
        }

        heroes.push_back(move(hero));
    }

    sort(heroes.begin(), heroes.end(), [](const unique_ptr<Hero>& a, const unique_ptr<Hero>& b) {
        return a->name() < b->name();
    });

    cout << "\nSorted list of heroes:\n";
    for (const auto& hero : heroes) {
        hero->print(cout) << endl;
    }

    return 0;
}