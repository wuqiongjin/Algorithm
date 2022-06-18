//容器选择unordered_map<string,map<string,int>>
//map<string,int>作为第二个值, map里面会对string进行字典排序(这里的string保存的都是目的地)
//同时, int保存到达目的地的次数, 这个目的地需要去几次。(防止产生死循环)

//我们的目的是搜索到一条最小(字典序最小)的路径, 搜索一条路径的话, 我们就不需要遍历整棵树
//因此我们需要把backtracking()的返回值设为bool类型而不是void (找到true直接返回)
class Solution {
public:
    bool backtracking(vector<vector<string>>& tickets){
        if(res.size() == tickets.size() + 1){	//当res数组中的元素个数 == 机票数 + 1 时说明完成了旅途的安排
            return true;
        }
        //遍历目的地
        for(pair<const string,int>& dest : targets[res[res.size() - 1]])
        {
            if(dest.second){
                dest.second--;
                res.push_back(dest.first);
                if(backtracking(tickets) == true){
                    return true;    //找到一条true的直接返回, 我们的目的是找到一条路径而不是遍历整棵树
                }
                res.pop_back();
                dest.second++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& e : tickets)  //初始化, 保存目的地需要达到的次数
        {
            targets[e[0]][e[1]]++;
        }
        res.push_back("JFK");
        backtracking(tickets);
        return res;
    }
    unordered_map<string,map<string,int>> targets;
    vector<string> res; //这里的res就是path, 只需要找到一个结果
};