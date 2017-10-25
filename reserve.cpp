#include <iostream>
#include <string>
using namespace std;

int main()
{
  string a[10000];
  string b;
  int n = 1;
  while (cin >> b)
  {
    n++;
    a[n] = b;
  }
  for (int i = n; i > 0; i--)
  {
    cout << a[i] << " ";
  }
  return 0;
}