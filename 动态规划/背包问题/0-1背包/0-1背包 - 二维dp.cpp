//LintCode
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(m + 1, 0));
        //对第一行进行初始化, 第一行是物品0的存放，只要dp[0][i] >= 物品0的大小，其值就赋成物品0的价值
        //第一列直接初始化为0就行，因为背包大小为0，存不了东西
        // for(int i = 0; i <= m; ++i)
        // {
        //     if(i >= A[0])
        //         dp[0][i] = V[0];
        //     else
        //         dp[0][i] = 0;
        // }
        for(int i = A[0]; i <= m; ++i)  //直接从第一个能装物品0的下标处进行初始化
            dp[0][i] = V[0];


        // int max = 0;         //不用单独搞个max，因为dp数组的最大值在最右下角处
        for(int i = 1; i < n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                if(j >= A[i])
                    dp[i][j] = fmax(dp[i - 1][j], dp[i - 1][j - A[i]] + V[i]);
                else
                    dp[i][j] = dp[i - 1][j];
                // if(max <= dp[i][j])
                //     max = dp[i][j];
            }

        return dp[n - 1][m];		//返回最大值
    }
};

//Carl哥代码
void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= bagWeight; j++) {
        dp[0][j] = value[0];
    }

    // weight数组的大小 就是物品个数
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagWeight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size() - 1][bagWeight] << endl;
}

int main() {
    test_2_wei_bag_problem1();
}