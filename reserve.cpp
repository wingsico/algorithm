#include <iostream>
#include <string>
using namespace std;

int main()
{
  char words[100];
  int len;
  char temp;
  gets(words);
  len = strlen(words) / sizeof(words[0]);
  cout << len << endl;
  for (int i = 0; i < len / 2; i++)
  {
    temp = words[i];
    words[i] = words[len - i - 1];
    words[len - i - 1] = temp;
  }
  cout << words;
  return 0;
}