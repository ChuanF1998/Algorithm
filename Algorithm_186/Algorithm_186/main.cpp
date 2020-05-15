/*
题目描述
搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，
精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到， 
马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，
要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。 团长
想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小
王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且
很快找到叠最高罗汉塔的人员序列。 现在你手上也拿到了这样一份身高体重表，请找出
可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
输入描述:
首先一个正整数N，表示人员个数。
之后N行，每行三个数，分别对应马戏团员编号，体重和身高。
输出描述:
正整数m，表示罗汉塔的高度。
示例1
输入
复制
6<br/>1 65 100<br/>2 75 80<br/>3 80 100<br/>4 60 95<br/>5 82 101<br/>6 81 70<br/>
输出
复制
4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct people
{
	int num;
	int wei;
	int hei;
};


int main()
{
	int n;
	while (cin >> n) {
		vector<people> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].num >> arr[i].wei >> arr[i].hei;
		}
		sort(arr.begin(), arr.end(), [](const people& a, const people& b){
			if (a.wei < b.wei) {
				return true;
			}
			else if (a.wei == b.wei) {
				return a.hei > b.hei;
			}
			else {
				return false;
			}
		});
		vector<int> re(n, 0);
		re[0] = 0;
		int result = -1;
		for (int i = 0; i < n; ++i) {
			//int count = 0;
			for (int j = i; j >= 0; --j) {
				if (arr[i].hei >= arr[j].hei) {
					re[i] = max(re[i], re[j] + 1);
				}
			}
			result = max(result, re[i]);
		}
		cout << result << endl;
	}
	return 0;
}