#include <iostream>
using namespace std;

int& getNumber() {
  static int number = 42; // Static variable to hold the value
  return number;
}

int main() {
int a=1;
const int &r=a;
a++;
cout << r << endl << a;
  return 0;
}
