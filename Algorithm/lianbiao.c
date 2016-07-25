
#include<stdio.h>
#include<stdlib.h>

#define Max 10

int searchtime=0;

struct List
{
	int number;
	char name[Max];
	struct List *next;
};
typedef struct List node;
typedef node *Link;

void free(Link head)
{
	Link pointer;
	while(head!=NULL)
	{
		pointer=head;
		head=head->next;
		free(pointer);
	}
}

void prin(Link head)
{
	while(head!=NULL)
	{
		printf("number=  %d,   name:    %s\n", head->number, head->name);
		head=head->next;
	}
}

int search(Link head, char key[Max])
{
	int i;
	while(head->name[0]!='0')
	{

		searchtime++;
		for(i=0; i<Max ; i++)
		{
			if(head->name[i]==key[i]&&(i+1)==9)
			{
				return 1;
			}
			if(head->name[i]!=key[i])
				goto loop;
		}
loop:	head=head->next;
	}
	return 0;
}

Link creat(Link head)
{
	Link pointer;
	Link ne;
	int i;
	int datanum;
	char dataname[Max];
	head=(Link)malloc(sizeof(node));
	if(head==NULL)
		printf("Memory allocate failure!!");
	else
	{
		datanum=1;
		printf("########################\n\n");
		printf("Please input the dataname:   ");
		scanf("%s", dataname);
		head->number=datanum;
		for(i=0; i<Max; i++)
			head->name[i]=dataname[i];
		head->next=NULL;
		pointer=head;
		while(1)
		{
			datanum++;
			ne=(Link)malloc(sizeof(node));
			printf("Please input the dataname:   ");
			scanf("%s", dataname);
			if(dataname[0]=='0')
				break;
			ne->number=datanum;
			for(i=0; i<Max; i++)
			{
				ne->name[i]=dataname[i];
			}
			ne->next=NULL;
			pointer->next=ne;
			pointer=ne;
		}

	}
	return head;
}


int main()
{
	int i;
	Link head;
	head=creat(head);
	printf("\n############################\n\n");
	if(head!=NULL)
		prin(head);
	char key[Max];
	printf("\n############################\n");
	printf("\nPlease input the keyname:  ");
	scanf("%s", key);
	printf("\n############################\n");
	if(search(head, key))
	{
		printf("\nYes!\nsearchtime=  %d\n", searchtime);
	}
	else
		printf("NO FIND!!\n");
	if(head!=NULL)
		free(head);
	return 0;
}
