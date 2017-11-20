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
    float *base, *top;
    int stacksize;
} SqStack1;

// 定义所使用的常量集
const int STACK_INIT_SIZE = 100;
const int STACK_INCREMENT = 10;
/* 用于比较符号优先级的全局二维数组 */
const char priority[7][7] = {
        {'>', '>', '<', '<', '<', '>', '>'}, // +
        {'>', '>', '<', '<', '<', '>', '>'}, // -
        {'>', '>', '>', '>', '<', '>', '>'}, // *
        {'>', '>', '>', '>', '<', '>', '>'}, // /
        {'<', '<', '<', '<', '<', '=', ' '}, // (
        {'>', '>', '>', '>', ' ', '>', '>'}, // )
        {'<', '<', '<', '<', '<', ' ', '='}  // #
};
// 与比较符号优先级二维数组对应的操作符全集
char OP[] = {'+', '-', '*', '/', '(', ')', '#'};

// 函数预定义
// 操作结果：初始化运算符栈
void InitStack(SqStack &s);

// 操作结果：得到运算符栈的栈顶元素
char GetTop(SqStack &s);

// 操作结果：对运算符栈进行压栈操作
void Push(SqStack &s, char e);

// 操作结果：对运算符栈进行出栈操作
void Pop(SqStack &s, char &e);

// 操作结果：初始化运算数栈
void InitStack1(SqStack1 &s);

// 操作结果：得到运算数栈的栈顶元素
float GetTop1(SqStack1 &s);

// 操作结果：对运算数栈进行压栈操作
void Push1(SqStack1 &s, float e);

// 操作结果：对运算数栈进行出栈操作
void Pop1(SqStack1 &s, float &e);

// 操作结果：判断一个字符是否是数字
bool isNumber(char c);

// 操作结果：计算中缀表达式的值
float MidExpression_Eval(char Express[]);

// 操作结果：计算表达式axb，并返回结果
float Operate(float a, char x, float b);

// 操作结果：获取操作符在全集操作符中的位置，并返回下标，此函数为辅助函数
int getIndex(char ops[], char e);


char Precede(char top, char c);
// 操作结果：获取算符优先级关系，并返回具体优先级符号，如'<','>'等


int main() {
    char express[STACK_INIT_SIZE] = {}; // 存储中缀表达式
    float result;
    cout << "输入中缀运算式: ";
    cin >> express;
    express[strlen(express)] = '#';
    result = MidExpression_Eval(express);
    express[strlen(express) - 1] = '\0';
    cout << express << '=' << result << endl;
    return 0;
}

// 函数实现
void InitStack(SqStack &s) { // 初始化运算符栈
    s.base = (char *) malloc(STACK_INIT_SIZE * sizeof(char));
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
}

char GetTop(SqStack &s) { // 获取运算符栈的栈顶元素
    if (s.top != s.base) {
        return *(s.top - 1);
    }
    return '!'; // 若出错则返回感叹号
}

void Push(SqStack &s, char e) { // 将运算符压入运算符栈
    if (s.top - s.base >= s.stacksize) {
        s.base = (char *) realloc(s.base, (s.stacksize + STACK_INCREMENT) * sizeof(char));
        s.top = s.base + s.stacksize;
        s.stacksize += STACK_INCREMENT;
    }
    *s.top++ = e;
}

void Pop(SqStack &s, char &e) { // 将运算符栈顶元素出栈
    if (s.top != s.base)
        e = *--s.top;
}

void InitStack1(SqStack1 &s) { // 初始化运算符栈
    s.base = (float *) malloc(STACK_INIT_SIZE * sizeof(float));
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
}

float GetTop1(SqStack1 &s) { // 获取运算数栈的栈顶元素
    if (s.top != s.base) {
        return *(s.top - 1);
    }
    return 0; // 出错则返回0
}

void Push1(SqStack1 &s, float e) { // 将运算数压入运算数栈
    if (s.top - s.base >= s.stacksize) {
        s.base = (float *) realloc(s.base, (s.stacksize + STACK_INCREMENT) * sizeof(float));
        s.top = s.base + s.stacksize;
        s.stacksize += STACK_INCREMENT;
    }
    *s.top++ = e;
}

void Pop1(SqStack1 &s, float &e) { // 将运算数栈顶元素出栈
    if (s.top != s.base)
        e = *--s.top;
}

bool isNumber(char c) {
    return (c >= '0' && c <= '9');
}

float Operate(float a, char x, float b) {
    float result = 0;
    switch (x) {
        case '+':
            result = a + b;
            break;
        case '*':
            result = a * b;
            break;
        case '-':
            result = a - b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            break;
    }
    return result;
}

int getIndex(char ops[], char e) {
    for (int i = 0; i < 7; i++) {
        if (e == ops[i]) {
            return i;
        }
    }
    return -1;
}

char Precede(char top, char c) {
    return priority[getIndex(OP, top)][getIndex(OP, c)];
}


float MidExpression_Eval(char express[]) {
    SqStack Op_char; // 声明运算符栈
    SqStack1 Op_float; // 声明运算数栈
    int i = 0; // 记录表达式读取位置
    char theChar; // 记录目前读取表达式的字符

    InitStack(Op_char); // 初始化运算符栈
    Push(Op_char, '#'); // 将最低优先级的'#'起始符压入操作数栈

    InitStack1(Op_float); // 初始化运算数栈
    theChar = express[i]; // 拿到表达式的第一个值
    while (theChar != '#' || GetTop(Op_char) != '#') {
        char numbers[40]; // 用于存储多位数字
        int j = 0; // 用于存储数字数组下标，方便增加位数, 同时也可以记录数字数组的长度
        while (isNumber(theChar) || theChar == '.') { // 若是数字或小数点，则循环读取
            numbers[j] = theChar;
            i++;
            j++;
            theChar = express[i];
        }

        if (j > 0) { // 若数字数组长度大于0，则2循环数组求多位数字的值并压入运算数栈
            float sum = 0;
            int dot = getIndex(numbers, '.'); // 若无小数点则返回-1
            for (int k = 0; k < j; k++) {
                if (numbers[k] == '.') {
                    continue;
                }
                if (dot != -1) {
                    if (k < dot) {
                        sum += (numbers[k] - '0') * pow(10, dot - k - 1); // 将字符转换成对应的多位数字
                    } else if (k > dot) { // 若没有小数点，这个块不执行
                        sum += (numbers[k] - '0') * pow(10, dot - k);
                    }
                } else {
                    sum += (numbers[k] - '0') * pow(10, j - 1 - k);
                }

            }
            Push1(Op_float, sum);
        } else {
            switch (Precede(GetTop(Op_char), theChar)) {
                case '<': // 栈顶元素优先级比此时的取值更低
                    Push(Op_char, theChar); // 压入运算符栈
                    theChar = express[++i]; // 使读取的位置后移，并取到下一个字符
                    break;
                case '=':
                    char x;
                    Pop(Op_char, x);
                    theChar = express[++i];
                    break;
                case '>':
                    char theta;
                    float a, b;
                    Pop(Op_char, theta);
                    Pop1(Op_float, b);
                    Pop1(Op_float, a);
                    Push1(Op_float, Operate(a, theta, b));
                default:
                    break;
            }
        }
    }
    return GetTop1(Op_float);
}