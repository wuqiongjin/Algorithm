#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;

//dp[i]表示到达第i个台阶的最少步数为dp[i]步
//状态转移方程：dp[i + j] = min(dp[i + j], dp[i] + 1);
//遍历顺序：先遍历台阶值，再遍历约数（不先遍历台阶的值，没法求约数的）
//约数的遍历从2开始，到sqrt(i)。每次找到1个约数，实际上是找到了2个，因为 j * (i / j) = i

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> dp(M + 1, INT_MAX);
    dp[N] = 0;
    for(int i = N; i < M; ++i)
    {
        for(int j = 2; j <= sqrt(i); ++j)
        {
            if(i + j > M)
                continue;
            
            if(i % j == 0)
            {
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
                //在找到第一个约数的时候，实际上就已经找到了另一个约数了！
                //比如找8的约数，找到了2的时候，就相当于找到了4.这样效率高很多
                //所以在前面只需要让 j <= sqrt(i)就可以了。因为 满足 j * j <= i就能找完所有约数
                if(i + i / j <= M)
                    dp[i + i / j] = min(dp[i] + 1, dp[i + i / j]);
            }
            
        }
    }
    
    /*for(int i = N; i <= M; ++i)
    {
        printf("dp[%d]:%d\n",i,dp[i]);
    }*/
    
    if(dp[M] == INT_MAX)
        cout << -1;
    else
        cout << dp[M];
    return 0;
}