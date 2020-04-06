/*
题目描述
小易有一些立方体，每个立方体的边长为1，他用这些立方体搭了一些塔。
现在小易定义：这些塔的不稳定值为它们之中最高的塔与最低的塔的高度差。
小易想让这些塔尽量稳定，所以他进行了如下操作：每次从某座塔上取下一块立方体，并把它放到另一座塔上。
注意，小易不会把立方体放到它原本的那座塔上，因为他认为这样毫无意义。
现在小易想要知道，他进行了不超过k次操作之后，不稳定值最小是多少。
输入描述:
第一行两个数n,k (1 <= n <= 100, 0 <= k <= 1000)表示塔的数量以及最多操作的次数。
第二行n个数，ai(1 <= ai <= 104)表示第i座塔的初始高度。
输出描述:
第一行两个数s, m，表示最小的不稳定值和操作次数(m <= k)
接下来m行，每行两个数x,y表示从第x座塔上取下一块立方体放到第y座塔上。
示例1
输入
3 2
5 8 5

输出
0 2
2 1
2 3
*/

//只排一次序，然后遍历k次。时间复杂度O(nlogn + k)
/*
模拟一下过程：假如塔高度分别是2， 9， 6， 3
排序：9 ， 6， 3， 2
第一步：9-->2;得 8， 6， 3， 3。 begin = 0. end = 3
第二步：8-->3.得 7， 6， 3， 4.  由于4比3大，那么前移一座塔，end = 2
第三步：7-->3.得 6， 6， 4， 4。 由于4小于6，那么4之前的塔都比它之后得塔高，end = 3
第四步：6-->4.得 5， 6， 4， 5. 由于5比6小，begin++。5比4大，end--。begin = 1， end = 2
第五步：6-->4.得 5， 5， 5， 5.退出
5次可完成，不过有可能没有5次，无论到第几次，高度差都是 begin塔高 - end塔高。
因为我们每次移动后都保证begin得塔最高，而end的塔最低
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
		//先插入一个pair对象保存s，m
		result.push_back(make_pair(0, k));
		//排序，lambda表达式，不会的也可以自己定义函数，排的是降序(升序也行，不过后面的逻辑得反过来)
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
			//如果前一座塔的高度已经小于它之后的那座塔的高度，那么begin++，下次就搬移++后的那座塔
			if (arr[begin].first < arr[begin + 1].first) {
				begin++;
			}
			//如果该座塔大于等于在它之后的塔，说明之前的塔都一样高，现在又从最开始那座塔搬移
			else {
				begin = 0;
			}
			//较低的塔跟较高的塔搬移规则是相反的，比前一座塔高则end--。否则，end = 末尾
			if (arr[end].first > arr[end - 1].first) {
				end--;
			}
			else {
				end = arr.size() - 1;
			}
			//他们的塔的高度一致就退出。因为我们的搬移的时候保证了begin前面的塔永远比end后面的塔高
			//所以begin和end两座塔高度相等，那么必然相邻或是同一座塔
			if (arr[begin].first == arr[end].first) {
				break;
			}
		}
		//最后begin位于end位塔高度差就是最小的不稳定值
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