#include <iostream>
using namespace std;

enum Season {
    SPRING = 1,
    SUMMER = 2,
    FALL = 3,
    WINTER = 4
};

int main() {
    Season currentSeason = SPRING;

    if (currentSeason == 1)
    {
        std::cout << "It's spring!" << endl;
    }
    
    return 0;
}
