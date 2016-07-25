#include<iostream>

using namespace std;

int min(int a[], int begin, int end);

int main()
{
    int a[5]={-1,1,25,-4,6};
    cout<<"min=\t"<<min(a,0,8)<<endl;
    return 0;
}

int min(int a[],int begin ,int end)
{
    if(begin+1==end)
        return a[begin];
    else
        {
            int t1 ,t2;
            int mid=(begin+end)/2;
            t1=min(a,begin ,mid);
            t2=min(a,mid,end);
            if(t1>t2)
                return t2;
            else
                return t1;
        }
}

//排序
int f(int a[], int size)
{
    int i, j;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-1; j++)
        {
            if(a[j]<a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
