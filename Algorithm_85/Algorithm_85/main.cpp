/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <ctype.h>
#include <string>

class Solution {
public:
	bool isPalindrome(std::string s) {
		auto first = s.begin();
		auto last = s.end() - 1;
		while (first < last) {
			if (isalnum(*first) != 0 && isalnum(*last) != 0) {
				if ((*first >= '0' && *first <= '9') || (*last <= '9' && *last >= '0')) {
					if (*first == *last) {
						first++;
						last--;
					}
					else {
						return false;
					}
				}
				else {
					if ((*first == *last) || (*first - 32 == *last) || (*first + 32 == *last)) {
						first++;
						last--;
					}
					else {
						return false;
					}
				}

			}
			else {
				if (isalnum(*first) == 0) {
					first++;
				}
				if (isalnum(*last) == 0) {
					last--;
				}
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}