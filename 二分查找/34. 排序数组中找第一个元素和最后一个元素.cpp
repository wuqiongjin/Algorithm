//N - N刷了... (这个思路最清晰!)
class Solution {
public:
    int findLeft(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{   //nums[mid] == target
                if(mid > 0 && nums[mid - 1] == target){ //判断mid的前一个元素是否还是target
                    right = mid - 1;
                }
                else{
                    return mid;
                }
            }
        }
        return -1;  //走到这里说明没找到, 直接返回-1 (如果left返回-1, 那么right一定也会返回-1)
    }

    int findRight(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{	//nums[mid] == target
                if(mid + 1 < nums.size() && nums[mid + 1] == target){   //判断mid的后一个元素是否还是target
                    left = mid + 1;
                }
                else{
                    return mid;
                }
            }
        }
        return -1;  //走到这里说明没找到, 直接返回-1
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        int left = findLeft(nums, target);
        int right = findRight(nums, target);

        return {left, right};   //直接返回就行了, 这里的left和right包含了找不到的情况
    }
};












//N-1
//这里找的区间是[left, right]
class Solution {
public:
    //思路：分开寻找Left左边界和Right右边界
    int Left(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] >= target)    //左边界就是满足target的第一个元素
            {
                right = mid - 1;
            }
        }
        return left;
    }

    int Right(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] <= target)         //右边界就是满足target的最后一个元素
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = Left(nums, target);
        int right = Right(nums, target);
        //判断下表的有效性
        if(left > right)
            return vector<int>{-1, -1};
        return vector<int>{left, right};
    }
};