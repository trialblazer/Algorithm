#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int find_(char* s, char* p, int begin) {
    int si = begin, pi = 0, slen = strlen(s), plen = strlen(p);
    if (begin < 0 || begin > slen || p == NULL || s == NULL)
        return -1;
    for (; si<slen; si++) {
        for (pi = 0; pi<plen; pi++) {
            if (s[si+pi] != p[pi])
                break;
        }
        if (pi == plen)
            return si;
    }
    return -1;
}

int kmp(char* s, char* p, int next[], int begin) {
    int si = begin, pi = 0, slen = strlen(s), plen = strlen(p);
    if (begin < 0 || begin > slen || p == NULL || s == NULL)
        return -1;
    while (si < slen &&  pi < plen) {
        /*if (s[si] == p[pi]) {
            si++;
            pi++;
        } else {
            pi = next[pi];
            if (pi == -1) {
                si++;
                pi++;
            }
        }
        //*/
        if (s[si] == p[pi] || pi == -1) {
            si++;
            pi++;
        } else {
            pi = next[pi];
        }
    }
    if (pi == plen)
        return si-plen;
    return -1;
}

void getNext(char* p, int next[]) {
     int plen = strlen(p), pb = -1, pe = 0;
     next[0] = -1;
     while (pe < plen) {
        if (p[pb] == p[pe] || pb == -1) {
            pb++;
            pe++;
            next[pe] = pb;
        } else {
            pb = next[pb];
        }
     }
}

int Find(char* s, char* p, int begin) {
    int plen = strlen(p), index = -2;
    int* next = new int[plen];
    if (next == NULL) {
        cout << "error" << endl;
        return index;
    }
    getNext(p, next);
    index = kmp(s, p, next, begin);
    delete []next;
    return index;
}

int main() {
    char a[] = "ababcabcacbab";
    char b[] = "ab";
    int begin = 0;
    for (begin = 0; begin < 10; begin++) {
        cout << find_(a, b, begin) << endl;
        cout << Find(a, b, begin) << endl << endl;
    }
    system("pause");
    return 0;
 }
