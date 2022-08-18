class Solution {
public:
    //单调栈    -   取模运算
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        stack<int> st;
        int len = nums.size();
        //将数组拉伸为2倍长，下标就从 2 * len - 1开始往前
        for(int i = len * 2 - 1; i >= 0; --i)
        {
            while(!st.empty() && nums[i % len] >= st.top())
            {
                st.pop();
            }
            
            if(st.empty())
                ans[i % len] = -1;
            else
                ans[i % len] = st.top();
            
            st.push(nums[i % len]);
        }
        return ans;
    }
};