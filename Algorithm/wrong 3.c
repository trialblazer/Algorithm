（1）
int f(int a[], int begin, int end)    分肯定的分到f（a, 0, 0)因为出口必须两个
{
    if(begin+1==end)                   数，相矛盾，所以为死递归
    {
        if(a[begin]<=a[end])
            return 1;
        else
            return -1;
    }
else
    {
        int mid=(begin+end)/2;
        int t1=min(f(a, begin, mid-1), f(a, mid, end));
        int t2=a[mid-1]<=a[mid]?1:-1;
        return min(t1, t2);
    }

}

（2）
#include<stdio.h>

int f(int a[], int size);

int main()
{
    int a[5]={2,2,2,1,5};
    printf("%d",f(a, 5));
}

int f(int a[], int size)
{
    int i=0;
    while(i<size)        //应该小于size-1
    {
        if(a[i]>a[i+1])
        {
            return -1;
        }
        else
        {
            i++;
        }
    }
    return 0;
}


（3）

#include<stdio.h>

int f(int a[], int begin, int end);

int main()
{
    int a[2]={1,3};
    printf("%d", f(a, 0, 2));
    return 0;
}

int f(int a[], int begin, int end)
{
    if(begin+1==end)
    {
        return 1;
    }
    else
    {
        int mid=(begin+end)/2;
        int t1=f(a, begin, mid);
        int t2=f(a, mid, end);
        if(t1==1&&t2==1)
        {
            int i=a[mid-1]<=a[mid]?1:-1;
            return i;
        }
        else
            return -1;

    }
}*/










