#include<stdio.h>

#define Queen_Max 6

int queen_number=0;
int queen[Queen_Max][Queen_Max];

int judge_queen(int x, int y);
void place_queen(int x);

int main() {
	int i, j;
	for(i=0; i<Queen_Max; i++)
		for(j=0; j<Queen_Max; j++)
			queen[i][j]=0;
	place_queen(0);
	return 0;
}

int judge_queen(int x, int y) {
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

void place_queen(int x) {
	int i, j;
	if(queen_number==Queen_Max) {
		for(i=0; i<Queen_Max; i++) {
			for(j=0; j<Queen_Max; j++) {
				printf("%4d", queen[i][j]);
			}
			puts(" ");
		}
		puts(" ");
	}
	for(i=0; i<Queen_Max; i++) {
		if(judge_queen(x, i)) {
			queen[x][i]=1;
		//	for(j=0; j<Queen_Max; j++) 
		//		printf("%4d", queen[x][j]);
		//	puts(" ");
			queen_number++;
			place_queen(++x);
			queen[x-1][i]=0;
	//		for(j=0; j<Queen_Max; j++) 
	//			printf("%4d", queen[x][j]);
	//		puts(" ");
			queen_number--;
			--x;
		}
	}
}

/*
int place_queen(int x) {
	int i, j, queen_number=0;
	for(j=0; j<Queen_Max; j++) {
		if(judge_queen(x, j)) {
			queen[x][j]=1;
			queen_number++;
			if(Queen_Max==queen_number)	return 1;
			place_queen(++x);
		}
		if(j==(Queen_Max-1))
			for(i=0; i<Queen_Max; i++) {
				queen[x-1][i]=0;
				queen_number--;
			}
	}	
}*/