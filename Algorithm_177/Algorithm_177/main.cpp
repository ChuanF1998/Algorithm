/*
题目：牛妹打怪兽
题目描述
众所周知，牛妹非常喜欢打游戏，在阳光明媚的一天，她在玩一个叫做打怪兽的游戏。
也许您已经知道游戏“打怪物”。如果您不知道，没关系，让我现在告诉您，
森林里有那么多怪物，您就是攻击怪物并保护村庄的英雄。
为了简化问题，我们把怪物排成一行，怪物身上有很多攻击点，你有一把剑，
只能切掉攻击点，当切掉一个攻击点时，怪物会分裂成两个在段中，您必须消耗与
怪物一样多的能量。您的任务是将怪物切割成不包含任何攻击点。例如，您面对一
个怪物，该怪物的长度为20，并且有四个攻击点在其主体上：2 5 10 18.您可以这样切割：
1.切开第一点，您使用的能量为2 + 18 = 20；
2.切第二点，您使用的能量为3 + 15 = 18；
3.切第三点，您使用的能量为5 + 10 = 15；
4.切第四点，您使用的能量是8 + 2 = 10；
您使用的总能量为：20 + 18 + 15 + 10 = 63;
但您可以采用另一种策略：
1.切第二点，您使用的能量是5 + 15 = 20；
2.切开第一点，您使用的能量为2 + 3 = 5；
3.切第三点，您使用的能量是5 + 10 = 15；
4.切第四个点，您使用的能量为8 + 2 = 10；
您使用的能量为：20 + 5 + 15 + 10 = 50;
因此您有最佳的策略来最小化需要消耗的能量。
那么问题来了，牛妹面对给定攻击点和长度的怪兽，到底最后可以用最少多少的能量打倒怪兽呢？

示例1
输入
复制
20,[2,5,10,18]
输出
复制
45
备注:
攻击点个数小于300
怪兽长度小于1000000
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param monsterLength int整型 怪兽长度
	* @param monsterPoint int整型vector 怪兽攻击点位置
	* @return int整型
	*/
	int attackMonster(int monsterLength, vector<int>& monsterPoint) {
		// write code here
		int n = monsterPoint.size();
		vector<vector<int> > arr(n + 2, vector<int>(n + 2, 0));
		monsterPoint.push_back(0);
		monsterPoint.push_back(monsterLength);
		sort(monsterPoint.begin(), monsterPoint.end());
		for (int len = 2; len <= n + 1; ++len) {
			for (int i = 1; i + len - 1 <= n + 1; ++i) {
				arr[i][i + len - 1] = 300000001;
				for (int j = i; j < i + len - 1; ++j) {
					arr[i][i + len - 1] = min(arr[i][i + len - 1], arr[i][j] + arr[j + 1][i + len - 1]
						+ monsterPoint[i + len - 1] - monsterPoint[i - 1]);
				}
			}
		}
		return arr[1][n + 1];
	}
};

int main()
{
	Solution ss;
	vector<int> arr{ 2, 5, 10, 18 };
	int k = ss.attackMonster(20, arr);
	return 0;
}