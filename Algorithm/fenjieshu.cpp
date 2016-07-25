
#include<iostream>

using namespace std;

int num = 0;
#define Max 10

void f(int m, int n) {
	if (m>n)
		return;
	num++;
	if ((n-m) > 0) {
		int i;
		for(i=m; i<=n/2; i++) 
			f(i, n-i);
	}
	if (m+n == Max)
		f(m+1, n-1);
}

int main() {
	f(1, Max-1);
	cout << "NUM = " << num+1 << endl;
	return 0;
}


int q(int n, int m) {
	if (n<1 || m<1)	
		return 0;
	if (n==1 || m==1)
		return 1;
	if (n<m)
		return q(n, n);
	if (n==m)
		return q(n, m-1)+1;
	return q(n, m-1)+q(n-m, m);
}



/*
#include <iostream>  
using namespace std;  
  
#define MAX 20  
  
int res_num;  
// �����ݴ���res������  
int res[MAX];  
int p_res = 0;  
  
// ��n���зֽ�  
void resolve(int n);  
  
int main() {  
    while (1) {  
        int n;  
        cin >> n;  
        resolve(n);  
        cout << "total num of res:\t" << res_num << endl;  
        res_num = 0;  
    }  
    return 0;  
}  
  
void resolve(int n) {  
    if (n<=0) { // ����  
        for (int i=0; i<p_res; i++)  
            cout << res[i] << " ";  
        cout << endl;  
        res_num++;  
    }  
  
    for (int i=1; i<=n; i++) {  
        res[p_res] = i;  
        p_res++;        // p_res++��˳�δ洢��������  
        resolve(n-i);  
        p_res--;        // ���б����У�ִ������һ�У���һ��forѭ����ʹ��һ������  
    }  
}  

*/
