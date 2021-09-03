class Solution {
public:
    //回文串的判断
    bool isPalindrome(const string& s)
    {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }

    void backtracking(string& s, int startIndex)
    {
        if(startIndex >= s.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); ++i)
        {
            //子串是[startIndex, i]这段。substr的第二个参数是长度
            string tmp = s.substr(startIndex, i - startIndex + 1);  
            if(isPalindrome(tmp))   //判断是否回文
                path.push_back(tmp);
            else                    //不是回文，直接跳过本轮循环
                continue;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) 
    {
        backtracking(s, 0);
        return ans;        
    }

    vector<string> path;
    vector<vector<string>> ans;
};