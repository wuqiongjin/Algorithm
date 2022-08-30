class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(q.empty())   return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        q.push(value);

        //维护单调队列, 判断是否应该将value插入, 如果value比队尾元素小, 可以插入, 否则pop直到小于队尾元素为止或队列为空
        while(!dq.empty() && dq.back() < value)
        {
            dq.pop_back();
        }
        dq.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())  return -1;

        //判断是否也需要删除 单调队列 队首
        if(dq.front() == q.front()){
            dq.pop_front();
        }

        int tmp = q.front();
        q.pop();
        return tmp;
    }

    queue<int> q;
    deque<int> dq;  //单调队列(递减)
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */