#include<stdio.h>

#define Size 5

int comb(int a[], int b[], int size);

int main()
{
    int i, a[Size], b[Size];
    printf("Please input %d number:\n", Size);
    for(i=0; i<Size; i++)
        scanf("%d", &a[i]);
    printf("Please input another %d number:\n", Size);
    for(i=0; i<Size; i++)
        scanf("%d", &b[i]);
    comb(a, b, Size);
    puts("");
    return 0;
}

int comb(int a[], int b[], int size)
{
    int c[size*2], m=0, n=0, p=0, i;
    while(1){
        if(m==size && n!=size) {
            for(i=n; i<size; i++)
                c[p++]=b[i];
            for(i=0; i<size*2; i++)
                printf("%d  ", c[i]);
            return 0;
        }
        if(n==size && m!=size) {
            for(i=m; i<size; i++)
                c[p++]=a[i];
            for(i=0; i<size*2; i++)
                printf("%d  ", c[i]);
            return 0;
        }
        if(a[m]<b[n])
            c[p++]=a[m++];
        else
            c[p++]=b[n++];
    }
}

/*
void merge(int a[],int b,int m,int e){
    int * c=new int[e-b];
    int i=b,j=m;
    int p=0;
    while(i<m && j<e) {
        if(a[i]>a[j])
            c[p++]=a[j++];
        else
            c[p++]=a[i++];
    }
    while(i<m) c[p++]=a[i++];
    while(j<e) c[p++]=a[j++];
    memcpy(a+b,c,sizeof(int)*(e-b));
    delete []c;
}*/



















