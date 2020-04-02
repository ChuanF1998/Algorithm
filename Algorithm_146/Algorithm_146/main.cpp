/*
��Ŀ����
ţţ׼���μ�ѧУ��֯�Ĵ���, ����ǰţţ׼����������װ��һЩ��ʳ, ţţ�ı�������Ϊw��
ţţ����һ����n����ʳ, ��i����ʳ���Ϊv[i]��
ţţ��֪������������������������������,��һ���ж�������ʳ�ŷ�(�����Ϊ0Ҳ��һ�ַŷ�)��
��������:
�����������
��һ��Ϊ����������n��w(1 <= n <= 30, 1 <= w <= 2 * 10^9),��ʾ��ʳ�������ͱ�����������
�ڶ���n��������v[i](0 <= v[i] <= 10^9),��ʾÿ����ʳ�������
�������:
���һ��������, ��ʾţţһ���ж�������ʳ�ŷ���
ʾ��1
����
3 10
1 2 4
���
8
˵��
������ʳ�����С��10,����ÿ����ʳ�з���Ͳ��������������һ����2*2*2 = 8�������
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution1
{
public:
	long long Getways(vector<long long>& arr, long long w)
	{
		sort(arr.begin(), arr.end());
		return func(arr, 0, w, 0) + 1;
	}
	long long func(const vector<long long>& arr, size_t pos, const long long& w, long long val)
	{
		long long push_ways = 0;
		for (size_t i = pos; i < arr.size(); ++i) {
			val += arr[i];
			if (val <= w) {
				push_ways += func(arr, i + 1, w, val) + 1;
			}
			else {
				break;
			}
			val -= arr[i];
		}
		return push_ways;
	}
};

int main()
{
	int n;
	long long w;
	long long sum = 0;
	solution1 s;
	while (cin >> n >> w) {
		vector<long long> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}
		if (sum <= w) {
			long long k = (long long)pow(2, n);
			cout << k << endl;
		}
		else {
			cout << s.Getways(arr, w) << endl;
		}
	}
	return 0;
}

