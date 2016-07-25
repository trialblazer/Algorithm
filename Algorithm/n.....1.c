#include<iostream>
using namespace std;

/*int main()
{
    int a = 1, b = 2;
    int c;
   while(b<4)
    {
        c = a*b;
        b++;
        a = c;
    }
    cout<<c;
    return 0;
}*/

/*int main()
{
    int a=1, b=2;
    while(b<5)
    {
        a = a*b;
        b++;
    }
    cout<<a<<endl;
    return 0;

}*/

int f(int n);

int main()
{
   /* int n,a;
    int f(n=1);
    while(n<5)
    {
        if(n==0)
            return 1;
        else
        {
            a = f(n-1)*n;
            return a;
        }
    }
    cout<<a<<endl;*/
    cout<<f(4)<<endl;
    return 0;
}

int f(int n)
{
    if(n==0)
    {
        return 1;
    }
    return f(n-1)*n;
}





































































