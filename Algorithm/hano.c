#include<iostream>
using namespace std;


void hano(int n, char a, char b, char c);

int num = 0;

int main()
{
    int n;
    cin>>n;
    hano(n, 'a', 'b', 'c');
    cout<<num<<endl;
    return 0;
}


void hano(int n, char a, char b, char c)
{
    if(n==1)
    {
        num++;
        cout<<a<<"-->"<<c<<"\n";
    }
    else
    {
        hano(n-1, a, c, b);
        num++;
        cout<<a<<"-->"<<c<<"\n";
        hano(n-1, b, a, c);
    }
}
