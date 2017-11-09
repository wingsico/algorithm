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

void get_fail(Students stu[], int line, int num);
void get_pass(Students stu[], int line, int num);
Students get_student_msg(Students stu[], int len);
int stu_menu();

int main()
{
  struct Students stu[4], *p;
  struct Grades *q;
  int choice;
  int t = 1;

  for (int i = 0; i < 4; i++)
  {
    p = &stu[i];
    q = &(p->grades);
    cout << "输入第"<< i + 1 << "位同学的姓名和学号(共4位)：" << endl;
    getline(cin, p->name);
    getline(cin, p->id);
    cout << "分别输入数学、英语、音乐、计算机的成绩：" << endl;
    cin >> q->Math >> q->English >> q->Music >> q->Computer;
    q->average = (q->Math + q->English + q->Music + q->Computer) / 4.0;
    cin.get();
  }

  for (int i = 0; i < 4;i++) {
    cout << "第" << i + 1 << "位同学的信息: ";
    cout << "姓名: " << stu[i].name << " "
         << "学号: " << stu[i].id << " "
         << "数学: " << stu[i].grades.Math << " "
         << "英语: " << stu[i].grades.English << " "
         << "音乐: " << stu[i].grades.Music << " "
         << "计算机: " << stu[i].grades.Computer << " "
         << "平均成绩: " << stu[i].grades.average << endl;
  }

  while (t) {
    choice = stu_menu();
    switch (choice)
    {
    case 1:
      get_fail(stu, 60, 4);
      break;
    case 2:
      get_pass(stu, 90, 4);
      break;
    case 3:
      get_student_msg(stu, 4);
      break;
    case 0:
      t = 0;
      break;
    default:
      break;
    };
  }

  return 0;
}

int stu_menu() {
  int choice;
  do
  {
    cout << "\n你可以进行以下操作：" << endl
         << "1. 列出未通过考试的同学的姓名;" << endl
         << "2. 列出90分以上的同学的姓名;" << endl
         << "3. 通过学号查询某个同学的信息;" << endl
         << "0. 离开" << endl;

    cout << "输入您的操作: ";
    cin >> choice;
  } while (choice < 0 || choice > 4);

  return choice;
}
void get_fail(Students stu[], int line, int num) {
  // 依据平均分
  cout << "平均成绩未通过的同学有: ";
  for (int i = 0; i < num; i++) {
    if (stu[i].grades.average < line) {
      cout << stu[i].name << " ";
    }
  }

  // 依据各科成绩
  cout << "\n数学未通过的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.Math < line)
    {
      cout << stu[i].name << " ";
    }
  }

  // 依据各科成绩
  cout << "\n英语未通过的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.English < line)
    {
      cout << stu[i].name << " ";
    }
  }

  // 依据各科成绩
  cout << "\n音乐未通过的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.Music < line)
    {
      cout << stu[i].name << " ";
    }
  }

  // 依据各科成绩
  cout << "\n计算机未通过的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.Computer < line)
    {
      cout << stu[i].name << " ";
    }
  }
}

void get_pass(Students stu[], int line, int num) {
  // 根据平均成绩
  cout << "平均成绩90分以上的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.average >= line)
    {
      cout << stu[i].name << " ";
    }
  }

  // 依据各科成绩
  cout << "\n数学90分以上的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.Math >= line)
    {
      cout << stu[i].name << " ";
    }
  }

  // 依据各科成绩
  cout << "\n英语90分以上的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.English >= line)
    {
      cout << stu[i].name << " ";
    }
  }

  // 依据各科成绩
  cout << "\n音乐90分以上的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.Music >= line)
    {
      cout << stu[i].name << " ";
    }
  }

  // 依据各科成绩
  cout << "\n计算机90分以上的同学有: ";
  for (int i = 0; i < num; i++)
  {
    if (stu[i].grades.Computer >= 90)
    {
      cout << stu[i].name << " ";
    }
  }
}

Students get_student_msg(Students stu[], int len)
{
  int i, n = 0;
  string id;
  cin.get();
  cout << "输入你要查询的学生的学号：";
  getline(cin, id);
  for (i = 0; i < len; i++)
  {
    if (id.compare(stu[i].id) == 0)
    {
      n++;
      cout << "已查询到该学生!" << endl;
      cout << "姓名: " << stu[i].name << endl
           << "学号: " << stu[i].id << endl
           << "数学成绩: " << stu[i].grades.Math << endl
           << "英语成绩: " << stu[i].grades.English << endl
           << "音乐成绩: " << stu[i].grades.Music << endl
           << "计算机成绩: " << stu[i].grades.Computer << endl
           << "平均成绩: " << stu[i].grades.average << endl;
    }
  }
  if (n == 0)
    cout << "\t该学号不存在!" << endl;
  return stu[n];
}