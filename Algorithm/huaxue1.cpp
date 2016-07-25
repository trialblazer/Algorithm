
#include <stdio.h>
#include <memory.h>
int max=0;

int c_row,c_col;

int a[100][100];
int v[100][100];
int offset[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int solve(int row,int col);

int main()
{
	scanf("%d %d",&c_row,&c_col);
	for(int i=0;i<c_row;i++){
		for(int j=0;j<c_col;j++)
			scanf("%d",&a[i][j]);
	}
	//solve(0,0);
	//函数应该循环调用否则对于某些数据就只是求解了一部分
	//例如，当a[0][0]最小时，函数就只求解了a[0][0]就结束了
	//从而导致错误
	for(int i=0;i<c_row;i++){
		for(int j=0;j<c_col;j++)
			solve(i,j);
	}
	printf("%d\n",max);
	return 0;
}

int solve(int row,int col)
{
	if(v[row][col])
		return v[row][col];
	int r,c;
	for(int i=0;i<4;i++)
	{
		r=row+offset[i][0];
		c=col+offset[i][1];
		if(r>=0 && c>=0 && r<c_row && c<c_col)
		{
			if(a[r][c]<a[row][col])
			{
				int temp=solve(r,c)+1;
				if(v[row][col]<temp)
					v[row][col]=temp;
			}
		}
	}
	if(!v[row][col])
		v[row][col]=1;
	if(v[row][col]>max)
		max=v[row][col];
	return v[row][col];
}              