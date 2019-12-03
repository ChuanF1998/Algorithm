/*
题目描述
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录
时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到
该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。

给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。

若没有金额超过总数的一半，返回0。
测试样例：
[1,2,3,2,2],5
返回：2
*/

//思路：先排序，然后遍历统计相同数字的大小，数量超过1/2输出。

#include <algorithm>
#include <vector>
using namespace std;


class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());
		int max_num = gifts[0];
		int max_count = 0;
		for (size_t i = 0; i<gifts.size(); ++i)
		{
			if (gifts[i]>max_num) {
				max_num = gifts[i];
				max_count = 0;
			}
			++max_count;
			if (max_count>n / 2) {
				return max_num;
			}
		}
		return 0;
	}
};


int main()
{
	return 0;
}