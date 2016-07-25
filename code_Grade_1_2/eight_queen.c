/*
#include<stdio.h>

#define Queen_Max 8

int queen_number=0;
int k=0;
int queen[Queen_Max][Queen_Max];

int judge_queen(int x, int y);
void place_queen(int x);

int main()
{
	int i, j;
	for(i=0; i<Queen_Max; i++)
		for(j=0; j<Queen_Max; j++)
			queen[i][j]=0;
	place_queen(0);
	return 0;
}

int judge_queen(int x, int y)
{
	if(queen[x][y]==1)	return 0;
	int i, j;
//shang
	for(i=0; i<x; i++)
		if(queen[i][y]==1)	return 0;
//zuoshang
	i=x, j=y;
	while(i>=0 && j>=0) {
		if(queen[i--][j--]==1)	return 0;
	}
//youshang
	i=x, j=y;
	while(i>=0 && j<Queen_Max) {
		if(queen[i--][j++]==1)	return 0;
	}

	return 1;
}

void place_queen(int x)
{
	int i, j;
	if(queen_number==Queen_Max) {
		printf("µÚ%d×é½â\n", ++k);
		for(i=0; i<Queen_Max; i++) {
			for(j=0; j<Queen_Max; j++) {
				printf("%2d", queen[i][j]);
			}
			puts(" ");
		}
		puts(" ");
	}
	for(i=0; i<Queen_Max; i++) {
		if(judge_queen(x, i)) {
			queen[x][i]=1;
			queen_number++;
			place_queen(++x);
			queen[x-1][i]=0;
			queen_number--;
			--x;
		}
	}
}*/

#include<iostream>
using namespace std;

#define Max 8

int safe(int x, int y);
void place(int n);

int a[Max], num=1;

int main()
{
	int i;
	for(i=0; i<Max; i++)
		a[0]=0;
	place(0);
	return 0;
}

void place(int n)
{
	int i, j;
	if(n==Max) {
		cout<<"This is the "<<num++<<"st key:"<<endl;
		for(i=0; i<Max; i++) {
			for(j=0; j<Max; j++) {
				if(a[i]==j)
					cout<<"#"<<" ";
				else
					cout<<"0"<<" ";
			}
			cout<<endl;
		}
	}
	else {
		for(i=0; i<Max; i++) {
			if(safe(n, i)) {
				a[n]=i;
				place(n+1);
				//place(++n)   改变的是N的值不是形参的值
			}
		}
	}
}

int safe(int x, int y)
{
	int i;
	for(i=0; i<x; i++) {
		if(a[i]==y || a[i]==(x+y-i) || a[i]==(y-x+i))
			return 0;
	//	else
	//		return 1;
	}
	return 1;
}
