#include <iostream>
const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;
const int priority[7][7] = {
    {'>', '>', '<', '<', '<', '>', '>'}, // +
    {'>', '>', '<', '<', '<', '>', '>'}, // -
    {'>', '>', '>', '>', '<', '>', '>'}, // *
    {'>', '>', '>', '>', '<', '>', '>'}, // /
    {'<', '<', '<', '<', '<', '=', ' '}, // (
    {'>', '>', '>', '>', ' ', '>', '>'}, // )
    {'<', '<', '<', '<', '<', ' ', '='}  // #
};

/*用于比较符号优先级的全局二维数组*/
char OP[] = {'+', '-', '*', '/', '(', ')', '#'};
#define Status unsigned int
#define OK 1
#define ERROR 0

using namespace std;
typedef struct Sqstack
{
  char *base, *top;
  int stacksize;
} Sqstack0, Sqstack1; // 操作数栈1 ／ 运算符栈0

Status InitStack(Sqstack &S);
Status Push(Sqstack &S);
Status Pop(Sqstack &S);
char GetTop(Sqstack &S);
bool In(char ops[], char e);
char Precede(char top, char c);
char EvaluateExpression();
char Operate(char prev, char operator_, char next);

int main()
{
  cout << EvaluateExpression() << endl;
  return 0;
}

Status InitStack(Sqstack &S)
{
  S.base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
  return OK;
}

char GetTop(Sqstack &S)
{
  if (S.top == S.base)
    return ERROR;
  return *(S.top - 1);
}

Status Push(Sqstack &S, char e)
{
  if (S.top - S.base >= S.stacksize)
  {
    S.base = (char *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(char));
    S.top = S.base + S.stacksize;
    S.stacksize += STACKINCREMENT;
  }
  *S.top++ = e;
  return OK;
}

Status Pop(Sqstack &S, char &e)
{
  if (S.top == S.base)
    return ERROR;
  e = *--S.top;
  return OK;
}

bool In(char ops[], char e)
{
  int length = strlen(ops);
  for (int i = 0; i < length; i++)
  {
    if (e == ops[i])
    {
      return true;
    }
  }
  return false;
}

int getIndex(char ops[], char e)
{
  int len = strlen(ops);
  for (int i = 0; i < len; i++)
  {
    if (e == ops[i])
    {
      return i;
    }
  }
  return -1;
}

char Precede(char top, char c)
{
  return priority[getIndex(OP, top)][getIndex(OP, c)];
}


char Operate(char prev, char operator_, char next)
{
  int p = prev - '0', n = next - '0';
  char result;
  switch (operator_)
  {
  case '+':
    result = p + n + '0';
    break;
  case '*':
    result = p * n + '0';
    break;
  case '-':
    result = p - n + '0';
    break;
  case '/':
    result = p / n + '0';
    break;
  }
  return result;
}

char EvaluateExpression()
{
  char c;
  Sqstack0 OPTR;
  Sqstack1 OPND;
  InitStack(OPTR);
  Push(OPTR, '#');
  InitStack(OPND);
  c = getchar();
  
  while (c != '#' || GetTop(OPTR) != '#')
  {
    if (!In(OP, c))
    {
      Push(OPND, c);
      c = getchar();
    }
    else
    {
      switch (Precede(GetTop(OPTR), c))
      {
      case '<': // 优先级低
        Push(OPTR, c);
        c = getchar();
        break;
      case '=':
        char x;
        Pop(OPTR, x);
        c = getchar();
        break;
      case '>':
        char theta, a, b;
        Pop(OPTR, theta);
        Pop(OPND, b);
        Pop(OPND, a);
        Push(OPND, Operate(a, theta, b));
        break;
      }
    }
  }
  return GetTop(OPND);
}
