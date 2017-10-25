#include <iostream>
using namespace std;

int main()
{
  int n, numbers[100], i = 0;
  cin >> n;
  while(i < n) {
    cin >> numbers[i];
  }
  for (int i = 0, j = 1;i < n;i++) {
    while(j) {
      if(numbers[i] == numbers[j]) {
        delete numbers[j];
        
      }
    }
  }
    return 0;
}