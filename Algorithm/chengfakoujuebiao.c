#include<stdio.h>

void prin(int n);

int main()
{
	int n; 
	printf("Please input the n:  ");
	scanf("%d", &n);
	prin(n);
	return 0;
}

void prin(int n)
{
	int i, j;
	for(i=1; i<=n; i++) {
		for(j=1; j<=i; j++) {
			int d=i*j;
			printf("%d*%d=%-4d", i, j, d);
		}
		printf("\n");
	}
}