// class Solution {
// public:
//     //双指针 + 哈希表
//     int lengthOfLongestSubstring(string s) 
//     {
//         if(s.size() == 0)   return 0;
//         if(s.size() == 1)   return 1;

//         map<char, int> mymap;
//         int start = 0, end = 0, maxlength = 0;
        
//         for(; end < s.size(); ++end)
//         {
//             ++mymap[s[end]];
//             while(mymap[s[end]] > 1)
//             {
//                 --mymap[s[start]];
//                 ++start;
//             }
//             if(end - start + 1> maxlength)
//                 maxlength = end - start + 1;
//         }
//         return maxlength;
//     }
// };

//滑动窗口 + 哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> usc;
        int maxlength = 0;
        //借助set存储[start, end]之间的元素
        //正向遍历字符串，start为每一次寻找最长子串的起始位置, 每次start++后都要删除前一个元素于set中
        //end去寻找相应的结束为止，然后判断end - start的长度
        //end的结束条件: 1. >= s.size 2. 遇到在set中重复的元素时，结束寻找
        //这样能保证，求出所有以start开头的最长子串!!!
        for(int start = 0, end = 0; start < s.size(); ++start)
        {
            if(start >= 1)
                usc.erase(s[start - 1]);
            
            while(end < s.size() && usc.count(s[end]) != 1)
            {
                usc.insert(s[end]);
                ++end;
            }

            maxlength = max(maxlength, end - start);
        }
        return maxlength;
    }
};