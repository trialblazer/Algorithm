/*
设置两个标志位begin和end分别指向这个数组的开始和末尾，然后用一个标志位current
从头开始进行遍历：
1）若遍历到的位置为0，则说明它一定属于前部，于是就和begin位置进行交换，然后
current向前进，begin也向前进（表示前边的已经都排好了）。
2）若遍历到的位置为1，则说明它一定属于中部，根据总思路，中部的我们都不动，然
后current向前进。
3）若遍历到的位置为2，则说明它一定属于后部，于是就和end位置进行交换，由于交换
完毕后current指向的可能是属于前部的，若此时current前进则会导致该位置不能被交
换到前部，所以此时current不前进。而同1），end向后退1。
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
