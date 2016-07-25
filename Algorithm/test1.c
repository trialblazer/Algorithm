#include<stdio.h>
#include"test 1.h"

#define size 5

int main()
{
	push(5);
	pop();
	return 0;
}


""""""""""""""""""""""""""""""""""


int stack[size];
int top=-1;

void push (int value)
{
		int i;
		printf("Plese input %d numbers:  ", size);
		for(i=0; i<size; i++)
		{
			int j;
			scanf("%d", &j);
			if(top==size)
			{
				printf("the stack is empty!!");
			}
			else
			{
				top++;
				stack[top]=j;
			}
		}
}


void pop()
{
	if(top==-1)
	{
		printf("The stack is empty!!");
	}
	else
	{
		int i;
		for(i=0; i<size; i++)
		{
			int j=stack[top];
			top--;
			printf("%d  ", j);
		}
		puts(" ");
	}
}
