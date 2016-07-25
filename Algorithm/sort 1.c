
#include<iostream>
using namespace std;


void sort(int a[], int size);
int max(int a[], int begin, int end);


int main()
{
    int a[6] = {5, 2, 7, 3, 9, 1};
    //for(int j=0; j<6; j++)
    //  cin>>a[j];
    sort(a, 6);
    for(int j=0; j<6; j++)
        cout<<a[j]<<" ";

    return 0;
}

int max(int a[],int begin , int end)
{
    //int max1 = a[0];
    int max1 = a[begin];
    int g=begin;
    for(int i=begin+1; i<end; i++)
    {
        if(max1<a[i])
        {
            max1=a[i];
            g=i;
        }
    }
    return g;
}

void sort(int a[], int size)
{
    for(int i=0; i<size; i++)
    {
        int temp = max(a, 0, size-i);
        int m = a[temp];
        a[temp] = a[size-i-1];
        a[size-i-1] = m;
    }
}



