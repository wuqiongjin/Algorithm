class Solution {
public:
    //贪心算法
    //先确定第一个维度(保证比自己大的人都在自己的前面)
    //然后对第二个维度进行贪心(按照k值找到对应位置进行插入)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        //按第一个元素排降序、第二个元素排升序
        sort(people.begin(), people.end(), [](vector<int>& x, vector<int>& y){
            if(x[0] == y[0]) return x[1] < y[1];
            return x[0] > y[0];
        });

        //vector插入效率比较低
        // vector<vector<int>> res;
        // for(int i = 0; i < people.size(); ++i)
        // {
        //     res.insert(res.begin() + people[i][1], people[i]);
        // }
        // return res;

        list<vector<int>> res;
        for(int i = 0; i < people.size(); ++i)
        {
            int pos = people[i][1];
            auto it = res.begin();
            while(pos--)
            {
                ++it;
            }
            res.insert(it, people[i]);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};