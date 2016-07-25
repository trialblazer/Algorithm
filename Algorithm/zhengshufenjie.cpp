#include <iostream>
#include <stdlib.h>

using namespace std;

/// 两个程序除了m为零时结果不同，其他都相同

/// 最小加数为一，
int f(int m, int max) {
    if (m < 1 || max < 1)
        return 0;
    if (m == 1 || m == 1)
        return 1;
    if (m < max)
        return f(m, m);
    if (m > max)
        return f(m, max-1)+f(m-max, max);
    return f(m, max-1)+1; ///m+0 算一次，在这个地方体现
}

/// 最小加数为零，
int g(int m, int max) {
    if (m<0 || max < 0) {
        cout << "m:" << m << endl << "max:" << max << endl;
        exit(1);
    }
    if (m <= 1 || max <= 1)
        return 1;
    if (m < max)
        return g(m, m);
    if (m > max)
        return g(m-max, max)+g(m, max-1);
    //if (m == max)
     //   g(m, max-1)+1;
    int sum = 0;
    for (int i=0; i<m; i++) {
        sum += g(i, m-i);
    }
    return sum;
}

int main() {
    for (int i=0; i< 50; i++) {
        cout << f(i, i) << endl;
        cout << g(i, i) << endl << endl;
    }
    return 0;
}


