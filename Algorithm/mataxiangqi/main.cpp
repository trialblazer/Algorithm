#include <stdio.h>
#include <windows.h>

#define Max 16

typedef struct ListNode{
    int X;
    int Y;
    int sign;   /// 当前节点的数据是上一个节点加p[sign]后的值，即x = x1+p[sign].x; y = x2+p[sign].y
    struct ListNode* Next;
}ListNode, *Link;
///用链表来模拟栈，
struct List{
    Link head;
    Link tail;

    List();
    ~List();
    bool isEmpty() {return (head->Next == tail);}
    bool push(int m, int n, int s);
    bool pop();
    void prin();
    void getfront(int &x, int &y);
    int getsign();
};

List::List() {
    head = (Link)malloc(sizeof(ListNode));
    if (head == NULL) {
        printf("Memory allocate failure!!");
        Sleep(3000);
        exit(1);
    }
    tail = NULL;
    head->X = -1;
    head->Y = -2;
    head->sign = -1;
    head->Next = tail;
}

List::~List() {
    while (isEmpty())
        pop();
}

bool List::push(int m, int n, int s) {
    Link add = (Link)malloc(sizeof(ListNode));
    if (add == NULL) {
        printf("Memory allocate failure!!");
        Sleep(3000);
        return false;
    }
    add->X = m;
    add->Y = n;
    add->sign = s;
    add->Next = head->Next;
    head->Next = add;
    return true;
}

bool List::pop() {
    if (isEmpty())
        return false;
    Link tmpt = head->Next;
    head->Next = tmpt->Next;
    free(tmpt);
    return true;
}
/// 打印链表
void List::prin() {
    Link pointer = head->Next;
    while (pointer != NULL) {
        printf("[%d,%d]", pointer->X, pointer->Y);
        if (pointer->Next != NULL)
            printf("-->");
        pointer = pointer->Next;
    }
}
/// 获取栈顶元素的标记
int List::getsign() {
    Link pointer = head->Next;
    return pointer->sign;
}
/// 获取栈顶的元素
void List::getfront(int &x, int &y) {
    x = head->Next->X;
    y = head->Next->Y;
}




/// 棋盘结构体
typedef struct Chess{
    struct Array{
        int x;
        int y;
    }p[8];              /// 辅助数组
    struct List Stack;  /// 保存路径的栈
    int l;              /// 棋盘的长
    int w;              /// 棋盘的宽
    int enter_x;        /// 入口坐标x
    int enter_y;        /// 入口坐标y
    int out_x;          ///出口坐标x
    int out_y;          /// 出口坐标y
    int a[Max][Max];    /// 棋盘数组
    int count;          ///已经踏过点的个数

    int num;            ///解的个数

    Chess(int rl, int rw, int ex, int ey, int ox, int oy);
    ~Chess() {}

    int _solve_chess(int x, int y);
    void _solve_chess();
    void solve_chess() {_solve_chess(out_x, out_y);}
}Chess;

Chess::Chess(int rl, int rw, int ex, int ey, int ox, int oy) {
    p[0] = {-1,-2};   p[1] = {-2,-1}; p[2] = {-2,1};
    p[3] = {-1,2};  p[4] = {1,2};   p[5] = {2,1};
    p[6] = {2,-1};  p[7] = {1,-2};
    for (int i=0; i<Max; i++)
        for (int j=0; j<Max; j++)
            a[i][j] = 0;
    l = rl;
    w = rw;
    enter_x = ex;
    enter_y = ey;
    out_x = ox;
    out_y = oy;
    count = 0;
    num = 0;
}

/// 解法1）
int Chess::_solve_chess(int x, int y) {
    Stack.push(x, y, 0);
    count++;

    if (x>=l || x<0 || y>=w || y<0)
        return 0;
    if (a[x][y] != 0)
        return 0;

    a[x][y] = l*w-count+1;

    int i, j, t1, t2;
    if (x==enter_x && y==enter_y && count == l*w) {
        if (num == 0)
            printf("\nThe result is: \n\n");
        printf("%d:\n", num+1);
        for (i=0; i<l; i++) {
            for(j=0; j<w; j++)
                printf("%-3d ", a[i][j]);
            puts("");
        }
        printf("\n\n");
        num++;
        return 1;
    }
    t1 = x;
    t2 = y;
    for (i=0; i<8; i++) {
        if (x<l || x>=0 || y<w || y>=0) {
            x = p[i].x + t1;
            y = p[i].y + t2;
            int t = _solve_chess(x, y);
            Stack.pop();
            count--;
            if (t == 1)
                a[x][y] = 0;
        }
    }
    return 1;
}

///（解法2）
void Chess::_solve_chess() {
    count = 0;
    int i, j, t1, t2;
    int p1, q1;
    int x = out_x, y = out_y;
    Stack.push(x, y, -1);
    count++;
    a[x][y] = l*w-count+1;

    while (1) {
        int sign = 0;
        if (count == l*w)
            break;
        t1 = x;
        t2 = y;
        for (i = 0; i<8; i++) {
         loop:x = p[i].x + t1;
            y = p[i].y + t2;
            if (x>=l || x<0 || y>=w || y<0)
                continue;
            if (count != l*w-1 && x==enter_x && y==enter_y)
                continue;
            if (a[x][y] != 0)
                continue;
            Stack.push(x,  y, i);
            count++;
            a[x][y] = l*w-count+1;
            sign = 1;
            break;
        }
        if (sign)
            continue;
        i = Stack.getsign()+1;
        Stack.getfront(t1, t2);
        a[t1][t2] = 0;
        Stack.pop();
        count--;
        if (count == 0)
            break;
        Stack.getfront(t1, t2);
        goto loop;
    }
    if (count == l*w)
        num++;

    printf("\n\n");
    for (i=0; i<l; i++) {
        for(j=0; j<w; j++)
            printf("%-3d ", a[i][j]);
        puts("");
    }
    printf("\n\n");
}



/// 算法一的测试函数
void check1(int a, int b, int c, int d, int e, int f) {
    Chess q(a,b,c,d,e,f);
    q.solve_chess();
    if(q.num == 0)
        printf("The horse can't walk the chessboard!\n\n");
}

/// 算法二的测试函数
void check2(int a, int b, int c, int d, int e, int f) {
    Chess q(a,b,c,d,e,f);
    q._solve_chess();
    if(q.num == 0)
        printf("The horse can't walk the chessboard!\n\n");
}

int main() {
    int l, w, entX, entY, outX, outY, i, j;
    printf("Please input the lenth and the width of the chesspoard(don't over %d):", Max);
    scanf("%d", &l);
    scanf("%d", &w);
    printf("Please inpu the starting position coordinates: ");
    scanf("%d", &entX);
    scanf("%d", &entY);
    printf("Please input the end position corrdinates: ");
    scanf("%d", &outX);
    scanf("%d", &outY);
    Chess q(l, w, entX, entY, outX, outY);

    check1(l,w,entX,entY,outX,outY);
    check2(l,w,entX,entY,outX,outY);
    return 0;
}

































