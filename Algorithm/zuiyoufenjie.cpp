/*
������������㷨֮ǰ����֤��������һ�����ʣ��� a + b = N������������ | a �C b | ԽС��a �� b Խ��
��֤����

�������ŷֽ�����Ķ��壬�� n < 4 ʱ�� n �ķֽ�ĳ˻���С�� n �ģ��� n ���ڻ���� 4 ʱ��n = 1 + ( n �C 1 ) ���ӵĳ˻�Ҳ��С�� n �ģ�
���� n = a + ( n �C a )��2 �� a �� n - 2�����Ա�֤�˻����� n����Խ�ֽ�˻�Խ��
����ǰ��֤�������ʣ����Բ�������̰�Ĳ��ԣ��� n �ֳɴ� 2 ��ʼ��������Ȼ���ĺ͡�������ʣ��һ�������������ں������ȵķ�ʽ�¾��ȵط�
��ǰ������̰�Ĳ������ȱ�֤�����������ֽ��������֮��ľ���ֵ��С���� | a �C b |��С��ͬʱ�ֿ��Խ���ֽ�ɾ����ܶ�����ӣ�������
��ֵ�ϴ�ȷ���������ֽ����Ȼ���ĳ˻�����ȡ�����ֵ��

*/

#include <iostream>

int bestDivide(int a) {
    if (a <= 4)
        return a;
    vector<int> divisor;
    int sum = 0;
    for (int i=2; sum<a; i++) {
        sum += i;
        if (sum > a) {
            sum -= i;
            break;
        }
        divisor.push_back(i);
    }
    int difference = a-sum, len = divisor.size();
    if (difference != 0) {
        while (difference != 0) {
            int j = len-1;
            for (int i=j; i>=0 && difference>0; i--) {
                divisor[i] += 1;
                difference--;
            }
        }
    }
    int product = 1;
    for (int i=0; i<len; i++)
        product *= divisor[i];
    return product;
}

int main() {
    int key;
    while (1) {
        cout << "������������" ;
        cin >> key;
        cout << "���˻�Ϊ��" ;
        cout << bestDivide(key) << endl;
    }
    return 0;
}
