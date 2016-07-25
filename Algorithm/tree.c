#include<stdio.h>

#define Max 16

void creat_tree(int *node_list, int *b_tree, int j);

int main()
{
	int node_list[Max];
	int b_tree[Max];
	int i, j, data;
	printf("Please input numbers(Exit for 0!!):  ");
	scanf("%d", &data);
	/*node_list[1]=data;
	while(data!=0)
	{
		j=1;
		for(i=2; i<=Max; i++)
		{
			j++;
			scanf("%d", &data);
			node_list[i]=data;
		}
	}*/

	j=1;
	while(data!=0)
	{
		node_list[j]=data;
		j++;
		scanf("%d", &data);
	}

	/*for(i=0; i<Max ;i++)
	{
		b_tree[i]=0;
	}*/

	for(i=1; i<Max; i++)
		b_tree[i]=0;

	creat_tree(node_list, b_tree, j);

	printf("\nThe tree is :  \n");
	for(i=1; i<Max; i++)
		printf("%d  :  [%d]\n", i, b_tree[i]);

	return 0;
}


void creat_tree(int *node_list, int *b_tree, int j)
{
	b_tree[1]=node_list[1];
	int i;
	/*for(i=2; i<=j; i++)
	{
		b_tree[i]=node_list[i];
	}*/

	int level=1;
	for(i=2; i<=j; i++)
	{
		while(b_tree[level]!=0)
		{
			if(node_list[i]<b_tree[level])
				level=2*level;
			else
				level=level*2+1;
		}
		b_tree[level]=node_list[i];
	}
}
