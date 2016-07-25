#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

void Swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int perm(char a[], int begin, int end) {
    if (begin+1 == end) {
        cout << a << endl;
        return 1;
    }
    vector<char>v;
    unsigned sum = 0;
    for (int i=begin; i<end; i++) {
        vector<char>::iterator t = find(v.begin(), v.end(), a[i]);
        if (t != v.end())
            continue;
        //if (a[i] == a[begin] && i != begin)
          //  continue;
        v.push_back(a[i]);
        Swap(a[i], a[begin]);
        sum += perm(a, begin+1, end);
        Swap(a[i], a[begin]);
    }
    return sum;
}

int main() {
    char a[] = "abc", b[] = "ababca";
    cout << "perm:" << a << ":" << endl;
    cout << perm(a, 0, strlen(a)) << endl;;
    cout << "perm" << b << ":" << endl;
    cout << perm(b, 0, strlen(b)) << endl;
    return 0;
}

