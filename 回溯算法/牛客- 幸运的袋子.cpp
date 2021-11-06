#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//回溯算法
//传参的时候把sum和multi传过去
//本题对于我而言的疑点在于：去重的部分
//为什么去重要这样去？
//因为最终的集合是1的子集，举个例子[1,1,3,5,7]
//以第一个1为开头的有(1,1,3)、(1,1,5)、(1,1,7)、(1,3)、(1,5)、(1,7)
//在结束完上面的组合后，我们判断v[i]和v[i + 1]是否相等，此时v[i+1]也是1.那么
//以v[i+1]为开头的组合势必和v[i]开头的组合相同！


int getLuckPacket(vector<int>& v, int startIndex, int n, int sum, int multi)
{
    int count = 0;
    
    for(int i = startIndex; i < n; ++i)
    {
        sum += v[i];
        multi *= v[i];
        
        if(sum > multi)
        {
            count +=  1 + getLuckPacket(v, i + 1, n, sum, multi);
        }
        else if(v[i] == 1)
        {
            count += getLuckPacket(v, i + 1, n, sum, multi);
        }
        else
        {
            break;
        }
        
        sum -= v[i];
        multi /= v[i];
        
		//去重
        while(i < n - 1 && v[i] == v[i + 1])
            ++i;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    cout << getLuckPacket(v, 0, n, 0, 1) << endl;
    return 0;
}