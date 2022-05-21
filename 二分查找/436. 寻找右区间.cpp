class Solution {
public:
    //思路: 排序 +　二分查找
    //排序, 我们需要按照第一个元素进行排序, 最后查找 > 该元素end位置的 最小下标即可
    //在排序之前, 先使用vector<pair<int,int>> 存储每个元素的第一个值和它的下标 到pair中
    //随后按照第一个元素进行排序
    //遍历intervals, 对每个区间的end 进行二分查找(C++里面的lower_bound就是找到 最小的>val的位置的迭代器)
    //随后我们取出该迭代器所指向的second(下标)即可
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        vector<pair<int,int>> vp;
        for(int i = 0; i < intervals.size(); ++i)
        {
            vp.emplace_back(intervals[i][0], i);
        }
        sort(vp.begin(), vp.end());
        
        vector<int> res;
        for(int i = 0; i < intervals.size(); ++i)
        {
            int target = intervals[i][1];
            auto it = lower_bound(vp.begin(), vp.end(), make_pair(target, 0));//默认按照第一个元素查找
            if(it == vp.end()){
                res.emplace_back(-1);
            }
            else{
                res.emplace_back(it->second);
            }
        }
        return res;
    }
};