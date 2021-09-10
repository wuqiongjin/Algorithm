class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int gi = 0, si = 0, ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(gi < g.size() && si < s.size())
        {
            if(g[gi] <= s[si])
            {
                ++gi;
                ++si;
                ++ans;
            }
            else
            {
                ++si;
            }
        }
        return ans;
    }
};