// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) 
//     {
//         int row = matrix.size(), col = matrix[0].size();//矩阵有几行，有几列
//         int top = 0, left = 0, bottom = row - 1, right = col - 1;
//         int ret = ((bottom - top) * col + (right - left)) / 2;
//         while(ret > 0 || (top <= bottom && left <= right))
//         {
//             ret = ((bottom - top) * col + (right - left)) / 2;
//             // cout << "ret=" << ret << endl;
//             int x = ret / col + top;
//             int y = ret % col + left;
//             if(y >= col)
//             {
//                 ++x;
//                 y-= col;
//             }
//             // cout << "x=" << x << " y=" << y << endl;
//             if(matrix[x][y] == target)
//                 return true;
//             else if(matrix[x][y] > target)
//             {
//                 right = y - 1;
//                 if(right < 0)
//                 {
//                     bottom = x - 1;
//                     right += col;
//                 }
//                 else
//                     bottom = x;
//             }
//             else//matrix[x][y] < target
//             {
//                 left = y + 1;
//                 if(left == col)
//                 {
//                     top = x + 1;
//                     left -= col;
//                 }
//                 else
//                     top = x;
//             }
//             // cout << "(top,left)"<<top<<","<<left<<"  (bottom,right)"<<bottom<<","<<right<<endl;
//         }
//         return false;
//     }
// };

//一次二分查找

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;

        while(left <= right)
        {
            //将坐标转化为二维坐标
            int mid = ((right - left) >> 1) + left;
            int x = mid / col;
            int y = mid % col;

            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};