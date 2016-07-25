	ջ
#include<stdio.h>

int stack[5];
int top=-1;
int max=5;

void push(int value)
{
	if(top==max)
		printf("the stack is full");
	else
	{
		top++;
		stack[top]=value;
	}
}

int pop()
{
	if(top==-1)
		printf("The stack if empty");
	else
	{
		int i=stack[top];
		top--;
		return i;
	}
}

int length()
{
	return top;
}

int main()
{
	int i;
	for(i=0; i<5; i++)
	{
		int j;
		scanf("%d", &j);
		push(j);
	}
	for(i=1; i<6; i++)
	{
		printf("%d=  %d\t", i, pop());
	}
	printf("length=  %d", length());
}
