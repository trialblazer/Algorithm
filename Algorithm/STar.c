#include<iostream>
using namespace std;

int f(int q);
int g(int n);

int main()
{
    int q;
    cin>>q;
    for(int i=-q; i<=q; i++)    //�Ǽӿ��Ƕ�ֵ
    {                            //��Ҫע�⻹��0�����Ը�ֵΪ3��ӡ7��
        int n=g(i);
        for(int j=0; j<=n-1; j++)
        {
            cout<<"*";
        }
        for(int j=0; j<2*q-2*n+1; j++)
        {
            cout<<" ";

        }
        for(int j=0; j<=n-1; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}


int g(int n)
{
    if(n>0)
        return n;
    else
        return -n;
}
