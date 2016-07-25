#ifndef CALCULATE_H
#define CALCULATE_H

#define Max 50  /// �û�������ʽ������
#include "Stack.h"   /// �������ջ�Ķ���


class Calculate {
    char ar[Max];           /// �����û�����ı��ʽ
    int pr[Max/2+1];        /// ������ʱ�����������ȼ�
    int len;                /// �û�������ʽ�ĳ���
    int size;               /// ����pr�ĳ���
    bool tag;               /// Ϊfalse��ʾ��ǰ�ַ����������ڣ�������
    Stack<char> a;          /// ��������������ʽ
    Stack<char> b;          /// ����ջ

private:
    void exchange();        /// ���û�������������ʽת���ɺ�����ʽ����a��
    int priority(char data);/// ��ȡdata�����ȼ���t��ʾdata�Ƿ���������

public:
    void calculate();       /// ������ʽ

};

#endif // CALCULATE_H
