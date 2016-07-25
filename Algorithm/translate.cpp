#include <iostream>
#include <string.h>

using namespace std;

char num[15];
char a[20][10] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};
char b[9][10] = {"","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty"};
char c[5][10] = {"","thousand","million","billion","hundred"};

void translate1(int end);
void translate2(int begin, int end);

int main(void) {
    for (int j=0; j<6; j++) {
	cout << "please input the number: ";
	cin >> num;
	int i, len = strlen(num);
	for (i=0; i<len; i++) {
		if (num[i] == '.')
			break;
	}
    translate1(i-1);
    if (i != len) {
        cout << "point ";
        for (int j=i+1; j<len; j++) {
            if (num[j] == '0') {cout << "zero "; continue;}
            cout << a[(int)num[j]-48] << " ";
        }
    }
	cout << endl;}
	return 0;
}

void translate1(int end) {
    if (end == 0 && (int)num[0] == 48) {cout << "zero "; return;}
	int len=end+1, bit1=len/3, bit2=len%3, p=bit2, begin=0, head=(int)num[begin]-48, sign=0, sign1=p;
	if (bit2 > 0) {
		if (bit2 == 1 || bit2 == 0) cout << a[head] << " ";
		else {
loop:       if (head == 0) cout << a[(int)num[begin+1]-48] << " ";
			else {
                if (head == 1) cout << a[(int)num[begin+1]-38] << " ";
                else cout << b[head-1 ] << " " << a[(int)num[begin+1]-48] << " ";
            }
			if (begin+2 == len) return;
		}
		if (sign != 0 || sign1 == 0) {p += 2; sign1 = 1;}
		//if (!(head == 0 && (int)num[begin+1] == 48 && (int)num[p-1] == 48)) {
            if (bit2 == 0) {cout << c[--bit1] << " ";}
            else {
                cout << c[bit1] << " ";
                if (sign == 0) {bit2 = 0; sign = 1;}
                else bit1--;
            }
      //  } else {
      //      bit1--;
       // }
	}
	//if (bit1 >= 0 && begin+2<=end) {
	if (bit1 >= 0 && bit2 == 0) {
        int j, t,tmpt=p;
		cout << a[(int)num[p]-48] << " ";
       // for (j=p+1; j<=end; j++)
       //     if (num[j] != '0')  break;
       while(1) {
            if (p == end+1) return;
            for (t=p; t<p+3; t++)
                if (num[t] != '0')  break;
       // if (j == end+1) return;
            if (t == p+3) {p += 3; bit1--;}
            else {
                if (p != tmpt) cout << a[(int)num[p]-48] << " ";
                if ((int)num[p] == 48) {
                    cout << " and ";
                } else {
                    if ((int)num[p+1] == 48 && (int)num[p+2] == 48) cout << "hundred ";
                    else cout << c[4] <<" and ";
                }
                head = (int)num[p+1]-48;
                break;
            }
		}
		//begin = p+1;
		begin = ++p;
		goto loop;
	}
}