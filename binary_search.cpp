#include <iostream>
using namespace std;

int binary_search(int, int);
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 30, 35, 55, 63, 77}, index;
  index = binary_search(arr, 55);
  cout << index << endl;
  return 0;
}

int binary_search(int arr[], int item) {
  int low = 0, high = arrLen(arr) - 1, mid, guess;
  while (low <= high) {
    mid = (low + high) / 2;
    guess = arr[mid];
    if (guess == item) {
      return mid;
    }
    if (guess > item) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return -1;
}

template <class T>
int arrLen(T& array) {
  return (sizeof(array) / sizeof(array[0]));
}