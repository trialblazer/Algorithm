/*#include<stdio.h>
void main()
{
    int swap(int *p1, int *p2);

    int a[3];
    int i;
    int *p, *t;
    p=&a, t=&a[3];
    for(i=0; i<3; i++)
    {
        scanf("%d", a[i]);
    }
   /*while(t-p>=1)
    {
        swap(p, t);
        p++; t--;
    }
    for(p=a; p<a+3; p++)
        swap(p, t);
    for(i=0; i<3; i++)
    {
        swap((p+i), (t-i));
    }

    for(p=a; p<a+3; p++)
        printf("%d", *p);
}

int swap(int *p1, int *p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}*/


#include<stdio.h>

void swap(int *p1, int *p2);

void main()
{
    int m=2, n=3;
    //int *pointer_1=m;    只限于数列
    //int *pointer_2=n;
    int pointer_1, pointer_2;
    pointer_1=&m;
    pointer_2=&n;
    swap(pointer_1, pointer_2);
    printf("%d,%d", m, n);

}

void swap(int *p1, int *p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;

}





