/*
题目描述
牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，
但是他需要知道自己面向哪个方向，请你帮帮他。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示转方向的次数N(N<=1000)。
接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。
输出描述:
输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。
示例1
输入
3
LRR

输出
E
*/

/*
思路：如果每一次都转一个方向，则需要4次才能与开始方向一致，所以可以将问题简化，
左转与右转的次数模4得到一个余数，后面就考虑左右转次数不同差值时的方向。
*/

#include <iostream>
#include <string>

class Solution
{
public:
	char direction_of(std::string& str)
	{
		int L_count = 0;
		int R_count = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == 'L') {
				++L_count;
			}
			if (str[i] == 'R') {
				++R_count;
			}
		}
		int L_remain = L_count % 4;
		int R_remain = R_count % 4;
		if (L_remain == R_remain) {
			return 'N';
		}
		else if (L_remain - R_remain == 1 || R_remain - L_remain == 3) {
			return 'W';
		}
		else if (R_remain - L_remain == 1 || L_remain - R_remain == 3) {
			return 'E';
		}
		else {
			return 'S';
		}
	};
};

int main()
{
	Solution s;
	int n;
	std::string str;
	while (std::cin >> n) {
		str.resize(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> str[i];
		}
		std::cout << s.direction_of(str) << std::endl;
		str.clear();
	}
	return 0;
}