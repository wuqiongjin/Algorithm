class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
		//本题思路：首先自己举一个常规的例子如：[5,3,2,4] [1,5,6,7]
		//我们如果正常的想，只要保证某一侧的所有手套都拿了，另一侧可能只要拿1个或者很少的几个就够了。
		//再进一步的想，某一侧实际上也不用全拿，我们只要拿这一侧的所有数量和 - 这一侧的最小值 + 1就够了。而另一侧只需要拿1个手套就行！
		//看例子中的左侧，5 + 3 + 2 + 4 = 14.按照我们刚才的理论，我们只需要拿14 - 2 + 1 = 13. 拿13个的话，最坏的情况也能保证所有颜色的手套都拿到！
		//我们的目的就是：保证这一侧的所有手套的种类都拿到！所以最坏的情况就是拿到了 5、3、1、4 这样的拿法。其他情况如：4、3、2、4.这样也能拿全所有种类的！
		
		//我们还需要考虑某一侧含0！
		//含0的话，就比较糟了。此时也要拿走对面那一侧0位置的所有手套，因为此时只保证一侧拿走全部的手套 - 这一侧的最小值 + 1 就不够了，对面只拿1只手套就不行了，所以要统计0位置的手套。
		
        int CountZero = 0;
        int left_sum = 0, right_sum = 0, left_min = INT_MAX, right_min = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            if(left[i] * right[i] == 0)
                CountZero += left[i] + right[i];
            else
            {
                left_sum += left[i];
                right_sum += right[i];
                if(left_min > left[i])
                    left_min = left[i];
                if(right_min > right[i])
                    right_min = right[i];
            }
        }
			  //countZero要保证所有0位置对应的另一侧的手套都被拿
        return CountZero + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;	//别忘了最后要加上 1.这个是另一侧要拿并且要进行匹配的手套
    }
};