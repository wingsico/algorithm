#include <iostream>
#include <cmath>
using namespace std;
// 定义栈类型
typedef struct /* 运算符栈 */
{
  char *base, *top;
  int stacksize;
} SqStack;
typedef struct /* 运算数栈 */
{
  int *base, *top;
  int stacksize;
} SqStack1;

// 定义所使用的常量集
const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;
/* 用于比较符号优先级的全局二维数组 */
const int priority[7][7] = { 
    {'>', '>', '<', '<', '<', '>', '>'}, // +
    {'>', '>', '<', '<', '<', '>', '>'}, // -
    {'>', '>', '>', '>', '<', '>', '>'}, // *
    {'>', '>', '>', '>', '<', '>', '>'}, // /
    {'<', '<', '<', '<', '<', '=', ' '}, // (
    {'>', '>', '>', '>', ' ', '>', '>'}, // )
    {'<', '<', '<', '<', '<', ' ', '='}  // #
};
// 与比较符号优先级二维数组对应的操作符全集
const char OP[] = {'+', '-', '*', '/', '(', ')', '#'};

// 函数预定义
void InitStack(SqStack *s);
// 操作结果：初始化运算符栈
char GetTop(SqStack *s);
// 操作结果：得到运算符栈的栈顶元素
void Push(SqStack *s, char e);
// 操作结果：对运算符栈进行压栈操作
void Pop(SqStack *s, char &e);
// 操作结果：对运算符栈进行出栈操作
void InitStack1(SqStack1 *s);
// 操作结果：初始化运算数栈
int GetTop1(SqStack1 *s);
// 操作结果：得到运算数栈的栈顶元素
void Push1(SqStack1 *s, char e);
// 操作结果：对运算数栈进行压栈操作
void Pop1(SqStack1 *s, char &e);
// 操作结果：对运算数栈进行出栈操作
bool IsNumber(char c);
// 操作结果：判断一个字符是否是数字
int MidExpression_Eval(char Express[]);
// 操作结果：计算中缀表达式的值
int Operate(int a, char x, int b);
// 操作结果：计算表达式axb，并返回结果
bool In(char ops[], char e);
// 操作结果：判断操作符是否合法，并返回判断结果
int getIndex(char ops[], char e);
// 操作结果：获取操作符在全集操作符中的位置，并返回下标，此函数为辅助函数
char Precede(char top, char c);
// 操作结果：获取算符优先级关系，并返回具体优先级符号，如'<','>'等


int main() {
  char express[STACK_INIT_SIZE]; // 存储中缀表达式
  cin << express;
  cout << express << '=' << MidExpression_Eval(express) << endl;
  return 0;
}

int MidExpression_Eval(char Express[]) {
  SqStack Op_char; // 声明运算符栈 
  SqStack1 Op_int; // 声明运算数栈
  int i = 0; // 记录表达式读取位置
  char theChar; // 记录目前读取表达式的字符

  InitStack(Op_char); // 初始化运算符栈
  Push(Op_char, '#'); // 将最低优先级的'#'起始符压入操作数栈

  InitStack1(Op_int); // 初始化运算数栈
  theChar = Express[i]; // 拿到表达式的第一个值

  while(theChar != '#' || GetTop(Op_char) != '#') {
    char numbers[10]; // 用于存储多位数字
    int j = 0; // 用于存储数字数组下标，方便增加位数, 同时也可以记录数字数组的长度

    while (isNumber(theChar)) { // 若是数字，则循环读取
      numbers[j] = theChar;
      i++;
      j++;
      theChar = Express[i];
    }

    if (j > 0) { // 若数字数组长度大于0，则循环数组求多位数字的值并压入运算数栈
      int sum = 0;
      for (int k = 0; k < j; k++) {
        sum += (numbers[k] - '0') * pow(10, j - 1 - k); // 将字符转换成对应的多位数字
      }
      Push1(Op_int, sum);
    } else {
      switch (Precede(GetTop(Op_char), theChar)) {
        case '<': // 栈顶元素优先级比此时的取值更低
          Push(Op_char, theChar); // 压入运算符栈
          theChar = Express[++i]; // 使读取的位置后移，并取到下一个字符
          break;
        case '=':
          char x;
          Pop(Op_char, x);
          theChar = Express[++i];
          break;
        case '>':
          char theta;
          int a, b;
          Pop(Op_char, theta);
          Pop1(Op_int, b);
          Pop1(Op_int, a);
          Push1(Op_int, Operate(a, theta, b));
        default:
          break;
      }
    }
  }
  return GetTop1(Op_int);
}

// 函数实现 
void InitStack(SqStack *s) { // 初始化运算符栈
  s.base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
  s.top = s.base;
  s.stacksize = STACK_INIT_SIZE;
}

char GetTop(SqStack *s) { // 获取运算符栈的栈顶元素
  if (s.top != s.base) {
    return *(s.top - 1);
  }
}

void Push(SqStack *s, char e) { // 将运算符压入运算符栈
  if (s.top - s.base >= s.stacksize)
  {
    s.base = (char *)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(char));
    s.top = s.base + s.stacksize;
    s.stacksize += STACKINCREMENT;
  }
  *s.top++ = e;
}

void Pop(SqStack *s, char &e) { // 将运算符栈顶元素出栈
  if (S.top != S.base)
    e = *--S.top;
}

void InitStack1(Sqstack1 *s)
{ // 初始化运算符栈
  s.base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
  s.top = s.base;
  s.stacksize = STACK_INIT_SIZE;
}

char GetTop1(SqStack1 *s)
{ // 获取运算符栈的栈顶元素
  if (s.top != s.base)
  {
    return *(s.top - 1);
  }
}

void Push1(SqStack1 *s, char e)
{ // 将运算符压入运算符栈
  if (s.top - s.base >= s.stacksize)
  {
    s.base = (char *)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(char));
    s.top = s.base + s.stacksize;
    s.stacksize += STACKINCREMENT;
  }
  *s.top++ = e;
}

void Pop1(SqStack1 *s, char &e)
{ // 将运算符栈顶元素出栈
  if (S.top != S.base)
    e = *--S.top;
}
