#include<iostream>

using namespace std;

#define LETTER 0

int main() {
	char str[20] = "C Language", c;
	int i = 0;
	while ((c = str[i]) != '\0') {
		i++;
#if LETTER
		if (c >= 'a' && c <= 'z')
			c -= 32;
#else
		if (c >= 'A' && c <= 'Z')
			c += 32;
#endif
		cout << c;
	}
	cout << endl;
	return 0;
}