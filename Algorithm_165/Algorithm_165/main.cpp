/*
题目：那些插队的人
题目描述
题目背景：

简明题意：

你有一个长度为 n 的队伍，从左到右依次为 1~n，有 m 次插队行为，用数组 cutIn 进行表示，
cutIn 的元素依次代表想要插队的人的编号，每次插队，这个人都会直接移动到队伍的最前方。
你需要返回一个整数，代表这 m 次插队行为之后，有多少个人已经不在原来队伍的位置了。

示例1
输入
复制
3,[3, 2, 3]
输出
复制
2
说明
初始队伍为 [1, 2, 3]
3 开始插队 [3, 1, 2]
2 开始插队 [2, 3, 1]
3 开始插队 [3, 2, 1]
所以2还在原来的尾置，3和1两个人已经不在原来的位置了。
示例2
输入
复制
3,[]
输出
复制
0
说明
没有人进行插队，所有人都在自己原来的位置上。
备注:
对于所有数据，保证 n \leq 1e9n≤1e9, m\leq 1e4m≤1e4，且 cutIn[i] \leq ncutIn[i]≤n
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	/**
	* 计算有多少个人最终不在自己原来的位置上
	* @param n int整型 队伍总长
	* @param cutIn int整型vector 依次会插队到最前方的人的编号
	* @return int整型
	*/
	int countDislocation(int n, vector<int>& cutIn) {
		// write code here
		int max_pos = 0;  //最大插队人编号
		int line = 1;     //插队队伍的编号
		int right = 0;     //插队后编号不变的人的数量
		map<int, int> m;
		for (int i = (int)cutIn.size() - 1; i >= 0; --i) {
			//重复插队。只算最后一次插队
			if (m.count(cutIn[i]) == 0) {
				m[cutIn[i]] = 1; //表明插队成功
				if (cutIn[i] == line) { //编号不变
					right += 1;  //人数加一
				}
				line += 1;
				max_pos = max(max_pos, cutIn[i]);
			}
		}
		return max_pos - right;
	}
};

int main()
{
	vector<int> cut{ 5241, 339, 155, 1514, 6887, 6769, 7763, 8997, 6435, 8930 };
	Solution ss;
	int k = ss.countDislocation(10000, cut);
	return 0;
}