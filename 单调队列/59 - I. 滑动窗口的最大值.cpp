class Solution {
public:
    //1. 优先队列
    //思路: 优先队列存放pair类型, first表示元素的值(因为默认按照第一个位置进行排序); second存放该元素的下标
    //后续遍历nums数组时, 
    //先让滑动窗口的右边界移动一格(放入一个元素到优先队列当中); 
    //收缩左边界: 这个收缩很有讲究, 因为我们最终要放入res中的是滑动窗口的最大值, 因此, 我们要判断当前优先队列的最大值是否移出了滑动窗口的左边界, ①没移出的话就不用pop优先队列了; ②移出了的话, 就需要while(不断的判断)当前的优先队列的top元素是否曾经被移出过滑动窗口(因为我们这个优先队列的大小此时一定是比k要大的, 因为我们在第一种情况下是不pop任何元素的, 所以可能存在优先队列当中存的一些元素已经移出了滑动窗口的左边界)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;   //存放 (元素的值,下标)
        for(int i = 0; i < k; ++i)
        {
            pq.emplace(nums[i], i);
        }

        vector<int> res = { pq.top().first };
        for(int i = k; i < nums.size(); ++i)
        {
            pq.emplace(nums[i], i);
            while(pq.top().second <= i - k)  //当q.top()元素的下标, 不在[]滑动窗口的范围内(与左区间端点判断)
            {
                pq.pop();
            }
            res.emplace_back(pq.top().first);
        }
        return res;
    }
};


//2. 单调队列 (感觉思想类似于单调栈, 保持队列是单调的)
class Solution {
public:
    //单调队列的长度不一定是k(往往比k小), 它里面维护的是当前滑动窗口范围内的 由最大-->最小的 一串值(按照原数组顺序维护的, [1,3,2,4,5], 滑动窗口的大小为3, 初始情况的单调队列内部为[3,2])
    struct MonoQueue{
        void _push(int val){
            //1. 如果 val > 队尾元素, while循环pop队尾元素,直到队列为empty或队尾元素>=val (维持单调性)
            //2. 如果 val <= 队尾元素, 直接push_back到队尾即可
            while(!dq.empty() && dq.back() < val)
            {
                dq.pop_back();
            }
            dq.push_back(val);
        }

        void _pop(int val){  //pop也要告知我你pop的元素, 我要进行判断"是否应该将当前队列的队首元素pop掉"
            if(dq.front() == val){
                dq.pop_front();
            }
        }

        int _front(){
            return dq.front();
        }

        deque<int> dq;
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonoQueue mq;
        for(int i = 0; i < k; ++i)
        {
            mq._push(nums[i]);
        }
        
        vector<int> res = { mq._front() };
        for(int i = k; i < nums.size(); ++i)
        {
            mq._pop(nums[i - k]);
            mq._push(nums[i]);
            res.push_back(mq._front());
        }
        return res;
    }
};