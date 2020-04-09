/*
题目描述
小明有一袋子长方形的积木，如果一个积木A的长和宽都不大于另外一个积木B的长和宽，
则积木A可以搭在积木B的上面。好奇的小明特别想知道这一袋子积木最多可以搭多少层，你能帮他想想办法吗？
定义每一个长方形的长L和宽W都为正整数，并且1 <= W <= L <= INT_MAX, 
袋子里面长方形的个数为N, 并且 1 <= N <= 1000000.
假如袋子里共有5个积木分别为 (2, 2), (2, 4), (3, 3), (2, 5), (4, 5), 
则不难判断这些积木最多可以搭成4层, 因为(2, 2) < (2, 4) < (2, 5) < (4, 5)。
输入描述:
第一行为积木的总个数 N

之后一共有N行，分别对应于每一个积木的宽W和长L
输出描述:
输出总共可以搭的层数
示例1
输入
5
2 2
2 4
3 3
2 5
4 5

输出
4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tier[1000000];
pair<int, int> tower[1000000];

class solution
{
public:
	int Get(int n)
	{
		if (n == 0) {
			return 0;
		}
		sort(tower, tower + n);
		tier[0] = tower[0].second;
		int len = 1;
		for (int i = 1; i < n; ++i) {
			if (tower[i].second >= tier[len - 1]) {
				tier[len++] = tower[i].second;
			}
			else {
				auto it = upper_bound(tier, tier + len, tower[i].second);
				*it = tower[i].second;
			}
		}
		return len;
	}
};

int main()
{
	solution ss;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tower[i].first >> tower[i].second;
	}
	cout << ss.Get(n) << endl;
	return 0;
}



#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int tier[1000000];
//pair<int, int> tower[1000000];

vector<pair<int, int> > tower(1000000);
vector<int> tier(1000000);

class solution1
{
public:
	int Get(int n)
	{
		if (n == 0) {
			return 0;
		}
		sort(tower.begin(), tower.begin() + n);
		tier[0] = tower[0].second;
		int len = 1;
		for (int i = 1; i < n; ++i) {
			if (tower[i].second >= tier[len - 1]) {
				tier[len++] = tower[i].second;
			}
			else {
				auto it = upper_bound(tier.begin(), tier.begin() + len, tower[i].second);
				*it = tower[i].second;
			}
		}
		return len;
	}
};

#endif