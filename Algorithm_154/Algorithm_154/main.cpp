/*
题目描述
前几个月放映的头号玩家简直火得不能再火了，
作为一个探索终极AI的研究人员，月神自然去看了此神剧。
由于太过兴奋，晚上月神做了一个奇怪的梦，月神梦见自己
掉入了一个被施放了魔法的深渊，月神想要爬上此深渊。

已知深渊有N层台阶构成（1 <= N <= 1000)，并且每次月神仅可往
上爬2的整数次幂个台阶(1、2、4、....)，请你编程告诉月神，月神
有多少种方法爬出深渊
输入描述:
输入共有M行，(1<=M<=1000)

第一行输入一个数M表示有多少组测试数据，

接着有M行，每一行都输入一个N表示深渊的台阶数
输出描述:
输出可能的爬出深渊的方式
示例1
输入
复制
4
1
2
3
4
输出
复制
1
2
3
6
备注:
为了防止溢出，可将输出对10^9 + 3取模
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> result(1001);
vector<int> flag;

class solution
{
public:
	void func1()
	{
		int i = 1;
		while (i <= 1000) {
			flag.push_back(i);
			i <<= 1;
		}
	}

	void func2()
	{
		result[0] = 1;
		for (size_t i = 1; i < result.size(); ++i) {
			long long val = 0;
			for (size_t j = 0; j < flag.size(); ++j) {
				if (i >= flag[j]) {
					val += result[i - flag[j]];
				}
				else {
					break;
				}
			}
			result[i] = (int)(val % 1000000003);
		}
	}
};



int main()
{
	solution s;
	s.func1();
	s.func2();
	int m;
	while (cin >> m) {
		vector<int> arr(m);

		for (int i = 0; i < m; ++i) {
			cin >> arr[i];
		}
		for (int i = 0; i < m; ++i) {
			cout << result[arr[i]] << endl;
		}
	}
}