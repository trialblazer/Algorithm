#include<stdio.h>

#define Max 10
int i;
struct List
{
    int num;
    int total;
    struct List *next;
};
typedef struct List node;
typedef node *Link;


void print_List(Link Head)
{
    Link pointer;
    pointer=Head;
    while(pointer!=NULL)
    {
        printf("%d   ", pointer->num);
        printf("%d\n", pointer->total);
        pointer=pointer->next;
    }
}


void free_List(Link head)
{
    Link pointer;
    while(head!=NULL)
    {
        pointer=head;
        head=head->next;
        free(pointer);
    }
}

int search_List(int key, Link head)
{
    int i=0;
    Link pointer;
    pointer=head;
    while(pointer!=NULL)
    {
        i++;
        if(pointer->total==key)
        {
            printf("%d     ", pointer->num);
            printf("%d\n", pointer->total);
            return 1;
        }
        pointer=pointer->next;
    }
    return 0;
}


Link creat_List(Link head)
{
    Link pointer;
    Link new;
    int datanum;
    int datata;
    head=(Link)malloc(sizeof(node));
    if(head==NULL)
        printf("Memory allocate failure!!");
    else
    {
        datanum=1;
        printf("please input the datata:   ");
        scanf("%d", &datata);
        head->num=datanum;
        head->total=datata;
        head->next=NULL;
        pointer=head;
        i=0;
        while(i<Max)
        {
            datanum++;
            new=(Link)malloc(sizeof(node));
            printf("please input the datata:   ");
            scanf("%d", &datata);
            new->num=datanum;
            new->total=datata;
            new->next=NULL;
            pointer->next=new;
            pointer=new;
            i++;
        }
    }
    return head;
}

int main()
{
    Link head;
    head=creat_List(head);

    if(search_List(89, head))
        printf("i=%d\n", i);
    else
        printf("NO FIND!!!\n");

    if(head!=NULL)
    {
       print_List(head);
        free_List(head);
    }
}




