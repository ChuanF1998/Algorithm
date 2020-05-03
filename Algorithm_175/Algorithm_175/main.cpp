/*
题目：牛能和牛可乐的礼物
题目描述
众所周知，牛能和牛可乐经常收到小粉丝们送来的礼物，每个礼物有特定的价值，
他俩想要尽可能按照自己所得价值来平均分配所有礼物。

那么问题来了，在最优的情况下，他俩手中得到的礼物价值和的最小差值是多少呢？
p.s 礼物都很珍贵，所以不可以拆开算哦

示例1
输入
复制
[1,2,3,4]
输出
复制
0
说明
他俩一个人拿1,4 。另一个人拿2,3
示例2
输入
复制
[1,3,5]
输出
复制
1
说明
他俩一个人拿1，3.另一个人拿5
备注:
单个礼物价值不超过100，礼物个数小于100，所有礼物总价值不超过10000
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param presentVec int整型vector 每个礼物的价值
	* @return int整型
	*/
	int maxPresent(vector<int>& presentVec) {
		// write code here
		int sum = 0;
		for (size_t i = 0; i < presentVec.size(); ++i) {
			sum += presentVec[i];
		}
		vector<int> arr(sum / 2 + 1, 0);
		for (int i = 0; i < presentVec.size(); ++i) {
			for (int j = arr.size() - 1; j >= presentVec[i]; --j) {
				arr[j] = max(arr[j], arr[j - presentVec[i]] + presentVec[i]);
			}
		}
		int remain = sum - arr[arr.size() - 1];
		int poor = remain - arr[arr.size() - 1];
		return poor > 0 ? poor : -1 * poor;
	}
};

int main()
{
	return 0;
}