
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void f(string& str) {
    int size_bg, bg, ed;
    while (1) {
        size_bg = str.find_first_of(" ");
        if (size_bg == string::npos)
            break;
        ed = str.find_first_not_of(" ", size_bg);
        if (ed == string::npos) {
            str.erase(size_bg, str.size()-size_bg);
            break;
        }
        str.erase(size_bg, ed-size_bg);
    }
}

int main() {
    string str("   how   are  your   ?   ");
    f(str);
    cout << str << endl;
    return 0;
}

