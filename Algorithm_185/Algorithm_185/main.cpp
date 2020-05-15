/*
��Ŀ���ϳ���
��Ŀ����
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����
Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
��������:
ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)��
��ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50����
��������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��
�������:
���һ�б�ʾ���ĳ˻���
ʾ��1
����
����
3
7 4 7
2 50
���
����
49
*/


/*
dfs:ţ������ʱ

#include <iostream>
#include <vector>
using namespace std;

vector<int> re;

void func(vector<int>& arr, long& max, long& pro, int& k, int count, int& d, int start, int& n)
{
	if (count == k) {
		if (pro > max) {
			max = pro;
		}
		return;
	}
	for (int i = start; i < n; ++i) {
		if (start + d <= i) {
			break;
		}
		if (arr[i] != 0) {
			pro *= arr[i];
			count += 1;
			func(arr, max, pro, k, count, d, i + 1, n);
			count -= 1;
			pro /= arr[i];
		}
	}
	return;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		vector<int> a;

		int k;
		int d;
		cin >> k >> d;
		long max = -50;
		long pro = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] != 0) {
				pro *= arr[i];
				func(arr, max, pro, k, 1, d, i + 1, n);
				pro /= arr[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}
*/


#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	while (cin >> n) {
		vector<int> arr(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		int k;
		int d;
		cin >> k >> d;
		vector<vector<long> > positive(k + 1, vector<long>(n + 1, 0));
		vector<vector<long> > negative(k + 1, vector<long>(n + 1, 0));
		long re = LONG_MIN;
		for (int i = 1; i <= n; ++i) {
			positive[1][i] = arr[i];
			negative[1][i] = arr[i];
			for (int j = 2; j <= k; ++j) {
				for (int k = i - 1; k >= 1 && i - k <= d; --k) {
					positive[j][i] = max(positive[j][i], max(positive[j - 1][k] * arr[i], negative[j - 1][k] * arr[i]));
					negative[j][i] = min(negative[j][i], min(positive[j - 1][k] * arr[i], negative[j - 1][k] * arr[i]));
				}
			}
			re = max(re, positive[k][i]);
		}
		cout << re << endl;
	}
	return 0;
}