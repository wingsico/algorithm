#include <iostream>
#include <string>
using namespace std;
#define N 4;
struct Grades
{
  int Math;
  int English;
  int Music;
  int Computer;
  double average;
};

struct Students {
  string name;
  string id;
  struct Grades grades;
};

int main() {
  struct Students stu[4], *p;
  struct Grades *q;

  for (int i = 0; i < 4; i++){
    p = &stu[i];
    q = &(p->grades);
    cout << "输入第"<< i + 1 << "位同学的姓名和学号(共4位)：" << endl;
    getline(cin, p->name);
    getline(cin, p->id);
    cout << "分别输入数学、英语、音乐、计算机的成绩：" << endl;
    cin >> q->Math >> q->English >> q->Music >> q->Computer;
    cin.get();
  }

  for (int i = 0; i < 4;i++) {
    cout << "姓名: " << stu[i].name << endl
         << "学号: " << stu[i].id << endl
         << "数学: " << stu[i].grades.Math << endl
         << "英语: " << stu[i].grades.English << endl
         << "音乐: " << stu[i].grades.Music << endl
         << "计算机: " << stu[i].grades.Computer << endl;
  }

  return 0;
}