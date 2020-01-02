/*
题目描述
小Q正在给一条长度为n的道路设计路灯安置方案。

为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。

小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。

小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。

输入描述:
输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路的长度。
第二行一个字符串s表示道路的构造,只包含'.'和'X'。
输出描述:
对于每个测试用例, 输出一个正整数表示最少需要多少盏路灯。
示例1
输入
2
3
.X.
11
...XX....XX

输出
1
3
*/


/*
思路：只要遇到存在是‘.’的情况，就把后两个也同时置为‘.’。
附加：也可以不用数组做，输入一个‘.’就再次直接向后输入两个‘.’
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
	int street_lamp_count(std::string& street)
	{
		int count = 0;
		size_t street_length = street.size();
		for (size_t i = 0; i < street_length - 1; ++i) {
			if (street[i] == '.') {
				street[i] = 'X';
				street[i + 1] = 'X';
				street[i + 2] = 'X';
				count++;
			}
		}
		if (street[street_length - 1] == '.') {
			count += 1;
		}
		return count;
	}
};

int main()
{
	int n;
	Solution s;
	std::vector<std::string> arr;
	while (std::cin >> n) {
		int length;
		std::string street;
		for (int i = 0; i < n; ++i) {
			std::cin >> length;
			std::cin >> street;
			arr.push_back(street);
		}
		for (int i = 0; i < n; ++i) {
			std::cout << s.street_lamp_count(arr[i]) << std::endl;
		}
		arr.clear();
	}
	return 0;
}