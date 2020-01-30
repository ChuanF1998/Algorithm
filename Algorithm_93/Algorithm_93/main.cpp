/*
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有
字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

/*
思路：
①遇到'.'时str和pattern就都向后移动一格，但是".*"可以任意匹配
②pattern + 1遇到'*'时，若pattern与str相等则要么
str + 1,pattern + 2 ---》 *代表1格
str + 1, pattern不变 ---》*代表多格
str不变，pattern + 2 ---》*代表0格

不等则str不变，pattern + 2                                          
③pattern + 1不是'*'号，若pattern与str相等则都往后移一格；不相等则返回false

*/

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr) {
			return false;
		}
		return is_matching(str, pattern);
	}

	bool is_matching(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0') {
			return true;
		}
		if (*str != '\0' && *pattern == '\0') {
			return false;
		}
		if (*(pattern + 1) == '*') {
			if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
				return is_matching(str + 1, pattern + 2)
					|| is_matching(str + 1, pattern)
					|| is_matching(str, pattern + 2);
			}
			else {
				return is_matching(str, pattern + 2);
			}
		}
		if (*(pattern + 1) != '*') {
			if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
				return is_matching(str + 1, pattern + 1);
			}
			else {
				return false;
			}
		}
		return false;
	}
};




int main()
{
	Solution s;
	char* a = "aaa";
	char* b = "aa*";
	bool m = s.match(a, b);
	return 0;
}