#include <iostream>
#include <cmath>
using namespace std;

int main() {
  float a, b;
  cin >> a >> b;
  if (abs(a - b) < 1e-8) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}