/*
��Ŀ����
С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
��������:
����Ϊһ�У�����������N��M���Կո������ (4 �� N �� 100000) (N �� M �� 100000)
�������:
���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1
ʾ��1
����
4 24

���
5
*/

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class jump_times
{
public:
	int Get_min(int n, int m)
	{
		vector<int> arr;
		if (n == 1) {
			return -1;
		}
		if (m == n){
			return 0;
		}
		if (is_prime(n)){
			return -1;
		}
		vector<int> step_num(m + 1, 0);
		step_num[n] = 1;
		for (int i = n; i<m; ++i) {
			if (step_num[i] == 0){
				continue;
			}
			vector<int> approximate;
			Get_approximate(i, approximate);
			for (int j = 0; j<approximate.size(); ++j) {
				if (approximate[j] + i <= m && step_num[approximate[j] + i] != 0) {
					if (step_num[i] + 1 < step_num[approximate[j] + i])
					{
						step_num[approximate[j] + i] = step_num[i] + 1;
					}
				}
				else {
					if (approximate[j] + i <= m){
						step_num[approximate[j] + i] = step_num[i] + 1;
					}
				}
			}
		}
		if (step_num[m] == 0){
			return -1;
		}
		else {
			return step_num[m] - 1;
		}
	}

	bool is_prime(int n)
	{
		if (n == 2 || n == 3) {
			return true;
		}
		double n_sqrt = sqrt(n*1.0);
		for (int i = 2; i <= n_sqrt; ++i) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}
	void Get_approximate(int n, vector<int>& arr) {
		double n_sqrt = sqrt(n*1.0);
		for (int i = 2; i <= n_sqrt; ++i) {
			if (n%i == 0) {
				arr.push_back(i);
				if ((n / i) != i) {
					arr.push_back(n / i);
				}
			}
		}
	}
};

int main()
{
	jump_times j;
	int n, m;
	while (cin >> n >> m) {
		cout << j.Get_min(n, m) << endl;
	}
	return 0;
}