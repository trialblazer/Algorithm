#include<stdio.h>

#define Max 8

int combine(int a[], int b[], int begin, int end);
void pri(int a[], int begin, int end);

int main()
{
	int a[Max]={7,9,11,13,150,170,190,210};
	int b[Max]={2,4,6,8,10,12,14,16};
	combine(a, b, 0, Max-1);
	puts("");
	return 0;
}

int combine(int a[], int b[], int begin, int end)
{
	int i, j=end;
	if(a[begin]>b[end]) {
		pri(b, 0, end+1);
		pri(a, 0, end+1);
		return 1;
	}
	int g=0, p;
	for(i=begin; i<=end; i++) {
		if(b[i]>=a[j]) {
			pri(a,  g, j);
			pri(b, i, j);
			return 1;
		}
		if(b[i]<=a[begin]) {
			printf("%d   ", b[i]);
		}
		else {
			while(1) {
				int mid=(g+end)/2;
				if(b[i]>=a[mid])
					begin=mid;
				else
					end=mid;
				if(begin+1==end) {
					pri(a, g, begin);
					printf("%d   ", b[i]);
					break;
				}
			}
			g=end;
			p=end;
			end=j;
		}
	}
	for(i=p; i<=j; i++)
		printf("%d   ", a[i]);
}

void pri(int a[], int begin, int end)
{
	int i;
	for(i=begin; i<=end; i++)
		printf("%d   ", a[i]);
}
