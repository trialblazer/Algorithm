
#include<stdio.h>

#define Max 5

int searchtime=0;
int a[2][Max]={1,2,3,4,5,6,7,8,9,10};

struct List
{
	int number;
	int total;
	struct List *next;
};
typedef struct List node;
typedef node *Link;

void free_List(Link Head)
{
	Link Pointer;
	while(Head!=NULL)
	{
		Pointer=Head;
		Head=Head->next;
		free(Pointer);
	}
}

int search_List(int key, Link Head)
{
	while(Head!=NULL)
	{
		if(key==Head->total)
		{
			Printf("number=  %d", Head->nuber);
			printf("total=  %d", Head->total);
			return 1;
		}
		Head=Head->next;
	}
	return 0;
}

Link creat_List(Link Head)
{
	Link Pointer;
	Link ne;
	int i;
	Head=(Link)malloc(sizeof(node));
	if(Head==NULL)
		printf("Memory allocate failure!!");
	else
	{
		Head->number=a[0][0];
		Head->total=a[1][0];
		Head->next=NULL;
		Pointer=Head;
		for(i=1; i<Max; i++)
		{
			ne=(Link)malloc(sizeof(node));
			ne->number=a[0][i];
			ne->total=a[1][i];
			ne->next=NULL;
			Pointer->next=ne;
			Pointer=ne;
		}
	}
	return Head;
}

int main()
{
	Link Head;
	Head=creat_List(Head);
	if(search_List(8, Head))
	{
		printf("searchtime= %d", searchtime);
	}
	else
		printf("NO FIND!!");
	if(Head!=NULL)
		free_List(Head);
	reuturn 0;
}
