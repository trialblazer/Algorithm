#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define Maxsize 40

void sort(int* a, int begin, int end);

int main()
{
    srand(time(NULL));
    int a[Maxsize];
    for (int i=0; i<Maxsize; ++i) {
        a[i] = rand()*27%300;
        cout << a[i] << "  ";
    }
    cout << endl << endl;
    sort(a, 0, Maxsize);
    for (int i=0; i<Maxsize; i++)
        cout << a[i] << "  ";
	return 0;
}

void sort(int* a, int begin, int end) {
    int c[end];
    if (begin+1 != end) {
        const int mid = (begin+end)/2, n = begin;
        sort(a, begin, mid);
        sort(a, mid, end);
        int m = mid;
        ///for (int i=0; i<end; i++) {
        for (int i=n; i<end; i++) {
            if (begin == mid) {
                while (m < end) {
                    //c[i] = a[m++];
                    c[i++] = a[m++];
                }
            }
            if (m == end) {
                while (begin < mid) {
                    //c[i] = a[begin++];
                    c[i++] = a[begin++];
                }
            }
            ///c[i] = a[begin]>a[m]? a[m++]:a[begin++];
            else
                a[begin]>a[m]? c[i]=a[m++]:c[i]=a[begin++];
        }
        for (int i=n; i<end; i++)
            a[i] = c[i];
    }
}
