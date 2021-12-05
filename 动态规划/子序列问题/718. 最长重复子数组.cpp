//思路：画图呀呀呀！
//二维dp
//dp[i][j]: 以下标i - 1为结尾的A串，与以下标j - 1为结尾的B串的最长重复子数组的长度为dp[i][j]
//这里将i - 1而不是i作为下标的原因在于方便计算!
//
//状态转移方程: 当nums1[i - 1] == nums2[j - 1]时, dp[i][j] = dp[i - 1][j - 1] + 1;
//**********************************************************************************
//画一下图，"当前位置的值如果相同的，那么当前问题的解就等于 dp[i - 1][j - 1]的值 + 1"
//**********************************************************************************
//本题肯定是要2层for循环的，先遍历nums1串再遍历nums2串

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ans = 0;

        for(int i = 1; i <= nums1.size(); ++i)
        {
            for(int j = 1; j <= nums2.size(); ++j)
            {
                if(nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                if(ans < dp[i][j])  ans = dp[i][j];            
            }
        }
        return ans;
    }
};


//一维滚动数组dp
//将二维dp压成了一行
//防止值的覆盖，我们在遍历nums2串的时候要逆序遍历
//当前位置的值不相同的时候，我们要将当前位置的值进行清零0操作!!!
//所以还是需要ans保留最优解
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> dp(nums2.size() + 1, 0);
        int ans = 0;

        for(int i = 1; i <= nums1.size(); ++i)
        {
            for(int j = nums2.size(); j >= 1; --j)
            {
                if(nums1[i - 1] == nums2[j - 1])
                    dp[j] = dp[j - 1] + 1;
                else
                    dp[j] = 0;
                if(ans < dp[j]) ans = dp[j];
            }
        }
        return ans;
    }
};