#include <iostream>
using namespace std;

float add (float a, float b){
  return a+b;
}
float sub (float a, float b){
  return a-b;
}
float mul (float a, float b){
  return a*b;
}
float div (float a, float b){
  return a/b;
}

typedef float (*myfloat)(float, float);
int main(){
  myfloat list[] = {add, sub, mul, div};
  char opid[256];
  opid['+'] = 0;
  opid['-'] = 1;
  opid['*'] = 2;
  opid['/'] = 3;



  return 0;
}
