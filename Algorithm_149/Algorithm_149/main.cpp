/*
题目描述
又到了丰收的季节，恰逢小易去牛牛的果园里游玩。
牛牛常说他对整个果园的每个地方都了如指掌，小易不太相信，所以他想考考牛牛。
在果园里有N堆苹果，每堆苹果的数量为ai，小易希望知道从左往右数第x个苹果是属于哪一堆的。
牛牛觉得这个问题太简单，所以希望你来替他回答。
输入描述:
第一行一个数n(1 <= n <= 105)。
第二行n个数ai(1 <= ai <= 1000)，表示从左往右数第i堆有多少苹果
第三行一个数m(1 <= m <= 105)，表示有m次询问。
第四行m个数qi，表示小易希望知道第qi个苹果属于哪一堆。
输出描述:
m行，第i行输出第qi个苹果属于哪一堆。

示例1
输入
5
2 7 3 4 9
3
1 25 11

输出
1
5
3
*/


//注意lower_bound用法，返回的是迭代器

#include <vector>
#include <iostream>
using namespace std;

class solution
{
public:
	vector<int> Get(vector<int>& apple, vector<int>& que)
	{
		vector<int> heap;
		if (apple.size() == 0 || que.size() == 0) {
			return heap;
		}
		vector<int> sum(apple.size());
		int count = 0;
		for (size_t i = 0; i < apple.size(); ++i) {
			count += apple[i];
			sum[i] = count;
		}
		int pos;
		int size = (int)sum.size() - 1;
		for (size_t i = 0; i < que.size(); ++i) {
			func(sum, que[i], 0, size, pos);
			//auto it = lower_bound(sum.begin(), sum.end(), que[i]);
			//heap.push_back(it - sum.begin() + 1);
			heap.push_back(pos + 1);
		}
		return heap;
	}

	void func(vector<int>& arr, int val, int begin, int end, int& pos)
	{
		int middle = (begin + end) >> 1;
		if (val == arr[middle]) {
			pos = middle;
			return;
		}
		if (end == begin + 1 && arr[begin] > val) {
			pos = begin;
			return;
		}
		if (end == begin + 1 && arr[begin] < val) {
			pos = end;
			return;
		}
		if (val < arr[middle]) {
			func(arr, val, begin, middle, pos);
		}
		if (val > arr[middle]) {
			func(arr, val, middle, end, pos);
		}
		return;
	}
};

int main()
{
	int n;
	solution s;
	while (cin >> n) {
		vector<int> apple(n);
		for (int i = 0; i < n; ++i) {
			cin >> apple[i];
		}
		int m;
		cin >> m;
		vector<int> que(m);
		for (int i = 0; i < m; ++i) {
			cin >> que[i];
		}
		vector<int> arr = s.Get(apple, que);
		for (size_t i = 0; i < arr.size(); ++i) {
			cout << arr[i] << endl;
		}
	}
	return 0;
}