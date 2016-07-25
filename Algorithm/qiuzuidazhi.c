#include <iostream>
using namespace std;

int max(int a, int b, int c);
int max4(int a, int b, int c, int d);

int main()
{
    int a, b, c ,d;
    cin>>a>>b>>c>>d;
    //max(a, b, c);
    cout<<max4( a, b, c, d) <<endl;
    return 0;
}

int max4(int a, int b, int c, int d)
{
    int tmp = max(a, b, c);
    if(tmp>d)
        return tmp;
    else
        return   d;


}

int max(int a, int b, int c)
{
    if (a>b)
    {
        if(a>c)
        {
            return a;
        }
        else
        {
             return c;
        }

    }
    else
    {
        if(b<c)
            return c;
        else
            return b;
    }
    /*if(a>b && a<c)
    {
        return c;
    }
    else
    {
        if (a>c)
        {
            return a;
        }
        else
        {
            return b;
        }
        return a;
    }
}
