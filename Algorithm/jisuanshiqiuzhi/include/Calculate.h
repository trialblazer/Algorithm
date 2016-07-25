#ifndef CALCULATE_H
#define CALCULATE_H

#define Max 50  /// 用户输入表达式的上限
#include "Stack.h"   /// 里面包含栈的定义


class Calculate {
    char ar[Max];           /// 保存用户输入的表达式
    int pr[Max/2+1];        /// 保存临时操作符的优先级
    int len;                /// 用户输入表达式的长度
    int size;               /// 数组pr的长度
    bool tag;               /// 为false表示当前字符不在括号内，否则在
    Stack<char> a;          /// 保存后续算数表达式
    Stack<char> b;          /// 辅助栈

private:
    void exchange();        /// 将用户输入的算数表达式转化成后序表达式存于a中
    int priority(char data);/// 获取data的优先级，t表示data是否在括号内

public:
    void calculate();       /// 计算表达式

};

#endif // CALCULATE_H
