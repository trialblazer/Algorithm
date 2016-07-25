#include<stdio.h>

void f(int a[], int size);
void g(int a[], int size);


int main()
{
    int a[5]={1,2,3,4,5};
    int i=0;
    f(a, 5);
    printf("\n");
    g(a, 5);
    f(a, 5);
}

void f(int a[], int size)
{
    int i;
    for(i=0; i<size; i++)
        printf("%d  ", a[i]);
}

void g(int a[], int size)
{
    int *p=a, *t=a+size-1;
    int i;
    for(i=0; i<size/2; i++)
    {
        int temp=*p;
        *p=*t;
        *t=temp;
        p++;
        t--;
    }
}

/*void g(int a[], int size)
{
    int i, j=size-1;
    for(i=0;i<size/2; i++)
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        j--;
    }
}*/
