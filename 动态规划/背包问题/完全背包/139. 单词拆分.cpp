class Solution {
public:
    //说实话，本题比较抽象
    //将字符串s看做背包；将字典看做物品。
    //由于物品可以重复取用，所以此题是完全背包
    //dp[j]: 字符串长度为j, dp[j]为true时，表示该字符串可以被字典拆分成为1个或多个单词
    //状态转移方程: dp[j]的状态(true/false)只与它前一个曾在字典中出现的单词的dp[i]的值有关
    //说复杂了。举个例子: leetcode 单词 [字典为"leet","code"]。
    //假设leet已经被字典搜索到了，code该怎么推到出来呢？
    //'c'、'o'、'd' 这三个单词在遍历时一定找不到对应的字典中的单词。所以直接看'e'。
    //到了'e'位置时，字符串长度为9,即背包大小为9。我们去遍历物品，从[0, j)中找物品，
    //我们要找"code"这个单词，i从0不断的++，它曾经找到过"leet"，所以在背包大小为4的位置,dp[4] = true。
    //此时，我们可以截取字符串，为什么要截取字符串？因为前半部分的leet正好符合字典。
    //我们再看除去leet后的单词是否能在字典中找到！
    //也就是截取字符串"code"了！
    //至于去字典中找单词，最简单的办法就是使用set容器！
    //本题的难点在于如何遍历？
    //本题最好先遍历背包，
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> mySet(wordDict.begin(), wordDict.end());
        
        for(int j = 0; j <= s.size(); ++j)  //先遍历背包
        {
            for(int i = 0; i < j; ++i)  //再遍历物品
            {
                //从下标为[i, j)之间截取字符串，与字典比较是否存在该单词！
                //前提条件为，dp[i]位置必须是true，只有前面截取的单词在字典中存在，才能保证最终的单词存在
                if(dp[i] && mySet.find(s.substr(i, j - i)) != mySet.end())
                    dp[j] = true;
            }
        }
        
        return dp[s.size()];
    }
};