#include <iostream>
#include <string.h>
using namespace std;

char num[20];
char a[20][10]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};
char b[9][10] = {"","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty"};
char c[5][10] = {"","thousand","million","billion"};

void translate(int sign, int begin) {
    if (sign == -1)
    return;
    cout << a[(int)num[begin]-48] << " ";
    if ((int)num[begin] != 48)
        cout << "hundred ";
    if ((int)num[begin+1]-48 == 0) {
        if ((int)num[begin+2]-48 != 0) {
            cout << "and " << a[(int)num[begin+2]-48] << " ";
        }
    } else {
        cout << "and ";
        if ((int)num[begin+1] == 49)
            cout << a[(int)num[begin+2]-38] << " ";
        else
            cout << b[(int)num[begin+1]-48-1] << " " << a[(int)num[begin+2]-48] << " ";
    }
    if ((int)num[begin] != 48 || (int)num[begin+1] != 48 || (int)num[begin+2] != 48)
        cout << c[sign] << " ";
    translate(--sign, begin+3);
}
void translate1() {
    int i;
	for (i=0; i<strlen(num); i++)
		if (num[i] == '.') 
            break;
    int len = i;
    if (i > 12) {
        cout << "out of size!\n";
        return;
    }
    if ((int)num[0] == 48) {
        cout << "zero";
    } else {
        int bit1 = len%3, bit2 = len/3, tmpt = 0;
        if (bit1 == 1) {
            cout << a[(int)num[0]-48] << " ";
            tmpt  = 1;
        }
        if (bit1 == 2) {
            if ((int)num[0] == 49)
                cout << a[(int)num[1]-38] << " ";
            else
                cout << b[(int)num[0]-48-1] << " " << a[(int)num[1]-48] << " ";
            tmpt = 2;
        }
        if (bit1 != 0)
            cout << c[bit2] << " ";
        translate(--bit2, 0+tmpt);
    }
    if (i != strlen(num)) {
        cout << "point ";
        for (int j=i+1; j<strlen(num); j++) {
            if (num[j] == '0') {cout << "zero "; continue;}
            cout << a[(int)num[j]-48] << " ";
        }
    }
	cout << endl;
}
int main(void) {
	cout << "please input the number: ";
	cin >> num;
	if (strlen(num) > 20)
        cout << "out of size!";
    else
        translate1();
    cout << endl;
	return 0;
}