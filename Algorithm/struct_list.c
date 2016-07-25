#include<stdlib.h>
#define Max 10
struct List
{
    int number;
    char name[Max];
    struct List *next;
};
//typedef struct list node;
typedef struct List Node;
typedef Node *Link;

void free_List(Link head)
{
    Link pointer;
    //while(pointer!=NULL)
    while(head!=NULL)
    {
        pointer=head;
        head=head->next;
        free(pointer);
    }
}

void prin_List(Link head)
{
    Link pointer;                           // while(head!=NULL)
    pointer=head;                           // {
    while(pointer!=NULL)                    //     printf("\n%d\n", head->number);
                                            //    printf("%s", head->name);
    {                                       //    head=head->next;
        //pointer=head;                     // }
        printf("\n%d\n", pointer->number);
        printf("%s", pointer->name);
        //head=head->next;
        pointer=pointer->next;
    }
}

Link create_List(Link head)
{
    int datanum;
    char dataname[Max];
    Link pointer;
    int i;
    head=(Link)malloc(sizeof(Node));
    if(head==NULL)
        printf("Memory allocate failure");
    else
    {
        datanum=1;
        printf("please input the dataname:  ");
        scanf("%s", dataname);
        head->number=datanum;
        for(i=0; i<Max; i++)
            head->name[i]=dataname[i];
        head->next=NULL;
        pointer=head;
        while(1)
        {
            Link new;
            datanum++;
            new=(Link)malloc(sizeof(Node));
            printf("please input the dataname:  ");
            scanf("%s", dataname);
           // if(dataname[0]='0')
            if(dataname[0]=='0')
                break;

            new->number=datanum;
            for(i=0; i<Max; i++)
                new->name[i]=dataname[i];
            new->next=NULL;
            pointer->next=new;
            pointer=new;
        }
    }
    return head;
}

/*Link reverse(Link head)
{
    // head 上一个节点
    // head的tmp 下一个节点
    Link tmp = head->next;
    head->next = NULL;

    while (tmp!= NULL)
    {
        tmp->next = head;
        head = tmp;
        tmp = tmp->next;
    }
    return head;
}*/
Link reverse(Link head)
{
    puts("");         //换行
    // head 上一个节点
    // head的tmp 下一个节点
    Link tmp = head->next;
    head->next = NULL;
    puts("");
    while (tmp!=NULL)
    {
        Link temp_next = tmp->next;
        tmp->next = head;
        head = tmp;
        tmp = temp_next;
        //puts(tmp->name);

    }
    return head;
}



int main()
{
    Link head;

    head=create_List(head);

    //while(head!=NULL)
    if(head!=NULL)
    {
        prin_List(head);

    }


    head=reverse( head);
    if(head!=NULL)
    {
        puts("not NULL");
        prin_List(head);
        free_List(head);
    }
    return 0;
}
