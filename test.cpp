#include <iostream>
using namespace std;

class Counter {
private:
  static int count; // Static data member to keep track of count
public:
  Counter() {
    count++; // Increment count when object is created
  }

  static int getCount() {
    return count; // Static function to get the count
  }
};

// Initialize static data member
int Counter::count = 0;

int main() {
  // Create objects of Counter class
  Counter obj1;
  Counter obj2;
  Counter obj3;

  // Call static function to get count of objects
  cout << "Number of objects created: " << Counter::getCount() << endl;

  return 0;
}




