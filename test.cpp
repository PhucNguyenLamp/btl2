#include<bits/stdc++.h> 
using namespace std;
class Car {
public:
    // Constructor with parameters
    Car(std::string make, std::string model, int year) {
        this->make = make;
        this->model = model;
        this->year = year;
        std::cout << "Car object created with make: " << make << ", model: " << model << ", year: " << year << std::endl;
    }

private:
    std::string make;
    std::string model;
    int year;
};

int main() {
    // Creating a Car object and calling the constructor
    Car myCar("Toyota", "Camry", 2022);

    return 0;
}
