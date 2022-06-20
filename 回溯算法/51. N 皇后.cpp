class Solution {
public:
    // bool isValid(int row, int col, int n){
    //     //1. 检查同行是否有其它棋子(row不变, col变)
    //     for(int i = 0; i < n; ++i)
    //     {
    //         if(i == col){
    //             continue;
    //         }
    //         if(path[row][i] == 'Q'){
    //             return false;
    //         }
    //     }
    //     //2. 检查同列是否有其它棋子(col不变, row变)
    //     for(int i = 0; i < n; ++i)
    //     {
    //         if(i == row){
    //             continue;
    //         }
    //         if(path[i][col] == 'Q'){
    //             return false;
    //         }
    //     }
    //     //3. 检查同一对角线是否有其它棋子
    //     int i = row - 1, j = col - 1;
    //     while(i >= 0 && j >= 0)
    //     {
    //         if(path[i][j] == 'Q'){
    //             return false;
    //         }
    //         --i;
    //         --j;
    //     }
    //     i = row + 1, j = col + 1;
    //     while(i < n && j < n)
    //     {
    //         if(path[i][j] == 'Q'){
    //             return false;
    //         }
    //         ++i;
    //         ++j;
    //     }

    //     i = row - 1, j = col + 1;
    //     while(i >= 0 && j < n)
    //     {
    //         if(path[i][j] == 'Q'){
    //             return false;
    //         }
    //         --i;
    //         ++j;
    //     }

    //     i = row + 1, j = col - 1;
    //     while(i < n && j >= 0)
    //     {
    //         if(path[i][j] == 'Q'){
    //             return false;
    //         }
    //         ++i;
    //         --j;
    //     }

    //     return true;
    // }

    //简化版 isVaild
    //不需要检查是否同行: 因为递归的性质, 每层(每行)必然只会标记一个'Q' 或者 不标记
    //不需要检查当前行以下的部分: 由于递归的性质, 我们是从上往下递归, 从上往下标记的, 因此下面的一定是还没标记的
    bool isValid(int row, int col, int n){
        //1. 检查是否同列
        for(int i = 0; i < row; ++i)
        {
            if(path[i][col] == 'Q'){
                return false;
            }
        }

        //2. 检查45°上半部分是否存在其它棋子
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        {
            if(path[i][j] == 'Q'){
                return false;
            }
        }

        //3. 检查135°上半部分是否存在其它棋子
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if(path[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void backtracking(int row, int n){
        if(row == n){
            res.push_back(path);
            return;
        }

        for(int col = 0; col < n; ++col)
        {
            if(isValid(row, col, n)){
                path[row][col] = 'Q';
                backtracking(row + 1, n);
                path[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        path.resize(n, string(n, '.'));
        backtracking(0, n);
        return res;
    }
    vector<string> path;
    vector<vector<string>> res;
};