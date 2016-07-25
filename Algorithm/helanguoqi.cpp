/*
����������־λbegin��end�ֱ�ָ���������Ŀ�ʼ��ĩβ��Ȼ����һ����־λcurrent
��ͷ��ʼ���б�����
1������������λ��Ϊ0����˵����һ������ǰ�������Ǿͺ�beginλ�ý��н�����Ȼ��
current��ǰ����beginҲ��ǰ������ʾǰ�ߵ��Ѿ����ź��ˣ���
2������������λ��Ϊ1����˵����һ�������в���������˼·���в������Ƕ�������Ȼ
��current��ǰ����
3������������λ��Ϊ2����˵����һ�����ں󲿣����Ǿͺ�endλ�ý��н��������ڽ���
��Ϻ�currentָ��Ŀ���������ǰ���ģ�����ʱcurrentǰ����ᵼ�¸�λ�ò��ܱ���
����ǰ�������Դ�ʱcurrent��ǰ������ͬ1����end�����1��
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define N 50000
int num1 = 0, num2 = 0;
void swap (int &var1, int &var2)
{
    int temp = var1;
    var1 = var2;
    var2 = temp;
}
void shuffle(int *array)
{
    int current = 0;
    int end = N-1;
    int begin = 0;
    while( current<=end )
    {
        if( array[current] ==0 )
        {
            swap(array[current],array[begin]);
            current++;
            begin++;
        }
        else if( array[current] == 1 )
            current++;
        else //When array[current] =2
        {
            swap(array[current],array[end]);
            end--;
        }
        num1++;
    }
}

void f(int *array)
{
    int current, end = N-1, begin = 0;
    if (array[begin] == 0)
        begin++;
    current = begin;
    if (array[end] == 2)
        end--;
    while( current<=end )
    {
        int sign = 0;
        if(array[current] == 0)
        {
            swap(array[current],array[begin]);
            while (1)
            {
                if (array[begin] == 0)
                {
                    begin++;
                    sign = 1;
                }
                else break;
            }
            if (sign == 0)
                begin++;
            if (current<begin)
                current = begin;
            else
                current++;
        }
        else if( array[current] == 1 )
            current++;
        else //When array[current] =2
        {
            swap(array[current],array[end]);
            while (1)
            {
                if (array[end] == 2)
                {
                    end--;
                    sign = 1;
                }
                else break;
            }
            if (sign == 0)
                end--;
        }
        num2++;
    }
}
int main(int argc, char *argv[])
{
    int a[N], b[N];
    int i;
    for( i=0 ; i<N; i++ )
        a[i] = b[i] = rand()%3;
    cout << endl;
    shuffle(a);
    f(b);
    for (int i=0; i<N; i++)
        if (a[i] != b[i])
        {
            cout << "wrong!\n";
            break;
        }
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    return 0;
}
