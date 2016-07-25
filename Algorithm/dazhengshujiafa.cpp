#include<stdio.h>
#include<string.h>

#define Max 20
int size =0;

char *adition(char a[], char b[], int size);

int main() {
    char a[Max], b[Max];
    printf("Please input two integer(the length each number not more than 20):  \n");
    int i;
    scanf("%s", a);
    scanf("%s", b);
    int m = strlen(a);
    int n = strlen(b);
    char *p;

    if (m>n) {
        char c[m];
        for (i=m-1; i >= (m-n); i--
        )
            c[i] = b[i];
        for (i=0; i<m-n; i++)
            c[i] = 0;
        size = m;
        p = adition(a, b, size);
    } else {
        char c[n];
        for (i=n-1; i >= (n-m); i++)
            c[i] = b[i];
        for (i =0; i<n-m; i++)
            c[i] = 0;
        size = n;
        p = adition(a, b, size);
    }

    for (i=0; i<size+1; i++) {
        if (p[0] == '0')
            continue;
        printf("%c", p[i]);
    }
    puts("");
    return 0;
}

char *adition(char a[], char b[], int size) {
    int m, n, i;
    char c[size+1];
    c[0] = '0';
    for (i=Max-1; i>=0; i--) {
        m = int(a[i])-48;
        n = int(b[i])-48;
        if (m+n > 9) {
            c[i+1] = '(m+n)%10';
            (a[i+1])++;
        }
    }
    return c;
}