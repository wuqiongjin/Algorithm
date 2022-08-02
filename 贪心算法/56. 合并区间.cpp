class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y){
            return x[0] < y[0];
        });
        //什么时候进行合并?
        //当前一个区间的右边界 >= 左边界 进行合并
        //如果不满足, 则将前一个区间push_back到result中
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i)
        {
            //前一个右边界 >= 后一个左边界 (有重叠区间)
            if(right >= intervals[i][0]){
                right = max(right, intervals[i][1]); //别忘了 当前的right可能比后一个的右边界也大
            }
            else{
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};


//N-2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& x, const vector<int>& y)
        {
            return x[0] < y[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); ++i)
        {
            int left = intervals[i][0], right = intervals[i][1];
            int j = i + 1;
            while(j < intervals.size() && intervals[j][0] <= right)
            {
                left = min(left, intervals[j][0]);
                right = max(right, intervals[j][1]);
                i = j;
                ++j;
            }
            res.push_back({left, right});
        }
        return res;
    }
};