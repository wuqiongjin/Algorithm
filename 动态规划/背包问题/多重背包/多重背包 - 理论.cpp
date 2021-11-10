#include <iostream>
#include <vector>
using namespace std;

//多重背包：实际上和01背包类似，只不过每种物品的数量都不止一件，所以给了一个nums数组表示相应物品的数量
//思路1：我们可以将多重背包转化为01背包，将每件数量>1的物品进行展开。
//思路2：将物品的数量放到遍历背包容量时，再进行展开

//思路1
void test_multi_pack1()
{
	vector<int> weight{ 1,3,4 };
	vector<int> value{ 15,20,30 };
	vector<int> nums{ 2,3,2 };
	int bagWeight = 10;

	for (int i = 0; i < nums.size(); ++i)
	{
		while (nums[i] > 1)
		{
			weight.push_back(weight[i]);	//将物品i展开放入背包中 （注意，如果数组原来有序的话，会打乱顺序，但是没什么影响其实）
			value.push_back(value[i]);
			nums[i]--;
		}
	}

	//一维dp逆着遍历背包
	vector<int> dp(bagWeight + 1, 0);
	for (int i = 0; i < weight.size(); ++i)	//先遍历物品
	{
		for (int j = bagWeight; j >= weight[i]; --j)	//遍历背包
		{
			dp[j] = fmax(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	cout << dp[bagWeight] << endl;
}

//将物品的个数在遍历背包时进行展开
void test_multi_pack2()
{
	vector<int> weight = { 1, 3, 4 };
	vector<int> value = { 15, 20, 30 };
	vector<int> nums = { 2, 3, 2 };
	int bagWeight = 10;
	vector<int> dp(bagWeight + 1, 0);


	for (int i = 0; i < weight.size(); i++) 
	{ // 遍历物品
		for (int j = bagWeight; j >= weight[i]; j--) 
		{ // 遍历背包容量
			// 以上为01背包，然后加一个遍历个数
			for (int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0; k++) 
			{ // 遍历个数
				dp[j] = fmax(dp[j], dp[j - k * weight[i]] + k * value[i]);
			}
		}
		//// 打印一下dp数组
		//for (int j = 0; j <= bagWeight; j++) 
		//{
		//	cout << dp[j] << " ";
		//}
		//cout << endl;
	}
	cout << dp[bagWeight] << endl;
}

int main()
{
	test_multi_pack1();
	test_multi_pack2();
	return 0;
}