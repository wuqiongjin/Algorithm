class Solution {
public:
    bool isValid(const string& s)
    {
        if(s.size() < 1 || s.size() > 3)    //检查位数
            return false;
        else
        {
            if(s[0] == '0' && s.size() > 1) //排除前导0
                return false;
            if(stoi(s) > 255)       //检查范围
                return false;
            else
                return true;
        }
    }
    
    void backtracking(string& s, int startIndex, int pointNum)
    {
        if(pointNum == 3)
        {
            //单独对第4段是否有效进行判断，它的判断方法和前3段不一样
            if(isValid(s.substr(startIndex, s.size() - startIndex)))
                ans.push_back(s);
            return;
        }

        for(int i = startIndex; i < s.size(); ++i)
        {
            string tmp = s.substr(startIndex, i - startIndex + 1);
            if(isValid(tmp))    //判断[startIndex, i]这个区间截取的数字是否有效
            {
                s.insert(s.begin() + i + 1, '.');   //有效的话，在区间的最后添加 '.'
                ++pointNum;
                backtracking(s, i + 2, pointNum);   //递归需要传 i + 2（因为多了个'.'）
                s.erase(s.begin() + i + 1);
                --pointNum;
            }
            else
                continue;
        }
    }

    vector<string> restoreIpAddresses(string s) 
    {
        if(s.size() < 4 || s.size() > 12)   //稍微剪枝一下
            return ans;
        backtracking(s, 0, 0);
        return ans;
    }

    vector<string> ans;
};