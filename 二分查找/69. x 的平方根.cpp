class Solution {
public:
    int mySqrt(int x) 
    {
        int left = 0, right = x;
        while(left < right)
        {
            long mid = ((right - left) >> 1) + left;

            if(mid * mid > x)   //可以使用 mid > x / mid来做判断条件，这样更有效防止溢出
            {
                right = mid;
            }
            else if(mid * mid == x)
            {
                return mid;
            }
            else// mid * mid < x
            {
                if((mid + 1) * (mid + 1) > x)
                    return mid;
                left = mid + 1;
            }
        }
        return left;
    }
};