#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <time.h>
#include <cstring>
#include <numeric>
#include <vector>

using namespace std;

#define SIZE 15      //硬币数量
#define WEIGHT 1     //真币重量
#define NORMAL 0     //伪币重量

int findCorn(int a[], int begin, int end) {
    static int count = 0;
    if (begin+1 == end)
        return begin;
    cout << "第" << ++count << "次查找" << endl;
    int mid = (begin+end)/2;
    vector<int> v1(a+begin, a+mid), v2(a+mid, a+end);
    int t1 = accumulate(v1.begin(), v1.end(), 0), t2 = accumulate(v2.begin(), v2.end(), 0);
    return t1>t2? findCorn(a, begin, mid):(t1==t2)? -1:findCorn(a, mid, end);
}

int main() {
    int a[SIZE] = {NORMAL};
    srand(time(NULL));
    int tmpt = rand()%16;
    a[tmpt] = WEIGHT;

    cout << "硬币为： ";
    for (int i=0; i<SIZE; i++)
        cout << a[i] << "  " ;
    cout << endl;

    if (SIZE%2 == 0)
        tmpt = findCorn(a, 0, SIZE) + 1;
    else {
        tmpt = findCorn(a, 0, SIZE-1);
        tmpt = (tmpt == -1? SIZE-1:tmpt)+1;
    }
    cout << "伪币为第" << tmpt << "个" << endl;
    return 0;
}
