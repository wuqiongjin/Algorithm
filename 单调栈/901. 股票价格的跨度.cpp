// class StockSpanner {
// public:
//     StockSpanner() {
//     }
    
//     int next(int price) 
//     {
//         if(priceStack.empty() || priceStack.top() > price)
//         {
//             priceStack.push(price);
//             widthStack.push(1);
//         }
//         else
//         {
//             int width = 0;
//             while(!priceStack.empty() && priceStack.top() <= price)
//             {
//                 width += widthStack.top();
//                 widthStack.pop();
//                 priceStack.pop();
//             }
//             priceStack.push(price);
//             widthStack.push(width + 1);
//         }
//         return widthStack.top();
//     }
// private:
//     stack<int> priceStack;  //价格
//     stack<int> widthStack;  //跨度
    
//     // stack<pair<int, int>> st;
// };



//简洁版
class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) 
    {
        //起始宽度为1
        int width = 1;
        while(!priceStack.empty() && priceStack.top() <= price)
        {
            width += widthStack.top();
            widthStack.pop();
            priceStack.pop();
        }

        priceStack.push(price);
        widthStack.push(width);

        return widthStack.top();
    }

private:
    stack<int> priceStack;  //价格
    stack<int> widthStack;  //跨度
    
    // stack<pair<int, int>> st;
};


//pari版本
class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) 
    {
        //起始宽度为1
        // int width = 1;
        pair<int, int> next(price, 1);

        while(!st.empty() && st.top().first <= price)
        {
            next.second += st.top().second;
            st.pop();
        }

        st.push(next);
        return st.top().second;
    }

private:
    // stack<int> priceStack;  //价格
    // stack<int> widthStack;  //跨度
    
    stack<pair<int, int>> st;   //first是价格，second是跨度
};



/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */