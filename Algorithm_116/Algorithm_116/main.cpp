/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
	std::vector<std::string> Permutation(std::string str) {
		sort(str.begin(), str.end());
		int length = str.size();
		std::vector<std::string> arr;
		if (length == 1)  {
			arr.push_back(str);
			return arr;
		}
		func(arr, str, length, 0);
		std::sort(arr.begin(), arr.end());
		return arr;
	}
	void func(std::vector<std::string>& arr, std::string& str, int length, int prev)
	{
		if (prev == length && length != 0) {
			arr.push_back(str);
			return;
		}
		for (int i = prev; i < length; ++i) {
			if (i != prev && str[i] == str[prev]) {
				continue;
			}
			std::swap(str[prev], str[i]);
			func(arr, str, length, prev + 1);
			std::swap(str[prev], str[i]);
		}
	}

};

int main()
{
	return 0;
}