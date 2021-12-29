#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double n;
    cin >> n;
    double left = -10000, right = 10000;
    while(right - left > 1e-8)
    {
        double mid = (left + right) / 2;
        if(mid * mid * mid >= n)
            right = mid;
        else
            left = mid;
    }
    cout << fixed << setprecision(6) << left << endl;
    //printf("%lf", left);  //printf默认打印6位小数
    
    return 0;
}