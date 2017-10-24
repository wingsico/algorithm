#include <cstdio>
#include <set>
using namespace std;

int main() {
  set<int> s;
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    s.insert(m);
  }
  printf("%d", s.size());
  return 0;
}