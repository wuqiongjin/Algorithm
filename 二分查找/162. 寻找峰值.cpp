class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (right - left) / 2 + left;
            //本题由于说了nums[-1]和nums[n] = 负无穷，所以不会出现无解的情况
            if(mid + 1 < nums.size() && nums[mid] >= nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};