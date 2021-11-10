#include <iostream>
#include <vector>
using namespace std;

//���ر�����ʵ���Ϻ�01�������ƣ�ֻ����ÿ����Ʒ����������ֹһ�������Ը���һ��nums�����ʾ��Ӧ��Ʒ������
//˼·1�����ǿ��Խ����ر���ת��Ϊ01��������ÿ������>1����Ʒ����չ����
//˼·2������Ʒ�������ŵ�������������ʱ���ٽ���չ��

//˼·1
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
			weight.push_back(weight[i]);	//����Ʒiչ�����뱳���� ��ע�⣬�������ԭ������Ļ��������˳�򣬵���ûʲôӰ����ʵ��
			value.push_back(value[i]);
			nums[i]--;
		}
	}

	//һάdp���ű�������
	vector<int> dp(bagWeight + 1, 0);
	for (int i = 0; i < weight.size(); ++i)	//�ȱ�����Ʒ
	{
		for (int j = bagWeight; j >= weight[i]; --j)	//��������
		{
			dp[j] = fmax(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	cout << dp[bagWeight] << endl;
}

//����Ʒ�ĸ����ڱ�������ʱ����չ��
void test_multi_pack2()
{
	vector<int> weight = { 1, 3, 4 };
	vector<int> value = { 15, 20, 30 };
	vector<int> nums = { 2, 3, 2 };
	int bagWeight = 10;
	vector<int> dp(bagWeight + 1, 0);


	for (int i = 0; i < weight.size(); i++) 
	{ // ������Ʒ
		for (int j = bagWeight; j >= weight[i]; j--) 
		{ // ������������
			// ����Ϊ01������Ȼ���һ����������
			for (int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0; k++) 
			{ // ��������
				dp[j] = fmax(dp[j], dp[j - k * weight[i]] + k * value[i]);
			}
		}
		//// ��ӡһ��dp����
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