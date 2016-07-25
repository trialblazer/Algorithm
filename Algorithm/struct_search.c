#include<stdio.h>

#define Max 5

struct List
{
    int number;
    int total;
    struct List *next;
};
typedef struct List node;
typedef node *Link;


int data[2][Max]={1,2,3,4,5,6,7,8,9,10};
int searchtime=0;


int search_List(int key, Link head)
{
    Link pointer;
    pointer=head;
    while(pointer!=NULL)
    {
        searchtime++;
        if(pointer->total==key)
        {
            printf("data number: %d\n", pointer->number);
            printf("data total: %d\n" , pointer->total);
            return 1;
        }
        pointer=pointer->next;
    }
    return 0;
}


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



Link creat(Link head)
{
    Link pointer;
    Link new;
    int i;
    head=(Link)malloc(sizeof(node));
    if(head==NULL)
    {
        printf("The memory allocate failure!!");
    }
    else
    {
        head->number=data[0][0];
        head->total=data[1][0];
        head->next=NULL;
        pointer=head;
        for(i=0; i<Max; i++)
        {
            new=(Link)malloc(sizeof(node));
            new->number=data[0][i];
            new->total=data[1][i];
            new->next=NULL;
            pointer->next=new;
            pointer=new;
        }
    }
    return head;
}


int main()
{
    Link head;
    head=creat(head);
    if(search_List(10, head))
    {
        printf("srarchtime=%d ", searchtime);
    }
    else
    {
        printf("NO FIND!!");
    }
    if(head!=NULL)
    {
        free(head);
    }
}
