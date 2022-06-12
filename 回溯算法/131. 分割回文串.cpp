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


//N-2
class Solution {
public:
    //1. 切割问题是如何转化为组合问题的 (每次切割完一部分后, 下一次就是从剩余的部分进行再切割, 组合也是)
    //2. 如何进行切割? (使用下标startIndex控制切割的起始位置, i控制控制位置)
    //3. 如何判断切割完成了? (startIndex到达了字符串的结尾)
    //4. 如何截取切割的字符串 (在进行递归的时候使用[startIndex, i]进行切割)
    //5. 如何判断回文字符串
    bool isPalindrome(const string& s, int start, int end){
        while(start < end)
        {
            if(s[start] != s[end]){
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
    
    void backtracking(int startIndex, const string& s){
        if(startIndex >= s.size()){
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); ++i)
        {
            if(isPalindrome(s, startIndex, i)){
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            }
            else{
                continue;
            }
            backtracking(i + 1, s);
            path.pop_back();	//回溯, 继续找下一个切割点
        }
    }
    
    vector<vector<string>> partition(string s) {
        path.clear();
        res.clear();
        backtracking(0, s);
        return res;
    }
    
    vector<string> path;
    vector<vector<string>> res;
};