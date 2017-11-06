#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
typedef struct LData {
  string name;
  string id;
  double Math;
  double English;
  double Music;
  double Computer;
  double average;
} LData;

typedef struct LNode {
  struct LData data;
  struct LNode *next;
} LNode, *LinkList;

void Create_List(LinkList &L, int n);
void Get_Name_of_Grades(LinkList &L, int Score_Line, bool compare);

int main () {
  LNode L;
  LNode *p = &L;
  Create_List(p, 4);
  Get_Name_of_Grades(p, 60, false);
  Get_Name_of_Grades(p, 90, true);
  return 0;
}

void Create_List(LinkList &L, int n) {
  LNode *p, *q;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  for (int i = 0; i < n; i++) {
    p = (LinkList)malloc(sizeof(LNode));
    cout << "Input No." << i+1 << " student's name and cardId: " << endl;
    cin.get();
    getline(cin, p->data.name);
    getline(cin, p->data.id);
    cout << "Input the student's scores about Math, English, Music, Computer: " << endl;
    cin >> p->data.Math >> p->data.English >> p->data.Music >> p->data.Computer;
    p->data.average = (p->data.Computer + p->data.English + p->data.Math + p->data.Music) / 4;
    q = L->next;
    L->next = p;
    p->next = q;
  }
}

void Get_Name_of_Grades(LinkList &L, int Score_Line, bool compare) {
  LNode *p;
  p = L->next;
  char sign[1];
  sign[0] = compare ? '>' : '<';
  cout << "students of scores " << sign[0] << ' ' << Score_Line << ": ";
  while(p != NULL) {
    if (p->data.average - Score_Line > 0 == compare) {
      cout << p->data.name << " ";
    }
    p = p->next;
  }
  cout << endl;
}
