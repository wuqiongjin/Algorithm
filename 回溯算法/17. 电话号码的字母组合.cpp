//这题就不用剪枝了，因为每个结果都是一种组合。
class Solution {
public:
    //构建数字和字符的映射（可以使用哈希表），这里就用二维数组了
    const string letterMap[10] = 
    {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz" // 9
    };

    void backtracking(string& digits, int digitIndex, int charIndex)
    {
        //纵向遍历的结束。
        if(path.size() == digits.size())
        {
            ans.push_back(path);    //将结果添加到ans中，返回上次调用的位置。
            return;
        }

        //for循环的条件是横向遍历，即： a b c 这样的遍历，所以需要用charIndex控制。
        for(; charIndex < letterMap[digits[digitIndex] - '0'].size(); ++charIndex)
        {
            path.push_back(letterMap[digits[digitIndex] - '0'][charIndex]);
            backtracking(digits, digitIndex + 1, 0);    //递归，是纵向遍历。需要调控digits数字的下标digitIndex
            path.pop_back();                            //回溯
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if(digits.size() == 0)
            return vector<string>();
        backtracking(digits, 0, 0);
        return ans;
    }
    
    string path;        //单次遍历结果
    vector<string> ans; //结果集合
};


//N-2
class Solution {
public:
    unordered_map<char,string> umcs = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtracking(int digitsIndex, const string& digits){
        if(digitsIndex == digits.size()){
            res.push_back(path);
            return;
        }

        string word = umcs[digits[digitsIndex]];//设每个数字字符对应一个word:"abc"、"def"、...
        //这里的i是每个word的下标
        for(int i = 0; i < word.size(); ++i)//我们需要横向遍历的是每个word, 纵向遍历的是digits
        {                                   //横向遍历是for循环处理,纵向遍历是递归处理
            path.push_back(word[i]);
            backtracking(digitsIndex + 1, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        res.clear();
        path = "";
        backtracking(0, digits);
        return res;
    }

    vector<string> res;
    string path;
};