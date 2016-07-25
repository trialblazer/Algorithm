#include "Calculate.h"
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

int Calculate::priority(char data) {
    int prio = 0;
    switch(data) {
    case '+':
    case '-':
        prio = 1;break;
    case '*':
    case '/':
        prio = 2;break;
    case '(':
        tag = true; break;
    case ')':
        tag = false; break;
    default:
        printf("Wrong input!\n");
        system("pause");
        exit(1);
    }
    if (tag)
        prio += 3;
    return prio;
}

void Calculate::exchange() {
    int i, m, n;
    char data, t;
    tag = false;
    size = 0;
    for (i=0; i<len; i++) {
        if (ar[i] >= '0' && ar[i] <= '9') {
            a.push(ar[i]);
        }
        else {
            int prio = priority(ar[i]);
            if (ar[i] == '(' || ar[i] == ')')
                continue;
            if (prio > pr[size-1] || b._empty()) {
                b.push(ar[i]);
                pr[size++] = prio;
            } else {
            loop:b.pop(data);
                size--;
                a.push(data);
                if (prio > pr[size-1] || b._empty()) {
                    b.push(ar[i]);
                    pr[size++] = prio;
                } else {
                    goto loop;
                }
            }
        }
    }
    while (!b._empty()) {
        b.pop(data);
        a.push(data);
    }
}

void Calculate::calculate() {
loop:printf("Please input the arithmetic expressions: ");
    scanf("%s", ar);
    len = strlen(ar);
    if (len > Max) {
        printf("Wrong input!\n\n");
        goto loop;
    }
    exchange();

    char data;
    int m, n;
    while (!a._empty()) {
        a.pop(data);
        b.push(data);
    }
    Stack<int> p;
    while (!b._empty()) {
        b.pop(data);
        if (data >= '0' && data <= '9')
            p.push((int)data-48);
        else {
            p.pop(m);
            p.pop(n);
            switch(data) {
            case '+':
                m += n; break;
            case '-':
                m -= n; break;
            case '*':
                m *= n; break;
            case '/':
                m /= n; break;
            default:
                printf("error!\n\n");
                system("pause");
            }
            p.push(m);
        }
    }
    p.pop(m);
    printf("The result is: %d\n", m);
}
