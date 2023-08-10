#include <iostream>
using namespace std;

void call_by_value(int x) {
  cout << "Call by value" << endl;
  cout << "x: " << x << endl;
  x = 10;
}

void call_by_address(int *x) {
  cout << "Call by address" << endl;
  cout << "x: " << *x << endl;
  *x = 10;
}

void call_by_reference(int &x) {
  cout << "Call by reference" << endl;
  cout << "x: " << x << endl;
  x = 10;
}

int main() {
  // Call by value
  int x = 5;
  call_by_value(x);
  cout << "---" << endl;
  cout << "x: " << x << endl;
  cout << "====" << endl;

  // Call by address
  x = 5;
  call_by_address(&x);
  cout << "---" << endl;
  cout << "x: " << x << endl;
  cout << "====" << endl;

  // Call by reference
  x = 5;
  call_by_reference(x);
  cout << "---" << endl;
  cout << "x: " << x << endl;
  cout << "====" << endl;

  return 0;
}