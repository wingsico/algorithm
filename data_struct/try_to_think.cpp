#include <iostream>
#include <stdlib.h>
#include <time.h>
const int N = 100;
using namespace std;

void Initial_List(int List[]);
void Find_Max(int List[]);

int main()
{
  int List[N];
  Initial_List(List);
  Find_Max(List);
  return 0;
}

void Initial_List(int List[]) {
  srand((unsigned)time(NULL));

  for (int i = 0; i < N; i++) {
    List[i] = rand() % 500 + 1;
    cout << List[i] << " ";
  }
}

void Find_Max(int List[]) {
  int max_indexs[N];
  int number = 0;
  int max_value = List[0];
  for (int i = 0; i < N; i++)
  {
    if (List[i] > max_value) {
      // 清除数组
      memset(max_indexs, 0, N);
      number = 0;

      max_value = List[i];
      max_indexs[number++] = i;
      continue;
    }

    if (List[i] == max_value) {
      max_indexs[number++] = i;
    }
  };

  cout << "\nThe Max Value is: " << max_value << endl;
  cout << "The Max Value's Indexs are: ";
  for (int j = 0; j < number; j++)
  {
    cout << max_indexs[j] << (j == number ? "" : " ");
  }
  cout << endl;
}
