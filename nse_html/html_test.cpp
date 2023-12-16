#include "nse/html.hpp"
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>
#include <variant>
#include <string>
using namespace std;

class Stream_writer: public nse::html::Writer {
public:
    void write(std::string_view msg) const override;
    void write(const Element& e, int lv = 0) const override;

    Stream_writer(std::ostream& o): os(o) {}
private:
    std::ostream& os;
};

void Stream_writer::write(std::string_view msg) const
{
    os << msg;
}

void Stream_writer::write(const Element& e, int lv) const
{
    e.write_to(*this, lv);
}


class Shape {
public:
    virtual double area() const = 0;
    virtual void read(std::istream& is) = 0;
    virtual void print(std::ostream& os) const = 0;
};

class Circle : public Shape {
public:
    Circle(double x = 50, double y = 50, double r = 10) : x(x), y(y), r(r) {}
    double area() const override {
        return 3.14159 * r * r;
    }
    void read(std::istream& is) override {
        is >> x >> y >> r;
    }
    void print(std::ostream& os) const override {
        os << "C " << x << " " << y << " " << r;
    }
private:
    double x;
    double y;
    double r;
};

class Rectangle : public Shape {
public:
    Rectangle(double x = 45, double y = 45, double w = 10, double h = 10) : x(x), y(y), w(w), h(h) {}
    double area() const override {
        return w * h;
    }
    void read(std::istream& is) override {
        is >> x >> y >> w >> h;
    }
    void print(std::ostream& os) const override {
        os << "R " << x << " " << y << " " << w << " " << h;
    }
private:
    double x;
    double y;
    double w;
    double h;
};


int main()
{   

    vector<unique_ptr<Shape>> shapes;
    string input;

   while (true) {
        cout << "Enter shape type and values ('quit' to exit): ";
        getline(cin, input);
        if (input == "quit") {
            break;
        }

        stringstream ss(input);
        char shapeType;
        int value1=0;
        int value2=0;
        int value3 = 0;
        int value4=0;
        ss >> shapeType >> value1 >> value2 >> value3;

        unique_ptr<Shape> shape;
        if (shapeType == 'R') {
            ss >> value4;
            shape = make_unique<Rectangle>(value1,value2,value3,value4);
        }
        else if (shapeType == 'C') {
            shape = make_unique<Circle>(value1,value2,value3);
        }
        else {
            cout << "Unknown hero type '" << shapeType << "'.\n";
            continue;
        }

        shapes.push_back(move(shape));
        using namespace nse::html;
    Stream_writer out(std::cout);
        
        string fx = to_string(value1);
        string fy = to_string(value2);
        string fr = to_string(shapes[0]->area());


        
        // auto e = Element("em", {t, Element("p", {t})});

        auto attrs = Attribute_map{
            {"id", "id001"},
            {"class", "class001"},
            {"enabled", true},
            {"selected", false}
        };


    Attribute_map circle_attr = {
        {"cx", fx},
        {"cy", fy},
        {"r", fr}
    };
    
    auto doc1 = Element("circle", circle_attr, {});
    auto doc = Element("svg", {doc1});


    out.write(doc);
    }

    sort(shapes.begin(), shapes.end(), [](const unique_ptr<Shape>& a, const unique_ptr<Shape>& b) {
        return a->area() < b->area();

        
    });
  

    

    return 0;

    }

    

