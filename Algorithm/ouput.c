/*#include<iostream>
uding namespace std;
int max(int a,int b,int c,int d);
int main()
{
       int e,f,g,h;
       cin>>e>>f>>g>>h;
       cout<<max(e,f,g,h);
    return 0;
}
int max(int a,int b,int c,int d)
{
    if(a>b)
        {
            if(c>d)
                {
                    if(a>c)
                        return a;
                        return c;
                }
            else
                {
                    if(a>d)
                        return a;
                        return d;
                }
        }
      else
          {
                if(c>d)
                {
                    if(b>c)
                        return b;
                        return c;
                }
            else
                {
                    if(b>d)
                        return b;
                        return d;
                }
          }
}*/
#include<iostream>
using namespace std;
int max(int a[],int size);
int main()
{
    int a[5];
    for(i=0;i<5;i++)
        cin>>a[i];
    cout<<max(a,5)<<endl;
    return 0;
}
int max(int a[],int size)
{
    int m=a[0];
    for(int i=1;i<size;i++)
        {
            if(m<a[i])
                m=a[i];
        }
        return m;
}
