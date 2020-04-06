/*
��Ŀ����
С����һЩ�����壬ÿ��������ı߳�Ϊ1��������Щ���������һЩ����
����С�׶��壺��Щ���Ĳ��ȶ�ֵΪ����֮����ߵ�������͵����ĸ߶Ȳ
С��������Щ�������ȶ������������������²�����ÿ�δ�ĳ������ȡ��һ�������壬�������ŵ���һ�����ϡ�
ע�⣬С�ײ����������ŵ���ԭ�����������ϣ���Ϊ����Ϊ�����������塣
����С����Ҫ֪�����������˲�����k�β���֮�󣬲��ȶ�ֵ��С�Ƕ��١�
��������:
��һ��������n,k (1 <= n <= 100, 0 <= k <= 1000)��ʾ���������Լ��������Ĵ�����
�ڶ���n������ai(1 <= ai <= 104)��ʾ��i�����ĳ�ʼ�߶ȡ�
�������:
��һ��������s, m����ʾ��С�Ĳ��ȶ�ֵ�Ͳ�������(m <= k)
������m�У�ÿ��������x,y��ʾ�ӵ�x������ȡ��һ��������ŵ���y�����ϡ�
ʾ��1
����
3 2
5 8 5

���
0 2
2 1
2 3
*/

//ֻ��һ����Ȼ�����k�Ρ�ʱ�临�Ӷ�O(nlogn + k)
/*
ģ��һ�¹��̣��������߶ȷֱ���2�� 9�� 6�� 3
����9 �� 6�� 3�� 2
��һ����9-->2;�� 8�� 6�� 3�� 3�� begin = 0. end = 3
�ڶ�����8-->3.�� 7�� 6�� 3�� 4.  ����4��3����ôǰ��һ������end = 2
��������7-->3.�� 6�� 6�� 4�� 4�� ����4С��6����ô4֮ǰ����������֮������ߣ�end = 3
���Ĳ���6-->4.�� 5�� 6�� 4�� 5. ����5��6С��begin++��5��4��end--��begin = 1�� end = 2
���岽��6-->4.�� 5�� 5�� 5�� 5.�˳�
5�ο���ɣ������п���û��5�Σ����۵��ڼ��Σ��߶Ȳ�� begin���� - end���ߡ�
��Ϊ����ÿ���ƶ��󶼱�֤begin������ߣ���end�������
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	void GetMin(vector<pair<int, int> >& arr, int k, vector<pair<int, int> >& result)
	{
		if (arr.size() == 0) {
			return;
		}
		//�Ȳ���һ��pair���󱣴�s��m
		result.push_back(make_pair(0, k));
		//����lambda���ʽ�������Ҳ�����Լ����庯�����ŵ��ǽ���(����Ҳ�У�����������߼��÷�����)
		sort(arr.begin(), arr.end(), [=](const pair<int, int> a, const pair<int, int> b)
		{
			return a.first > b.first;
		});
		int begin = 0;
		int end = arr.size() - 1;
		int times = k;
		while (begin < end && times > 0) {
			times--;
			result.push_back(make_pair(arr[begin].second + 1, arr[end].second + 1));
			arr[begin].first--;
			arr[end].first++;
			//���ǰһ�����ĸ߶��Ѿ�С����֮����������ĸ߶ȣ���ôbegin++���´ξͰ���++���������
			if (arr[begin].first < arr[begin + 1].first) {
				begin++;
			}
			//������������ڵ�������֮�������˵��֮ǰ������һ���ߣ������ִ��ʼ����������
			else {
				begin = 0;
			}
			//�ϵ͵������ϸߵ������ƹ������෴�ģ���ǰһ��������end--������end = ĩβ
			if (arr[end].first > arr[end - 1].first) {
				end--;
			}
			else {
				end = arr.size() - 1;
			}
			//���ǵ����ĸ߶�һ�¾��˳�����Ϊ���ǵİ��Ƶ�ʱ��֤��beginǰ�������Զ��end���������
			//����begin��end�������߶���ȣ���ô��Ȼ���ڻ���ͬһ����
			if (arr[begin].first == arr[end].first) {
				break;
			}
		}
		//���beginλ��endλ���߶Ȳ������С�Ĳ��ȶ�ֵ
		result[0].first = arr[begin].first - arr[end].first;
		result[0].second = k - times;
		return;
	}
};

int main()
{
	solution s;
	int n;
	int k;
	while (cin >> n >> k) {
		vector<pair<int, int> > arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].first;
			arr[i].second = i;
		}
		vector<pair<int, int> > result;
		s.GetMin(arr, k, result);
		for (size_t i = 0; i < result.size(); ++i) {
			cout << result[i].first << " " << result[i].second << endl;
		}
	}
	return 0;
}