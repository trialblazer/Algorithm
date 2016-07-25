
#include<stdio.h>

#define Max 10

struct List
{
	int number;
	char name[Max];
	struct List *next;
};
typedef struct List node;
typedef node *Link;

void free(Link Head)
{
	Link pointer;
	while(Head!=NULL)
	{
		pointer=Head;
		Head=Head->next;
		free(pointer);
	}
}


void prin(Link Head){
	while(Head!=NULL)
	{
		printf("%d   ", Head->number);
		printf("%s\n", Head->name);
		Head=Head->next;

	}
}

Link creat(Link Head)
{
	Link pointer;
	Link New;
	int datanum;
	char dataname[Max];
	int i;
	Head=(Link)malloc(sizeof(node));
	if(Head==NULL)
		printf("Memory allocate failure!!");
	else
	{
		datanum=1;
		printf("Please input the dataname:   ");
		scanf("%s", dataname);
		Head->number=datanum;
		for(i=0; i<Max; i++)
			Head->name[i]=dataname[i];
		Head->next=NULL;
		pointer=Head;
		while(1)
		{
			datanum++;
			New=(Link)malloc(sizeof(node));
			printf("Please input the dataname:  ");
			scanf("%s", dataname);
			if(dataname[0]=='0')
				break;
			New->number=datanum;
			for(i=0; i<Max; i++)
				New->name[i]=dataname[i];
			New->next=NULL;
			pointer->next=New;
			pointer=New;
		}
	}
	return Head;
}

int main()
{
	Link Head;
	Head=creat(Head);
	if(Head!=NULL)
	{
		prin(Head);
		free(Head);
	}
	return 0;
}

