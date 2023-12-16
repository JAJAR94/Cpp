#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Picture {
public:
    Picture(const std::vector<std::string>& rows) {
        _rows = rows;
        _width = 0;
        for (const auto& row : _rows) {
            if (row.size() > _width) {
                _width = row.size();
            }
        }
        _height = _rows.size();
    }

    int width() const {
        return _width;
    }

    int height() const {
        return _height;
    }

    void print() const {
        for (const auto& row : _rows) {
            std::cout << row << std::endl;
        }
    }

    void hflip() {
        for (auto& row : _rows) {
            while (row.size() < _width) {
                row.push_back(' ');
            }
            std::reverse(row.begin(), row.end());
        }
    }

    void vflip() {
        std::reverse(_rows.begin(), _rows.end());
    }

    void hcat(const Picture& other){
        
    }

private:
    std::vector<std::string> _rows;
    int _width;
    int _height;
};

int main() {
    std::vector<std::string> rows = {
        "  /\\",
        " /  \\",
        "/____\\",
        "\\    /",
        " \\  /",
        "  \\/"
    };

    std::vector<std::string> rows2 = {
        "  /\\",
        " /  \\",
        "/____\\"
    };

    std::vector<std::string> rows3 = {
        "\\    /",
        " \\  /",
        "  \\/" 
    };

    Picture picture(rows);
    std::cout << "Original picture:" << std::endl;
    picture.print();
    std::cout << "Width: " << picture.width() << std::endl;
    std::cout << "Height: " << picture.height() << std::endl;

    picture.hflip();
    std::cout << "Horizontally flipped picture:" << std::endl;
    picture.print();

    picture.vflip();
    std::cout << "Vertically flipped picture:" << std::endl;
    picture.print();

    return 0;
}