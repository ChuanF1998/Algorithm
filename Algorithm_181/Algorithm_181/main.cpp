/*
��Ŀ�����
��Ŀ����
������������ n �� m��������1��2��3.......n ������ȡ������,ʹ��͵��� m ,Ҫ���������еĿ�������г���
��������:
ÿ�������������2������,n��m
�������:
��ÿ����ϵ��ֵ����������,ÿ�����һ�����
ʾ��1
����
����
5 5
���
����
1 4<br/>2 3<br/>5
*/

#include <iostream>
#include <vector>
using namespace std;

void func(int begin, int n, int m, int& sum, vector<int>& arr)
{
	if (sum == m) {
		for (int i = 0; i < arr.size(); ++i) {
			if (i == 0) {
				cout << arr[i];
			}
			else {
				cout << " " << arr[i];
			}

		}
		cout << endl;
		return;
	}
	for (int i = begin; i <= n; ++i) {
		sum += i;
		arr.push_back(i);
		func(i + 1, n, m, sum, arr);
		sum -= i;
		arr.pop_back();
	}
}

int main()
{
	int n;
	int m;
	while (cin >> n >> m) {
		vector<int> arr;
		int sum = 0;
		func(1, n, m, sum, arr);
	}
	return 0;
}