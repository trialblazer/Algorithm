#include<iostream>
#include<string.h>

using namespace std;

#define Max 10

void translate(char a[], int begin, int end);
void translate1(char a[], int begin, int end);
void translate2();


int main() {
	translate2();
	return 0;
}


void translate2() {
	char a[Max];
	cout << "Please input the number you want to translate.\n" << "Num: ";
	cin >> a;
	int end = strlen(a);
	int i , begin = end;
	for (i=0; i<end; i++) {
		if (a[i] == '.')
			begin = i;
	}
	cout << "The translate number is: ";
	translate(a, 0, begin);
	if (begin != end) {
		cout << "point ";
		translate1(a, begin+1, end);
		cout << " ";
	}
	cout << endl;
}

void translate(char a[], int begin, int end) {
	int size = end-begin;
	if (size == 1) {
		switch(a[begin]) {
		case '0':	return;
		case '1':	cout << "one "; return;
		case '2':	cout << "two "; return;
		case '3':	cout << "three "; return;
		case '4':	cout << "four"; return;
		case '5':	cout << "five "; return;
		case '6':	cout << "six"; return;
		case '7':	cout << "seven"; return;
		case '8':	cout << "eight"; return;
		case '9':	cout << "nine"; return;
		default:	cout << "error"; return;
		}
	}
	if (size == 2) {
		int i = (int)a[begin]-48, j = (int)a[begin+1]-48;
		if (i == 0 && j == 0)	return;
		if (i == 1) {
			if (j == 1)	{cout << "eleven "; return;}
			if (j == 2) {cout << "twelve "; return;}
			if (j == 5) {cout << "fifteen "; return;}
			if (j == 8)	{cout << "eighteen "; return;}
			translate(a, begin+1, begin+2); cout << "teen "; return;
		} else {
			if (i == 2) { cout << "twenty "; translate(a, begin+1, begin+2); return;}
			if (i == 3) { cout << "thirty "; translate(a, begin+1, begin+2); return;}
			if (i == 5)	{ cout << "fifty "; translate(a, begin+1, begin+2); return;}
			if (i == 8)	{ cout << "eighty "; translate(a, begin+1, begin+2); return;}
			translate(a, begin, begin+1);
			cout << "ty ";
			translate(a, begin+1, begin+2);
		}
	}
	if (size == 3) {
		translate(a, begin, begin+1);
		if (a[begin] != '0')	cout << " hundred ";
		if (a[begin+1] == '0' && a[begin+2] == '0')
			return;
		else {
			cout << "and ";
			translate(a, begin+1, end);
		}
	}
	if (size == 4) {
		translate(a, begin, begin+1);
		if (a[begin] != '0') cout << " thousand ";
		translate(a, begin+1, end);
	}
	if (size == 5) {
		translate(a, begin, begin+2);
		if (a[begin] != '0') cout << " thousand ";
		translate(a, begin+2, end);
	}
	if (size == 6) {
		translate(a, begin, begin+3);
		if (a[begin] != '0') cout << " thousand ";
		translate(a, begin+3, end);
	}
	if (size == 7) {
		translate(a, begin, begin+1);
		if (a[begin] != '0') cout << " million ";
		translate(a, begin+1, end);
	}
	if (size == 8) {
		translate(a, begin, begin+2);
		if (a[begin] != '0') cout << " million ";
		translate(a, begin+2, end);
	}
	if (size == 9) {
		translate(a, begin, begin+3);
		if (a[begin] != '0') cout << " million ";
		translate(a, begin+3, end);
	}
	if (size == 10) {
		translate(a, begin, begin+1);
		if (a[begin] != '0') cout << " billion ";
		translate(a, begin+1, end);
	}
}


void translate1(char a[], int begin, int end) {
	int i;
	for (i=begin; i<end; i++) {
		translate(a, i, i+1);
	}
}