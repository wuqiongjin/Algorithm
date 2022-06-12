class Solution {
public:
    bool isValid(const string& s)
    {
        if(s.size() < 1 || s.size() > 3)    //检查位数(不然有可能超出int的范围)
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


//N-2
class Solution {
public:
    bool isValid(const string& s)
    {
        //0 ~ 255
        if(s.size() < 1 || s.size() > 3){   //这里必须要这样判断一下, 不然有可能超出int范围
            return false;
        }

        if(stoi(s) < 0 || stoi(s) > 255){
            return false;
        }

        //不能有前导0
        if(s == "0"){
            return true;
        }

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != '0'){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }

    void backtracking(int startIndex, string& s, int pointNum){
        if(pointNum == 3){
            string tmp = s.substr(startIndex);	//单独处理一下最后第四部分IP段
            if(isValid(tmp)){
                res.push_back(s);
            }
            return;
        }

        for(int i = startIndex; i < s.size(); ++i)
        {
            string ret = s.substr(startIndex, i - startIndex + 1);
            if(isValid(ret)){
                s.insert(s.begin() + i + 1, '.');   //在i位置的后面添加".", 所以是i+1
                ++pointNum;
                backtracking(i + 2, s, pointNum);
                s.erase(s.begin() + i + 1);
                --pointNum;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12){
            return {};
        }
        // path = "";
        res.clear();
        backtracking(0, s, 0);
        return res;
    }

    // string path; //还是直接在s上修改比较方便, 这样的做法麻烦, 在pop_back的时候还要把之前添加进去的字符串也pop, 也就是需要pop2次...
    vector<string> res;
};