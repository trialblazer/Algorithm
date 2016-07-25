/*
【分析】设计算法之前，先证明整数的一个性质：若 a + b = N（常数），则 | a – b | 越小，a × b 越大。
【证明】

根据最优分解问题的定义，当 n < 4 时对 n 的分解的乘积是小于 n 的；当 n 大于或等于 4 时，n = 1 + ( n – 1 ) 因子的乘积也是小于 n 的，
所以 n = a + ( n – a )，2 ≤ a ≤ n - 2，可以保证乘积大于 n，即越分解乘积越大。
根据前面证明的性质，可以采用如下贪心策略：将 n 分成从 2 开始的连续自然数的和。如果最后剩下一个数，将此数在后项优先的方式下均匀地分
给前面各项。该贪心策略首先保证了正整数所分解出的因子之差的绝对值最小，即 | a – b |最小；同时又可以将其分解成尽可能多的因子，且因子
的值较大，确保最终所分解的自然数的乘积可以取得最大值。

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
        cout << "请输入拆分数：" ;
        cin >> key;
        cout << "最大乘积为：" ;
        cout << bestDivide(key) << endl;
    }
    return 0;
}
