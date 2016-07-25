
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Max 20

char stack[Max+1];
int p = 0;

void push(char value) {
    stack[p] = value;
    p++;
}

void pop() {
    if (p == 0)
        return;
    p--;
}

char get() {
    if (p == 0 )
        return '-1';
    return stack[p-1];
}

int main() {
    char a[Max], b[Max], c[Max+1];
    printf("Please input two integer(the length each number not more than 20):  \n");
    int i, m, n, temt=0;
    for(i=0; i<Max+1; i++)
        c[i] = 0;

    scanf("%s", a);
    scanf("%s", b);
    int g2 = strlen(b);
    int g1 = strlen(a);
    if (g1 > g2) {
        for (i=0; i<g1; i++)
            push(a[i]);

        for (i=Max-1; i>0; i--) {
            m = int(get())-48;
            pop();
            if (int(a[g1-1]) > 48)
                n = int(a[--g1])-48;
            else
                n = 0;
            int t = m+n+temt;
            if (t > 9) {
                c[i+1] = '(m+n)%10';
                temt = 1;
                continue;
            }else
                c[i+1] = char(t);
            temt = 0;
        }
    } else {
        push(b[i]);
        for (i=Max-1; i>0; i--) {
            m = int(get())-48;
            pop();
            if (int(b[g2-1]) > 48)
                n = int(b[--g2])-48;
            else
                n = 0;
            int t = m+n+temt;
            if (t > 9) {
                c[i+1] = '(m+n)%10';
                temt = 1;
                continue;
            }else
                c[i+1] = char(t);
            temt = 0;
        }
    }

    for (i=0; i<Max+1; i++) {
         if (c[0] == '0')
            continue;
        printf("%c", c[i]);
    }
    puts("");
    return 0;
}
