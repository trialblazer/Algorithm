#include<iostream>
using namespace std;

int max(int a[], int size);
void sort(int a[], int size);
int m(int a[], int b,int c);


int main(int argc, char * argv[])
{
    if(argc==1)
    {
        cout<<argc<<"! = "<<1<<endl;
        return 1;
    }

    int res = argc*main(argc-1, argv);
    cout<<argc<<"! = "<<res<<endl;
    return res;
}

int max(int a[],int size)
{
    int temp=a[0];
    int g=0;
    for(int i=1; i<size; i++)
    {
        if(temp<a[i])
        {
            temp=a[i];
            g=i;
        }
    }
    return g;
}

void sort(int a[], int size)
{

    for(int i=0; i<size-1; i++)
    {
        int g=max(a, size-i);
        int temp=a[g];
        a[g]=a[size-i-1];
        a[size-i-1]=temp;
    }
}



//д��ע��
int m(int a[], int b, int c)
{
   int i=0;
   while(i<=b)
   {
       //if(a[i]==a[b])
       if(a[i]==c)
       {
            //return b;
            return i;
            //break;  //�������غ��û�б�Ҫbreak
       }
       //b++;//Ӧ����i++,
       i++;
   }
   //�ϱߵ�ѭ��û�ҵ�������û�����ף�
   return -1;

}
