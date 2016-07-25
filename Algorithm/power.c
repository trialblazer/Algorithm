#include<iostream>
using namespace std;

int f(int m, int n);
int k;

int main()
{
    cout<<f(2, 1)<<"\n";
    cout<<k<<"\n";
    return 0;
}

int f(int m, int n)
{
    k++;
    if(n==0)
    {
        return 1;
    }
    else
    {
        if(n%2==0)
        {
            //return f(m, n/2)*f(m, n/2);
            int tmp = f(m, n/2);
            return tmp*tmp;
        }
        else
        {
            return f(m, n-1)*m;
        }
    }
}
