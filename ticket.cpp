#include <iostream>
using namespace std;

int main() {
  int price, now_price, res;
  double t;
  cin >> price >> t;
  now_price = price * (t / 10.0);
  res = now_price % 10;
  now_price = res > 4 ? now_price + 10 - res : now_price - res;
  cout << now_price << endl;
  return 0;
}