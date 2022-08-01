// //暴力解法 O(n ^ 3)
// class Solution {
// public:
//     bool isPalindromic(string&& s)
//     {
//         int start = 0, end = s.size() - 1;
//         while(start < end)
//         {
//             if(s[start] != s[end])
//                 return false;
//             ++start;
//             --end;
//         }
//         return true;
//     }

//     int countSubstrings(string s)
//     {
//         vector<int> dp(s.size() + 1, 0);

//         for(int i = 1; i <= s.size(); ++i)
//         {
//             for(int j = 0; j < i - 1; ++j)
//             {
//                 if(isPalindromic(s.substr(j, i - j)))
//                     dp[i]++;
//             }
//             dp[i] += dp[i - 1] + 1;
//         }
//         return dp[s.size()];
//     }
// };

//动态规划
class Solution {
public:
    int countSubstrings(string s) 
    {
        //1. dp[i][j]: 表示[i, j]区间的字符串是否是回文串 //bool类型的数组
        //结果要用ans变量去记录
        //2. 递推公式: 
        //当s[i] == s[j]时, 有3种情况的位置:
        //      1. i == j
        //      2. i + 1 == j   
        //----> 1和2都可以确定[i, j]区间的字符串为回文串!!!
        //      3. i + n == j   (n > 1)
        //----> 要判断3是否是回文串，还取决于[i+1, j-1]这个区间的字符串是否回文
        //----> 也就是去除了区间的断点后，看里层区间 (这个过程就是借助了子问题的解)
        //当s[i] != s[j]时
        //dp[i][j]肯定是false了，我们在初始化时全给false了，这里就不用管了
        //3. 初始化: 全部初始化为false，在判断是回文串的位置再设置为true
        //4. 遍历顺序
        //根据递推公式: 递推公式涉及了dp[i + 1][j - 1], 这个位置是"在dp[i][j]的左下方",
        //这限制了我们在遍历的时候必须要"从下到上，从左到右去遍历"!
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int ans = 0;

        for(int i = s.size() - 1; i >= 0; --i)
        {
            for(int j = i; j < s.size(); ++j)
            {
                if(s[i] == s[j])
                {
                    //情况1和情况2
                    if(j == i || j == i + 1)//j - i <= 1
                    {
                        ++ans;
                        dp[i][j] = true;    
                    }
                    else if(dp[i + 1][j - 1] == true)   //情况3
                    {
                        ++ans;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return ans;
    }
};



//N-2
class Solution {
public:
    int countSubstrings(string s) {
        //1. 确定dp数组
        //bool dp[i][j]: 区间[i, j]的子串是否为回文串 (我们通过res保存答案, dp数组判断是否是回文串)
        //2. 确定状态转移方程
        //当s[i] != s[j]:
        //dp[i][j] = false;
        //当s[i] == s[j]:
        //如果 i == j, 即[i,j]区间表示1个字符, 那么它一定是回文串, dp[i][j] = true      # a
        //如果 j - i == 1, 即[i, j]区间表示2个字符, 再加上这2个字符相等, 那么它也一定是回文串   # aa
        //如果 j - i == 2, 即[i, j]区间表示3个字符, 再加上这2个字符相等, 那么它也一定是回文串   # aba
        //如果 j - i > 2, 如( abda ), 此时i和j指向了字符a, 我们如果要判断这个子串是否是回文串的话, 还需要
        //判断 s[i + 1] 与 s[j - 1], 即 dp[i][j] = dp[i + 1][j - 1];
        //3. dp数组初始化 false
        //4. 确定遍历顺序
        //由于状态转移方程中涉及了 dp[i + 1][j - 1], 
        //因此, 为了确保能得到第 i 行, 我们需要先获取到 i + 1 行, 即, 从下到上遍历
        //因此, 为了确保能得到第 j 列, 我们需要先获取第 j - 1 列, 即 , 从左向右遍历

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;    //用变量res统计回文串数量
        for(int i = s.size() - 1; i >= 0; --i)
        {
            for(int j = i; j < s.size(); ++j)
            {
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }
                else{
                    if(j - i <= 2){	//实际上这里判断是 <= 1 还是 <= 2都可以
                        dp[i][j] = true;
                        ++res;
                    }
                    else{
                        dp[i][j] = dp[i + 1][j - 1];
                        if(dp[i][j] == true)    ++res;
                    }
                }
            }
        }
        return res;
    }
};