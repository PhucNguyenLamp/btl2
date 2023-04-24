///main.h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

class Events{
    private:
    int xinchao;
    int *events;
    public:
    Events(){
        xinchao = 1;
        events = &xinchao;
        cout << events;
    }
    ~Events(){
        delete events;
        events = nullptr;
        cout << events;

    }
};
int main(){
    Events *events = new Events();
    return 0;
}