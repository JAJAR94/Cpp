#include <iostream>
#include <vector>



class Point {
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

class Poly_line {
private:
    std::vector<Point> points;

public:
    Poly_line() {}

    Poly_line(const std::vector<Point>& points) : points(points) {}

    void add_point(int x, int y) {
        points.emplace_back(x, y);
    }

    std::vector<Point> get_points() const {
        return points;
    }

    friend std::ostream& operator<<(std::ostream& os, const Poly_line& poly) {
        os << "  <polyline fill=\"none\" stroke=\"black\" \n    points=\"";
        for (const auto& point : poly.points) {
            os << point.x << "," << point.y << " ";
        }
        os << "\"" << "\n";
        return os;
    }

    friend std::ostream& gen_svg(std::ostream& os, const Poly_line& poly) {
        os << "<svg width=\"200\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">";
        os << "\n";
        os << poly;
        os << "  />\n</svg>\n";
        return os;
    }
};

int main() {
    Poly_line poly;
    poly.add_point(10, 10);
    poly.add_point(190, 20);
    poly.add_point(180, 180);
    poly.add_point(80, 110);
    poly.add_point(10, 10);
    poly.add_point(90, 0);
    poly.add_point(5, 50);
    gen_svg(std::cout, poly); 
    

    return 0;
}