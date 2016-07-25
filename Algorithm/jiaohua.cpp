#include<stdio.h>
#include <ctime>
#include <cstdlib>

#define Max 10
void swap(int *x, int *y);
int f(int a[], int n);

int main()
{
	int i, a[Max];
    srand(time(NULL));
    for (i=0; i<Max; ++i) {
        a[i] = rand()%(Max*10);
        printf("%d  ", a[i]);
    }
    puts("");
	f(a, Max);
	
	return 0;
}

void swap(int* x, int* y)
{
	int tem=*x;
	*x=*y;
	*y=tem;
}

int f(int a[], int n)
{
	int i, j=1, g=a[0];
	for(i=1;i<Max; i++){
loop:if(i==(Max-j)) {
			if(a[i]<a[0])
				swap(&a[0], &a[i]);
			else
				swap(&a[0], &a[i-1]);
			printf("a[0]=%d\n", g);
			for(i=0;i<Max; i++)
				printf("%-3d", a[i]);
			puts("\n");
			return 1;
		}
		if(a[i]>a[0]) {
			while(i<Max-j) {
				if(a[Max-j]<a[0]) {
					swap(&a[Max-j], &a[i]);
					break;
				}
				j++;
				if(i==(Max-j))
					goto loop;
			}
			j++;
		}
	}
}


