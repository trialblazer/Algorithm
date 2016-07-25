#include <iostream>
#include <cstring>

using namespace std;

void _perm(char s[], int b, int e);
void perm(char s[]);

char a[] = "aab";

int main() {
    perm(a);
    return 0;
}

void perm(char s[]) {
    _perm(s, 0, strlen(s));
}

void _perm(char s[], int b, int e) {
    if (e-b == 1) {
        cout << s << endl;
        return;
    }
    for (int i=b; i<e; i++) {
        int sign = 0;
        for (int j=b; j<i; j++) {
            if (a[i] == a[j]) {
                sign = 1;
                break;
            }
        }
        if (sign == 0) {
            swap(a[i], a[b]);
            _perm(s, b+1, e);
            swap(a[i], a[b]);
        }
    }
}
