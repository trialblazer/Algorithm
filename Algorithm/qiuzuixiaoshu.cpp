#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

#include <algorithm>

#define MAX 10

using namespace std;

int main()
{
    vector<int> l;
    srand(time(NULL));
    for (int i=0; i<MAX; i++)
        l.push_back(rand() % (MAX * 10));

    vector<int>::iterator it = l.begin();
    while (it != l.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    cout << "min : " << *min_element(l.begin(), l.end()) << endl;

    return 0;
}