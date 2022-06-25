class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> countMap; //统计words中每个单词出现的次数
        for(auto& e : words)
            countMap[e]++;

        vector<int> res;
        int w = words[0].size();    //每个单词的大小
        int len = words.size() * w; //滑动窗口大小
        unordered_map<string,int> tmp_count;    //用于保存每次检查窗口内的元素是否存在的哈希表(每轮for清空)
                        //注意,这里的i+len<=s.size()
        for(int i = 0; i + len <= s.size(); ++i) //i就是每个滑动窗口的起始位置
        {
            tmp_count.clear();
            int j = 0;
            for(; j < len; j += w)  //j确定滑动窗口内的每个单词的起始位置
            {
                string tmp = s.substr(i + j, w);
                if(countMap[tmp]){
                    tmp_count[tmp]++;
                    if(tmp_count[tmp] > countMap[tmp]){ //不满足
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(j == len){
                res.push_back(i);
            }
        }
        return res;
    }
};