#include <iostream>
using namespace std;

void quickSort(int a[], int begin, int end);
int partition(int a[], int begin, int end);

void mergeSort(int a[], int begin, int end);
void merge(int a[], int begin, int mid, int end);

int a[]= {6, 12, 43, 23, 89};

int main()
{

    mergeSort(a, 0, 5);
    for(int i=0; i<5; i++)
        cout<<a[i]<<" ";
    return 0;
}

//快速排序
//先划分再排序
void quickSort(int a[], int begin, int end)
{
    if(end-begin>2)
    {
        int mid = partition(a, begin, end);
        //quickSort(a, begin, mid);
        //quickSort(a, mid, end);
        quickSort(a, begin, mid-1);
        quickSort(a, mid+1, end);
    }
}

//用a[begin]划分a数组
int partition(int a[], int begin, int end)
{
    int v = a[begin];
    int b = begin, e = end;

    while(b<e)
    {
        while(b<end && a[++b]<v);
        while(e>0 && a[--e]>v);
        if(b<e)
        {
            int tmp = a[b];
            a[b] = a[e];
            a[e] = tmp;
        }
        else
        {
            break;
        }
    }

    int tmp = a[e];
    a[e] = a[begin];
    a[begin] = tmp;

    return e;
}


//合并排序
//先对分成两半，并排序，然后对两半进行合并
void mergeSort(int a[], int begin, int end)
{
    if(end-begin>2)
    {
        int mid = (begin+end)/2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid, end);
        merge(a, begin, mid, end);
    }
}

//将排好序的两段合并成整体排好序的
//[begin, mid)  [mid, end)
void merge(int a[], int begin, int mid, int end)
{
    int size = end - begin;
    int * b = new int[size];

    int p1 = begin, p2 = mid;
    int pb = 0;

    while(p1<mid && p2<end)
    {
        if(a[p1]>a[p2])
        {
            b[pb] = a[p2];
            pb++, p2++;
        }
        else
        {
            b[pb] = a[p1];
            p1++, pb++;
        }
    }
    while(p1<mid)
        b[pb++] = a[p1++];
    while(p2<end)
        b[pb++] = a[p2++];


    for(int i=begin; i<end; i++)
        //a[i] = b[i];
        a[i] = b[i-begin];

    delete []b;
}
