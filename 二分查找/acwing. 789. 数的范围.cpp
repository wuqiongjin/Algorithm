#include <iostream>
using namespace std;

const int N = 100010;
int arr[N];


int main()
{
    int n, q, target;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) 
        cin >> arr[i];
    
    while(q--)
    {
        cin >> target;
        
        int left = 0, right = n - 1;
        while(left < right)
        {
            int mid = (right - left) / 2 + left;
            if(arr[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }

        if(arr[left] != target)
        {
            cout << "-1 -1" << endl;
            continue;
        }
        cout << left << ' ';
        
        left = 0, right = n - 1;
        while(left < right)
        {
            int mid = (right - left) / 2 + left + 1;
            if(arr[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        cout << right << endl;
    }
    
    return 0;
}