#include<stdio.h>

#define Size 10

void merge(int a[], int begin, int mid, int end);

int main()
{
    int i, a[Size];
    printf("Please input %d number:\n", Size);
    for(i=0; i<Size; i++)
        scanf("%d", &a[i]);
    merge(a, 0, Size/2, Size);
    for(i=0; i<Size; i++)
        printf("%d ", a[i]);
    puts("");
    return 0;
}

void merge(int a[], int begin, int mid, int end)
{
    int i, j, g=mid;
    for(i=begin; i<g; i++) {
        for(j=--mid; j<end && j>-1; j++) {
            if(j+1==end || a[j]<a[j+1])
                break;
            int tem=a[j];
            a[j]=a[j+1];
            a[j+1]=tem;
        }
    }
}























