class Solution {
public:
    void backtracking(int left, int right, int n)
    {
        if(left == n && right == n){
            res.push_back(path);
            return;
        }

        if(left < n){
            path += "(";
            backtracking(left + 1, right, n);
            path.pop_back();
        }

        if(left > right){
            path += ")";
            backtracking(left, right + 1, n);
            path.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        res.clear();
        backtracking(0, 0, n);
        return res;
    }

    vector<string> res;
    string path;
};