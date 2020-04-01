/*
��Ŀ����
ţţ����˯��ͷ�����������˺ܶ����ӣ�ֻ�����������ʱ�����Ż��ѹ������Ҿ������𴲡�
��������������ҪX���ӵ�����ң��Ͽ�ʱ��Ϊ�����AʱB�֣��������������ʲôʱ����
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а���һ������������ʾ���ӵ�����N(N<=100)��
��������N��ÿ�а���������������ʾ������������ʱ��ΪHi(0<=A<24)ʱMi(0<=B<60)�֡�
��������һ�а���һ����������ʾ������������ҪX(0<=X<=100)���ӵ�����ҡ�
��������һ�а���������������ʾ�Ͽ�ʱ��ΪA(0<=A<24)ʱB(0<=B<60)�֡�
���ݱ�֤������һ�����ӿ�����ţţ��ʱ������ҡ�
�������:
�������������ʾţţ������ʱ�䡣

ʾ��1
����
3
5 0
6 0
7 0
59
6 59

���
6 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class times
{
public:
	bool operator< (const times& t) {
		if (_hour < t._hour) {
			return true;
		}
		else if (_hour > t._hour) {
			return false;
		}
		else {
			if (_minute <= t._minute) {
				return true;
			}
			else {
				return false;
			}
		}
	}
public:
	int _hour;
	int _minute;
};

class solution
{
public:
	times latest(vector<times>& arr, int cost, int hour, int minute)
	{
		sort(arr.begin(), arr.end());
		vector<int> minu;
		for (size_t i = 0; i < arr.size(); ++i) {
			int k = minutes(arr[i], hour, minute);
			minu.push_back(k);
		}
		times t = arr[0];
		for (size_t i = 0; i < minu.size(); ++i) {
			if (cost + minu[i] > 0) {
				break;
			}
			t = arr[i];
		}
		return t;
	}

	int minutes(times& t, int hour, int minute)
	{
		int mi = 0;
		int ho = 0;
		mi += t._minute - minute;
		ho = t._hour - hour;
		mi += ho * 60;
		return mi;
	}
};




int main()
{
	solution s;
	int n;
	while (cin >> n) {
		vector<times> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i]._hour >> arr[i]._minute;
		}
		int cost;
		cin >> cost;
		int hour, minute;
		cin >> hour >> minute;
		times tmp = s.latest(arr, cost, hour, minute);
		cout << tmp._hour << " " << tmp._minute << endl;
	}
	return 0;
}