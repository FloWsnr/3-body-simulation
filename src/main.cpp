//using namespace std;

#include <string>
#include <array>
#include <iostream>

int main() {
    // Your code here
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct Mass {
    std::string name;
    double mass;
    std::array<double, 3> position;
    std::array<double, 3> velocity;
    std::array<double, 3> acceleration;
};
