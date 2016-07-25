#include <iostream>
using namespace std;

//求n的阶乘
int f(int n)
{
    if(n==0)
        return 1;
    return n*f(n-1);
}

//求数组a下标在区间[begin, end)的最大值
int max(int a[], int begin, int end)
{
    //数组中只有一个值，直接返回
    if(begin+1==end)
        return a[begin];

    //求中值
    int mid = (begin+end)/2;

    //求数组前半部分[begin, mid)的最大值
    int t1 = max(a, begin, mid);

    //求数组后半部分[mid, end)的最大值
    int t2 = max(a, mid, end);

    //求前半部分和后半部分的最大值
    if(t1>t2)
        return t1;
    return t2;
}

int main()
{
    cout<<f(6)<<endl;
    int a[5] = {4,1,6,8,3};
    cout<<max(a, 0, 5)<<endl;
    return 0;
}
