#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MIN 1
#define MAX 30
#define LEN sizeof(struct Hotel)

typedef struct Hotel
{
    int room_num;
    char name[20];
    char sex[10];
    int paid;
    int inyear;
    int inmonth;
    int inday;
    struct Hotel *next;
} Hotel, *Link_Hotel;

bool login();
char menu_select();
void regeist();
void search_num();
void show_all();
void search_name();
void change();
void fire();
bool check(int n);
Link_Hotel load();

void _free(Link_Hotel head)
{
    Link_Hotel p = head;
    while (p != NULL)
    {
        head = head->next;
        free(p);
        p = head;
    }
}

bool login()
{
    int i=0,k=0;
    while (1)
    {
        system("cls");
        printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
        char password[7]="123456", a[7];
        if (k == 3) {
            printf("\n\n                        �Ƿ��û���ֹ��½!\n");
            break;
        }
        printf("\n                        ����������: ");
        for(i=0; i<6; i++)
        {
            a[i]=getch();
            printf("*");
        }
        a[6]='\0';
        printf("\n");
        int tmpt = strcmp(password,a);
        if(tmpt != 0)
        {
            k++;
            printf("\n\n                                         �����������������!\n");
            Sleep(1000);
        }
        else
        {
            if(tmpt==0)
                return true;
        }
    }
    return false;
}
char menu_select()
{
    system("cls");
    char select;
    printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
    printf("                            1.������ס\n");
    printf("                            2.�鿴ĳһ������Ϣ\n");
    printf("                            3.����ĳһ������Ϣ\n");
    printf("                            4.�鿴������Ϣ\n");
    printf("                            5.���˻���\n");
    printf("                            6.�����˷�\n");
    printf("                            7.�˳�����ϵͳ\n");
    printf("            ----------------------------------------------\n\n");
    select=getch();
    return select;
}
void regeist()
{
    FILE *fp;
    if((fp=fopen("information.txt","a+"))==NULL)
    {
        printf("�޷����ļ�!\n");
        Sleep(1000);
        return;
    }
    char ch;
    int num;
    Hotel p1;
    while (1)
    {
        system("cls");
        printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
        printf("\n            ��ӭ��ס,��Ǽ���ס��Ϣ:\n");
        printf("\n                    �����(%d-%d):",MIN,MAX);
        scanf("%d",&num);
        if(num<MIN||num>MAX)
        {
            printf("\a\n                                        ����!");
            fclose(fp);
            Sleep(1000);
        }
        if (!check(num))
        {
            Sleep(1000);
            fclose(fp);
            return;
        }
        p1.room_num=num;
        printf("\n                      ס����:");
        scanf("%s",p1.name);
        printf("\n                      �Ա�:");
        scanf("%s",p1.sex);
        printf("\n                      ����:");
        scanf("%d",&p1.paid);
        printf("\n                      ��ס���ڣ��ո������:");
        scanf("%d %d %d",&p1.inyear,&p1.inmonth,&p1.inday);
        p1.next=NULL;
        if (fwrite(&p1,LEN,1,fp) != 1)
            printf("�ļ�д��ʧ��\n");
        printf("\n\n��ѡ���Ƿ�����Ǽ���ס��Ϣ(y/n):");
loop:
        ch = getch();
        switch(ch)
        {
        case 'n':
        case 'N':
            fclose(fp);
            printf("\n\n                                          �Ǽ�ס����ס��Ϣ�ɹ�!");
            system("pause");
            return;
        case 'y':
        case 'Y':
            break;
        default:
            goto loop;
        }
    }
}
void search_num()
{
    char ch;
    int room_num;
    Link_Hotel head, pa;
    head=load();
    while (1)
    {
        system("cls");
        printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
        printf("\n                 ��������Ҫ�鿴�ķ����(%d-%d):",MIN,MAX);
        scanf("%d",&room_num);
        system("cls");
        printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
        pa=head;
        if(room_num<MIN||room_num>MAX)
        {
            printf("\n\n                                                 û�и÷���!");
            _free(head);
            Sleep(1000);
            head = NULL;
            return;
        }
        while (pa != NULL)
        {
            if(room_num == pa->room_num)
            {
                printf("\n\n                      �����:\t%d",pa->room_num);
                printf("\n\n                      ס����:\t%s",pa->name);
                printf("\n\n                      �Ա�:\t%s",pa->sex);
                printf("\n\n                      ����:\t%d",pa->paid);
                printf("\n\n                      ��ס����:\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
                printf("\n\n\n��ѡ���Ƿ�����鿴��Ϣ(y/n):");
loop:
                ch = getch();
                if (ch == 'y' || ch == 'Y')
                    break;
                switch(ch)
                {
                case 'n':
                case 'N':
                    return;
                default:
                    goto loop;
                }
            }
            pa=pa->next;
        }
        if (pa == NULL)
            printf("\n\n                       �÷��仹û������ס!");
        Sleep(1000);
    }
}
void show_all()
{
    Link_Hotel  head, pa;
    head=load();
    pa=head;
    system("cls");
    printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
    if (pa == NULL)
    {
        printf("              ���ڻ�û����ס��Ϣ");
        printf("\n\n\n                                       ");
        system("pause");
        return;
    }
    printf("\n\n            ���пͻ�����Ϣ����:\n");
    while(pa != NULL)
    {
        printf("\n                      �����:\t%d",pa->room_num);
        printf("\n                      ס����:\t%s",pa->name);
        printf("\n                      �Ա�:\t%s",pa->sex);
        printf("\n                      ����:\t%d",pa->paid);
        printf("\n                      ��ס����:\t%d %d %d\n",pa->inyear,pa->inmonth,pa->inday);
        pa=pa->next;
    }
    _free(head);
    head = NULL;
    printf("\n\n                                                         ");
    system("pause");
}
void search_name()
{
    char ch;
    char inname[20];
    Link_Hotel head,pa;
    head=load();
    while (1)
    {
        system("cls");
        printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
        printf("\n            ��������Ҫ�鿴�Ŀͻ�����(��0�˳�):");
        scanf("%s",inname);
        if (strcmp("0", inname) == 0)
            break;
        system("cls");
        printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
        pa=head;
        while (pa != NULL)
        {
            if(strcmp(inname,pa->name)==0)
            {
                printf("\n                      �����:\t%d\n",pa->room_num);
                printf("\n                      ס����:\t%s",pa->name);
                printf("\n\n                      �Ա�:\t%s",pa->sex);
                printf("\n\n                      ����:\t%d",pa->paid);
                printf("\n\n                      ��ס����:\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
                printf("\n\n\n    ��ѡ���Ƿ�����鿴��Ϣ(y/n):\n");
loop:
                ch = getch();
                if (ch == 'y' || ch == 'Y')
                    break;
                switch(ch)
                {
                case 'n':
                case 'N':
                    _free(head);
                    return;
                default:
                    goto loop;
                }
            }
            pa=pa->next;
        }
        if (pa == NULL)
        {
            printf("\n\n                                     û�в鵽��ס����Ϣ!");
            Sleep(1000);
        }
    }
}

void change()
{
    int room_num, newroom_num;
    FILE *fp;
    Hotel tmpt;
    Link_Hotel head =  NULL, pb = NULL;
    char ch;
    int sign = 0, s = 0;
    system("cls");
    printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
    printf("\n            ��������Ҫ�����ķ����(%d-%d)<��0�˳�>:",MIN,MAX);
    scanf("%d",&room_num);
    if (room_num == 0)
        return;

    printf("            ��������Ҫ�����ķ����(%d-%d)<��0�˳�>:",MIN,MAX);
    scanf("%d",&newroom_num);
    if (newroom_num == 0)
        return;
    if(newroom_num<MIN||newroom_num>MAX||newroom_num == room_num || room_num<MIN||room_num>MAX)
    {
        printf("\a\n                                                   ����!");
        return;
    }
    if((fp=fopen("information.txt","rb"))==NULL)
    {
        printf("                      �޷����ļ�!\n");
        Sleep(1000);
        return;
    }
    while (1)
    {
        Link_Hotel tmpt =  (Link_Hotel)malloc(LEN);
        if (tmpt == NULL)
        {
            printf("                          error!\n");
            if (sign == 0)
                free(tmpt);
            else
                _free(head);
            return;
        }
        if (fread(tmpt, LEN, 1, fp) == 0)
            break;
        if (tmpt->room_num == newroom_num)
        {
            printf("\n\n                          %d�����Ѿ�������ס����Ǹ!\n\n", newroom_num);
            Sleep(1500);
            fclose(fp);
            return;
        }
        if (tmpt->room_num == room_num)
        {
            s = 1;
            printf("\n\n                      �����:\t%d",tmpt->room_num);
            printf("\n                      ס����:\t%s",tmpt->name);
            printf("\n                      �Ա�:\t%s",tmpt->sex);
            printf("\n                      ����:\t%d",tmpt->paid);
            printf("\n                      ��ס����:\t%d-%d-%d\n\n",tmpt->inyear,tmpt->inmonth,tmpt->inday);
            tmpt->room_num = newroom_num;
            s = 1;
        }
        if (sign == 0)
        {
            head = tmpt;
            pb = head;
            sign = 1;
        }
        else
        {
            pb->next = tmpt;
            pb = pb->next;
        }
    }
    if (pb != NULL)
        pb->next=NULL;
    fclose(fp);

    if (s == 0)
    {
        printf("\n\n                                            û�в��ҵ����ˣ�\n\n");
        Sleep(1000);
        return;
    }
    printf("             ȷ�ϸ���(y/n)?\n");
loop:
    ch = getch();
    switch(ch)
    {
    case 'y':
    case 'Y':
        break;
    case 'n':
    case 'N':
        _free(head);
        return;
    default:
        goto loop;
    }
    if((fp=fopen("information.txt","w"))==NULL)
    {
        printf("�޷����ļ�!\n");
        Sleep(1000);
        _free(head);
        return;
    }
    while (head != NULL)
    {
        if (fwrite(head,LEN,1,fp) != 1)
        {
            printf("�ļ�д��ʧ��\n");
            Sleep(1500);
            fclose(fp);
            _free(head);
            return;
        }
        head = head->next;
    }
    puts("");
    printf("                                       �����ɹ���");
    fclose(fp);
    system("pause");
    _free(head);
}


void fire()
{
    char inname[20], ch;
    FILE *fp;
    Link_Hotel tmpt, head =  NULL, pb = NULL;
    int sign = 0, s = 0;
    system("cls");
    printf("\n\n            -----------��ӭʹ�þƵ���Ϣ����ϵͳ-----------\n\n");
    printf("\n             ��������Ҫ�˷��Ŀ�������(��0�˳�):");
    scanf("%s",inname);
    if (strcmp(inname, "0") == 0)
        return;
    if((fp=fopen("information.txt","rb"))==NULL)
    {
        printf("                      �޷����ļ�!\n");
        getch();
        return;
    }
    while (1)
    {
        tmpt = (Link_Hotel)malloc(LEN);
        if (tmpt == NULL)
        {
            if (sign == 0)
                free(tmpt);
            else
                _free(head);
            printf("\n\n                                           error!\n");
            return;
        }
        if (fread(tmpt, LEN, 1, fp) == 0)
            break;
        if (strcmp(inname, tmpt->name) == 0)
        {
            s = 1;
            printf("\n\n                      �����:\t%d",tmpt->room_num);
            printf("\n                      ס����:\t%s",tmpt->name);
            printf("\n                      �Ա�:\t%s",tmpt->sex);
            printf("\n                      ����:\t%d",tmpt->paid);
            printf("\n                      ��ס����:\t%d %d %d\n\n",tmpt->inyear,tmpt->inmonth,tmpt->inday);
            printf("             ȷ���˷�(y/n)?\n");
loop:
            ch = getch();
            switch(ch)
            {
            case 'y':
            case 'Y':
                break;
            case 'n':
            case 'N':
                if (sign == 0)
                    free(tmpt);
                else
                    _free(head);
                return;
            default:
                goto loop;
            }
            continue;
        }
        if (sign == 0)
        {
            head = tmpt;
            pb = head;
            sign = 1;
        }
        else
        {
            pb->next = tmpt;
            pb = pb->next;
        }
    }
    if (pb != NULL)
        pb->next=NULL;
    fclose(fp);

    if (s == 0)
    {
        printf("\n\n                                            û�в��ҵ����ˣ�\n\n");
        Sleep(1000);
        _free(head);
        return;
    }

    if((fp=fopen("information.txt","w"))==NULL)
    {
        printf("�޷����ļ�!\n");
        Sleep(1000);
        _free(head);
        return;
    }
    int num;
    Hotel p1;
    while (head != NULL)
    {
        if (fwrite(head,LEN,1,fp) != 1)
        {
            printf("�ļ�д��ʧ��\n");
            Sleep(1500);
            fclose(fp);
            _free(head);
            return;
        }
        head = head->next;
    }
    puts("");
    printf("                                       �˷��ɹ���");
    fclose(fp);
    system("pause");
    _free(head);
}

bool check(int n)
{
    FILE *fp;
    Hotel tmpt;
    if((fp=fopen("information.txt","rb"))==NULL)
    {
        printf("�޷����ļ�!\n");
        getch();
        exit(0);
    }
    while(fread(&tmpt, LEN, 1, fp))
    {
        if (tmpt.room_num == n)
        {
            printf("\n\n                                  %d�ŷ����Ѿ��п�����!\n",n);
            fclose(fp);
            return false;
        }
    }
    fclose(fp);
    return true;
}
Link_Hotel load()
{
    FILE *fp;
    Link_Hotel s = NULL, pb = NULL, head;
    if((fp=fopen("information.txt","rb"))==NULL)
    {
        printf("�޷����ļ�!\n");
        getch();
        fclose(fp);
        return NULL;
    }
    s =(Link_Hotel )malloc(LEN);
    if(s==NULL)
    {
        printf("�ڴ����ʧ��!\n");
        getch();
        fclose(fp);
        return NULL;
    }
    if (fread(s, LEN, 1, fp) == 0)
    {
        head = NULL;
        return head;
    }
    head = s;
    pb = s;
    while(1)
    {
        s =(Link_Hotel )malloc(LEN);
        if(s==NULL)
        {
            printf("�ڴ����ʧ��!\n");
            getch();
            fclose(fp);
            return NULL;
        }
        if (fread(s,LEN,1,fp) == 0)
        {
            free(s);
            break;
        }
        pb->next = s;
        pb = pb->next;
    }
    pb->next=NULL;
    fclose(fp);
    return head;
}
int main()
{
    FILE *fp;
    if ((fp = fopen("information.txt","rb"))==NULL)
    {
        if ((fp = fopen("information.txt", "w")) !=  NULL)
            fclose(fp);
    }
    char choice;
    if (login())
    {
        system("cls");
        while (1)
        {
            choice=menu_select();
            switch(choice)
            {
            case '1':
                regeist();
                break;
            case '2':
                search_num();
                break;
            case '3':
                search_name();
                break;
            case '4':
                show_all();
                break;
            case '5':
                change();
                break;
            case '6':
                fire();
                break;
            case '7':
                exit(0);
                break;
            }
        }
    }
    return 0;
}



