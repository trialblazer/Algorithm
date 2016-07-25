#include<iostream>
using namespace std;
int max1(int a,int b);
int max(int c);
int main()
{
    int a, b, c;
   cin>>a>>b>>c;
    //int max(int a, int b );
      cout<<max(a,b);
    return 0;
}

int max(int c)
{
    int max1(int a, int b);
    if(c> max1(a,b))
        return c;
        return max1(a,b);
}
int max1(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
