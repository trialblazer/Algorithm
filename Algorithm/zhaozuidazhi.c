#include<iostream>
using namespace std;

#define Max 10

int max(int a[], int size);

int main()
{
    int a[Max];
    for(int i=0; i<5; i++)
        cin >>a[i];
    cout<<max(a,5)<<endl;
    return 0;
}
int max(int a[], int size)
{
     //int max=0;
    int max1=a[0];
    for(int i=1; i<size; i++)
    {
        if (max1<a[i])
            max1=a[i];
    }
    return max1;
}

/*
int max(int a[],int begin,int end)
{
    if(begin+1==end)
    {
   // if (a[begin]>a[end])
            return a[begin];
          //return a[end];
    }
    else
        {
            int t1,t2;
            int mid=(begin+end)/2;
            t1=max(a,begin,mid);
            t2=max(a,mid,end);
            if(t1>t2)
                return t1;
                return t2;
        }
}

*/
