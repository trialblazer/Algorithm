#include<stdio.h>

#define Max 8
#define len 2*Max-1

int a[len][len];
int m=0;

void prin(int k);

int main()
{
	prin(Max);
	return 0;
}

void prin(int k)
{
	int i, j, n=(len-m);
	for(i=m; i<n; i++)
		for(j=m; j<n; j++)
			a[i][j]=k;
		if(n==1) {
			for(i=0; i<len; i++) {
			for(j=0; j<len; j++)
				printf("%3d", a[i][j]);
			puts(" ");
		}
	}
	m++;
	prin(k-1);
}


#include<stdio.h>

#define Max 8
#define len 2*Max-1

int a[len][len];

void prin(int n);

int main()
{
	prin(Max);
	return 0;
}

int m=0;
void prin(int n)
{
	int i, j, k;
	for(k=n; k>0; k--) {
		n=(len-m);
		for(i=m; i<n; i++)
			for(j=m; j<n; j++)
				a[i][j]=k;
		m++;
	}
	for(i=0; i<len; i++) {
		for(j=0; j<len; j++)
			printf("%3d", a[i][j]);
		puts(" ");
	}
}
