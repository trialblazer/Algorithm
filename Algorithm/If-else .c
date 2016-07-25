#include <iostream>

using namespace std;

int max(int a, int b);

int main()
{
    int a, b, c;
    cin >>a>>b;
    c = max(a, b);
    cout<<c<<endl;
    return 0;
}

int max(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return  b;
    }
}



