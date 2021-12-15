class Solution {
public:
    //和647题差不多
    string longestPalindrome(string s) 
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int left = 0, right = 0, maxlength = 0;

        for(int i = s.size() - 1; i >= 0; --i)
        {
            for(int j = i; j < s.size(); ++j)
            {
                if(s[i] == s[j])
                {
                    if(j - i <= 1)
                        dp[i][j] = true;
                    else if(dp[i + 1][j - 1] == true)
                        dp[i][j] = true;
                }

                if(dp[i][j] == true && j - i + 1 > maxlength)
                {
                    maxlength = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, maxlength);
    }
};