/*
��Ŀ�������������
��Ŀ����
�㳡��վ��һ֧���飬����������ȫ�����ص�Ť������ӣ����������ǵ�������ݣ�
�����æ�ҳ�������ε����������С� ����������������ǣ�1��7��3��5��9��4��8����
�������ε������������У�1��7������1��3��5��9������1��3��4��8���ȣ�������ĳ���Ϊ4��
��������:
��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000����

�����ŵڶ��а���n��������m��1��n��10000�������������ÿλ��Ա����ߡ�
�������:
��Ӧÿһ�����ݣ��������������еĳ��ȡ�
ʾ��1
����
����
7<br/>1 7 3 5 9 4 8<br/>6<br/>1 3 5 2 4 6
���
����
4<br/>4
*/
#if 0
// write your code here cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > arr(1001, { 0, 0});
vector<pair<int, int> > tmp(1001, { 0, 0});
vector<int> result(1001, 0);

int main()
{
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; ++i) {
			arr[i].first = i;
			tmp[i].first = i;
			cin >> arr[i].second;
			tmp[i].second = arr[i].second;
		}
		sort(tmp.begin() + 1, tmp.begin() + n + 1, [](const pair<int, int>& a, const pair<int, int>& b){
			return a.second < b.second;
		});
		for (int i = 1; i <= n; ++i) {
			arr[tmp[i].first].first = i;
		}
		for (int i = 1; i <= n; ++i) {
			if (arr[i].first < i && arr[i].second < arr[i - 1].second) {
				result[i] = arr[i].first;
				
			}
			else {
				result[i] = result[i - 1] + 1;
			}
		}
		int re = 0;
		for (int i = 1; i <= n; ++i) {
			re = max(re, result[i]);
		}
		cout << re << endl;
	}
	return 0;
}
#endif



// write your code here cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(1001, 0);
//vector<pair<int, int> > arr(1001, { 0, 0});
//vector<pair<int, int> > tmp(1001, { 0, 0});
vector<int> result(1001, 0);

int main()
{
	int n;
	while (cin >> n) {
		result.resize(1001, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		int re = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				if (arr[i] > arr[j])
					result[i] = max(result[i], result[j]);
			}
			result[i] += 1;
			re = max(re, result[i]);
		}
		cout << re << endl;
		result.clear();
	}
	return 0;
}