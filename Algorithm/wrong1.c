
/*#include<stdio.h>
void main()
{
    int m;
    scanf("%d",&m);
    int i=1;
    int j=2;
    int n;     //�ӵ�
    while( j<=m)
    {

        //int n;
        n=i*j;
        i=n;
        j++;
    }
    printf("%d",n);    //nδ���壬Ҫ����ȫ�ֱ�����
}*/


#include<stdio.h>
void main()
{
    int m=5;
    int i=1;
    int n, j;   //�ӵ�
    for(/*int j=2*/j=2; j<m; j++)   //j������forѭ���ж��壬Ҫ�����涨�壻
    {
        //int n=i*j;    ����
        n=i*j;
        i=n;

    }
    //printf("%d",&n);            //ȡ��ַ��������
    printf("%d", n);    //nû�ж��壬����Ҫ����һ��ȫ�ֱ���n

}
