/*
题目描述
牛牛总是睡过头，所以他定了很多闹钟，只有在闹钟响的时候他才会醒过来并且决定起不起床。
从他起床算起他需要X分钟到达教室，上课时间为当天的A时B分，请问他最晚可以什么时间起床
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示闹钟的数量N(N<=100)。
接下来的N行每行包含两个整数，表示这个闹钟响起的时间为Hi(0<=A<24)时Mi(0<=B<60)分。
接下来的一行包含一个整数，表示从起床算起他需要X(0<=X<=100)分钟到达教室。
接下来的一行包含两个整数，表示上课时间为A(0<=A<24)时B(0<=B<60)分。
数据保证至少有一个闹钟可以让牛牛及时到达教室。
输出描述:
输出两个整数表示牛牛最晚起床时间。

示例1
输入
3
5 0
6 0
7 0
59
6 59

输出
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