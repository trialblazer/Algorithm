/*#include<stdio.h>

#define Max 5

int sum(int a[], int begin, int end);

int main()
{
	int a[Max], i, j, max, max1, max2, a1, b=0, c;
	for(i=0; i<Max; i++) {
		scanf("%d", &a[i]);
	}
	for(i=0; i<Max; i++) {
		j=i;
		while(j<Max) {
			max1=sum(a, i, j);
			if(j!=(Max-1)) 
				max2=sum(a, i, (++j));
			max=max1>max2? max1:max2;
			a1=max;
			j++;
			if(j==Max) break;
		}
		c=a1>b? a1: b;
		b=c;

	}
	printf("max=%d\n", c);
	return 0;
}

int sum(int a[], int begin, int end)
{
	int i, sum=0;
	for(i=begin; i<=end; i++) {
		sum=sum+a[i];
	}
	return sum;
}
*/
#include<stdio.h>

#define Max 5

int f(int a[], int n);

int main()
{
	int a[Max]={1, -2,-3,4,-2};
	printf("%d\n", f(a, Max-1));
	return 0;
}

int f(int a[], int n)
{
	int max, c;
	if(n==1)
		return a[1];
	else {
		int i, j, a1, sum=0, b=0;
		for(j=0; j<=n; j++) {
			for(i=n; i>=j; i--) {
				sum+=a[i];
				a1=sum;
			}
			c=a1>b? a1: b;
			b=c;
			sum=0;
		}
	}
	return f(a, (n-1))>c? f(a, (n-1)):c;
}


/*
#include <stdio.h>

int a[100], dp[100];

#define max(a, b) (((a)>(b)) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);

    // 求各个dp的值
    dp[0] = a[0];
    for (int i=1; i<n; i++)
        dp[i] = max(dp[i-1]+a[i], a[i]);

    //求最大值
    int max = dp[0];
    for (int i=1; i<n; i++)
        if (max < dp[i]) max = dp[i];

    printf("%d\n", max);
    return 0;
}

*/

/*
#include <stdio.h>
int main() {
    int t, n, max, sum, a;
    scanf("%d", &n);
    scanf("%d", &a);
    max = sum = a;
    while(--n) {
        scanf("%d", &a);
        sum += a;
        if (sum < a) sum = a;
        if (max < sum) max = sum;
    }
    printf("%d\n", max);
    return 0;
}

  #include <stdio.h>
int main() {
    // dp[i]表示数组中以a[i]为结尾的最大子序列和
    // 则有如下递推公式： dp[i]=max(dp[i-1]+a[i], a[i])
    // 由于dp[i]只依赖dp[i-1]，所以只保存dp[i]就行
    // sum代表即dp[i-1]，然后不断更新sum
    // 并保存最大的sum
    int t, n, max, sum, a;
    scanf("%d", &n);
    scanf("%d", &a);
    max = sum = a;
    while(--n) {
        scanf("%d", &a);
        sum += a;
        if (sum < a) sum = a;
        if (max < sum) max = sum;
    }
    printf("%d\n", max);
    return 0;
}
*/

/*
#include <stdio.h>

int sum[1000001];

int main() {
    int t, n, max, a;
    scanf("%d", &n);

    sum[0] = 0;
    for (int i=1; i<=n; ++i) {
        scanf("%d", &a);
        sum[i] = sum[i-1] + a;
    }

    int max = sum[1];
    for (int i=0; i<n; ++i) {
        for (int j=i; j<=n; ++j) {
            int tmp = sum[j] - sum[i];
            if (tmp > max)
                max = tmp;
        }
    }
    printf("%d\n", max);
    return 0;
}
*/

