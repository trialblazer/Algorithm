
/*#include<stdio.h>
void main()
{
    int m;
    scanf("%d",&m);
    int i=1;
    int j=2;
    int n;     //加的
    while( j<=m)
    {

        //int n;
        n=i*j;
        i=n;
        j++;
    }
    printf("%d",n);    //n未定义，要定义全局变量‘
}*/


#include<stdio.h>
void main()
{
    int m=5;
    int i=1;
    int n, j;   //加的
    for(/*int j=2*/j=2; j<m; j++)   //j不能在for循环中定义，要在外面定义；
    {
        //int n=i*j;    错误
        n=i*j;
        i=n;

    }
    //printf("%d",&n);            //取地址用于输入
    printf("%d", n);    //n没有定义，所以要定义一个全局变量n

}
