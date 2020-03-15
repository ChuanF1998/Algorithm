/*
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个
只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/

#include <string>
#include <vector>

class Solution {
public:
	int FirstNotRepeatingChar(std::string str) {
		if (str.size() == 0) {
			return -1;
		}
		std::vector<int> arr(255, 0);
		for (size_t i = 0; i < str.size(); ++i) {
			arr[str[i]]++;
		}
		for (size_t i = 0; i < str.size(); ++i) {
			if (arr[str[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	return 0;
}