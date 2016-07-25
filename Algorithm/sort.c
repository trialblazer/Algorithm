#include<iostream>       //现在有三种方法
using namespace std;

void sort(int a[],  int size);
int f(int a[], int n, int begin, int end);
int max(int a[], int size);

int main()
{
    int a[7]={1,78,59,2,3,4,56};
    sort(a, 7);
    for(int i=0; i<7; i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    cout<<f(a, 31, 0, 7);
    return 0;
}

int max(int a[], int size)   //找函数中最大值的坐标
{
    int max=a[0];
    int g=0;
    for(int i=1; i<size; i++)
    {
        if(max<a[i])
        {
            max=a[i];
            g=i;
        }

    }
    return g;

}

/*int f(int b[], int n, int size)  //用逐个比较的方法找是否存在n
{
    int i=0;
    while(i<size)
    {
        if(n==b[i])
        {
            return i;
        }
        else
            i++;
    }
    return -1;

}*/

void sort(int a[], int size)     //将函数排序
{
    for(int i=0; i<size-1; i++)
    {
        int g=max(a, size-i);
        int temp=a[g];
        a[g]=a[size-i-1];
        a[size-i-1]=temp;
    }
}


/*int f(int b[], int n, int begin, int end)  //用递归的方法在[begin,end)上找是否存在n
{
    if(b[begin]>n||b[end-1]<n)
        return -1;
    else
    {
        if(begin+1==end)    //出口
        {
            if(b[begin]==n)
                return begin;
            else
                return -1;
        }
        else
        {
            int mid=(begin+end)/2;
            if(b[mid]>n)                //因为是半闭半开所以mid只能做begin不能end,所以不能是>=.
                f(b, n, begin, mid);
            else
                f(b, n, mid, end);
        }
    }


    /*if(n<b[0] || n>b[end-1])     //函数功能是在[begin,end)上的找是否存在n。所以不是b[0]是b[begin]
        return -1;
    else
    {
        for(int i=0; i<end; i++)      //思维混乱，想用递归，但又参杂有for循环，
        {
            if(begin+1 == end)
            {
                if(b[begin] == n)
                {
                   return begin;
                }

                else
                {
                     return -1;
                }
            }

            else
            {
                int mid=(begin+end)/2;
                if(b[mid]>=n)
                    f(b, n, begin, mid);
                else
                    f(b, n, mid, end);
            }

        }
    }

}*/


int f(int a[], int n, int begin, int end)  //找是否存在n     死了
{
    if(a[begin]>n||a[end-1]<n)
        return -1;
    else
    {
        for(int i=0; i<end; i++)
        {
            if(a[i]==n)
            {
                return i;
            }
            else
            {
                int mid=(begin+end)/2;
                if(a[mid]<n)
                {
                    f(a, n, mid, end);
                }
                else
                {
                    f(a, n, begin, mid);
                }
            }

        }
    }
}


二：

#include<stdio.h>

int max(int a[], int size);
void sort(int a[], int size);
int find(int a[], int n, int size);

int main()
{
    int a[8]={1,4,5,2,78,12,9,7};
    sort(a, 8);
    puts(" ");
    find(a, 97, 8);
    return 0;
}

int max(int a[], int size)
{
    int max=a[0];
    int g=0;
    int i;
    for(i=1; i<size; i++)
    {
        if(max<a[i])
        {
            max=a[i];
            g=i;
        }
    }
    return g;
}


void sort(int a[], int size)
{
    int i,g;
    for(i=0; i<size-1; i++)
    {
        g=max(a, size-i);
        int temp;
        temp=a[g];
        a[g]=a[size-i-1];
        a[size-i-1]=temp;
    }
    for(i=0; i<size; i++)
    {
        printf("%d  ", a[i]);
    }
}


int find(int a[], int n, int size)
{
    int i=0;
    while(i<size)
    {
        if(a[i]==n)
        {
            printf("The number of ‘n’ in the quenen is: %d ", i);
            return i;
        }
        i++;
    }
    printf("NO FIND!!");
    return -1;
}
