#include <iostream>
#include <map>
#include <string>
using std::string;

template<typename T>
class Datastore {
private:
    std::map<string, T> data;

public:
    void set(string key, T value) {
        data[key] = value;
    }

    T* get(string key) {
        auto it = data.find(key);
        if (it != data.end()) {
            return &(it->second);
        } else {
            return nullptr;
        }
    }

    T* add(string key1, string key2) {
        auto it1 = data.find(key1);
        auto it2 = data.find(key2);
        if (it1 != data.end() && it2 != data.end()) {
            T& value1 = it1->second;
            T& value2 = it2->second;
            T result = value1 + value2;
            data[key1] = result;
            return &(data[key1]);
        } else {
            return nullptr;
        }
    }
};

int main() {
    Datastore<double> d;

    while (true) {
        string function, key, key1, key2;
        double value;
        std::cout << "\n" << "get/set" << "\n";
        std::cin >> function;

        if (function == "set") {
            std::cout << "key value";
            std::cin >> key >> value;
            d.set(key, value);
        } else if (function == "get") {
            std::cout << "Key" << "\n";
            std::cin >> key;
            double* result = d.get(key);
            if (result == nullptr) {
                std::cout << "<N/A>" << "\n";
            } else {
                std::cout << key << ": " << *result << "\n";
            }
        } else if (function == "add") {
            std::cout << "key key" << "\n";
            std::cin >> key1 >> key2;
            double* result = d.add(key1, key2);
            if (result == nullptr) {
                std::cout << key1 << "+" << key2 << ": <N/A>" << "\n";
            } else {
                std::cout << key1 << "+" << key2 << ": " << *result << "\n";
            }
        }
    }

    return 0;
}
