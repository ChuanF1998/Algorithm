/*
��Ŀ����
��������������4��1-10�����֣�ͨ���Ӽ��˳����õ�����Ϊ24����ʤ��
���룺
4��1-10�����֡�[���������ظ�����ÿ�����ֽ�����ʹ��һ�Σ�����������֤���쳣����]
�����
true or false
��������:
����4��int����
�������:
�����ܷ�õ�24�㣬�����true���������false
ʾ��1
����
7 2 1 10
���
true
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool get24(vector<int>& arr, int standerd)
	{
		int sum = arr[0];
		return func(arr, 1, sum, standerd);
	}
	bool func(vector<int>& arr, int flag, int sum, int standerd)
	{
		if (flag == (int)arr.size()) {
			return standerd == sum;
		}
		bool k = false;
		for (int i = 0; i < (int)arr.size(); ++i) {
			if (i == 0) {
				k = func(arr, i + 1, sum + arr[i], standerd);
			}
			if (i == 1) {
				k = func(arr, i + 1, sum - arr[i], standerd);
			}
			if (i == 2) {
				k = func(arr, i + 1, sum * arr[i], standerd);
			}
			if (i == 3) {
				k = func(arr, i + 1, sum / arr[i], standerd);
			}
		}
		return k;
	}
};


int main()
{
	Solution s;
	int a, b, c, d;
	vector<int> arr(4, 0);
	while (cin >> a >> b >> c >> d) {
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
		sort(arr.begin(), arr.end());
		bool k = false;
		do {
			k = s.get24(arr, 24);
			if (k) {
				cout << "true" << endl;
				break;
			}
		} while (next_permutation(arr.begin(), arr.end()));
		if (!k) {
			cout << "false" << endl;
		}
	}
	return 0;
}