class Solution {
public:
    //单调栈
    // vector<int> dailyTemperatures(vector<int>& temperatures) 
    // {
    //     vector<int> ans(temperatures.size());
    //     stack<int> st;
    //     for(int i = temperatures.size() - 1; i >= 0; --i)
    //     {
    //         if(st.empty())
    //         {
    //             st.push(i);
    //             ans[i] = 0;                
    //         }
    //         else
    //         {
    //             if(temperatures[i] >= temperatures[st.top()])
    //             {
    //                 while(!st.empty() && temperatures[i] >= temperatures[st.top()])
    //                 {
    //                     st.pop();
    //                 }
    //                 //如果栈为空，说明i位置后面没有比它更大的了
    //                 if(st.empty())
    //                     ans[i] = 0;
    //                 else
    //                     ans[i] = st.top() - i;

    //                 st.push(i);
    //             }
    //             else
    //             {
    //                 ans[i] = st.top() - i;
    //                 st.push(i);
    //             }
    //         }
    //     }
    //     return ans;

    // }


    //简化版本	-	单调栈 O(N)
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> ans(temperatures.size());
        stack<int> st;
        for(int i = temperatures.size() - 1; i >= 0; --i)
        {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            //栈为空，则当前位置后面没有比它更大的值了
            if(st.empty())
                ans[i] = 0;
            else    //栈不为空，栈顶元素的值 - 当前元素的下标
                ans[i] = st.top() - i;

            st.push(i);
        }
        return ans;
    }
};




//N-2
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>> st;//第一个存下标, 第二个存 temperatures 的值

        for(int i = 0; i < temperatures.size(); ++i)
        {
            if(st.empty()){
                st.emplace(i, temperatures[i]);
            }
            else{
                while(!st.empty() && st.top().second < temperatures[i])//temperatures[i]与栈顶元素相等的话, 直接push入栈即可, 所以这里不挂等号
                {
                    res[st.top().first] = i - st.top().first;
                    st.pop();
                }
                st.emplace(i, temperatures[i]);
            }
        }
        return res;
    }
};

//stack<int>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        // stack<pair<int,int>> st; //第一个存下标, 第二个存 temperatures 的值
        stack<int> st;  //只存下标, temperatures的值我们通过下标去访问

        for(int i = 0; i < temperatures.size(); ++i)
        {
            if(st.empty()){
                st.emplace(i);
            }
            else{
                while(!st.empty() && temperatures[st.top()] < temperatures[i])	//temperatures[i]与栈顶元素相等的话, 直接push入栈即可, 所以这里不挂等号
                {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.emplace(i);
            }
        }
        return res;
    }
};