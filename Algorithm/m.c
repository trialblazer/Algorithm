#include <iostream>
#include <cstring>
using namespace std;

int pack1(int n, int c);
int pack2(int n, int c);
int pack3(int n, int c);
int pack4(int n, int c);

int w[100], v[100];
int dp[100][100];

int main()
{
    int n, c;
    cin>>n>>c;

    for(int i=1; i<=n; i++)
        cin>>w[i]>>v[i];

    cout<<pack1(n, c)<<endl;

    //初始化dp数组
    /*for(int i=0; i<=n; i++)
        for(int j=0; j<=c; j++)
            dp[i][j] = -1;
    cout<<pack2(n, c)<<endl;*/

    /*cout<<pack3(n, c)<<endl;*/

    cout<<pack4(n, c)<<endl;

    return 0;
}

int pack1(int n, int c)
{
    if(n==0)
        return 0;
    int tmp1, tmp2;
    tmp1 = tmp2 = 0 ;

    //不放
    tmp1 = pack1(n-1, c);

    if(w[n]<=c)
        tmp2 = pack1(n-1, c-w[n]) + v[n];
    if(tmp1>tmp2)
        return tmp1;
    return tmp2;
}

int pack2(int n, int c)
{
    if(dp[n][c]!=-1)
        return dp[n][c];

    if(n==0)
        return dp[n][c] = 0;

    int tmp1, tmp2;
    tmp1 = tmp2 = 0 ;

    //不放
    tmp1 = pack2(n-1, c);

    if(w[n]<=c)
        tmp2 = pack2(n-1, c-w[n]) + v[n];
    if(tmp1>tmp2)
        return dp[n][c] = tmp1;
    return dp[n][c] = tmp2;
}

int pack3(int n, int c)
{
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=c; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=w[i])
                if(dp[i-1][j-w[i]]+v[i] > dp[i][j])
                    dp[i][j] = dp[i-1][j-w[i]]+v[i];
        }
    }
    return dp[n][c];
}

int pack4(int n, int c)
{
    int * d = new int[c];
    memset(d, 0, sizeof(int)*c);
    for(int i=1; i<=n; i++)
        for(int j=c; j>=w[i]; j--)
            if(d[j-w[i]]+v[i]>d[j])
                d[j] = d[j-w[i]] + v[i];
    int tmp = d[c];
    delete []d;
    return tmp;
}
