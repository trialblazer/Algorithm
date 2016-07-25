#include<iostream>
#include <cstdio>

using namespace std;

double f(int n, double begin, double end);

int main()
{
    printf("%lf10\n", f(3, 1, 2));
    return 0;
}

double f(int n, double begin, double end)
{
    if(end-begin<0.000000000000001)
        return end;
    double mid=(begin+end)/2;
    if(mid*mid-n>0)
        return f(n,begin,mid);
    return f(n,mid,end);

}
