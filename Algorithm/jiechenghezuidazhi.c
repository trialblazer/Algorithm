#include <iostream>
using namespace std;

//��n�Ľ׳�
int f(int n)
{
    if(n==0)
        return 1;
    return n*f(n-1);
}

//������a�±�������[begin, end)�����ֵ
int max(int a[], int begin, int end)
{
    //������ֻ��һ��ֵ��ֱ�ӷ���
    if(begin+1==end)
        return a[begin];

    //����ֵ
    int mid = (begin+end)/2;

    //������ǰ�벿��[begin, mid)�����ֵ
    int t1 = max(a, begin, mid);

    //�������벿��[mid, end)�����ֵ
    int t2 = max(a, mid, end);

    //��ǰ�벿�ֺͺ�벿�ֵ����ֵ
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
