/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-last-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路:反向遍历，但反向开始的空格要去掉
*/

#include <string>


class Solution {
public:
	int lengthOfLastWord(std::string s) {
		if (s.size() == 0) {
			return 0;
		}
		int n = 0;
		auto rbegin = s.rbegin();
		auto rend = s.rend();
		while (rbegin < rend) {
			if (*rbegin == ' ') {
				++rbegin;
			}
			else {
				break;
			}
		}
		while (rbegin < rend) {
			if (*rbegin == ' ') {
				break;
			}
			++n;
			++rbegin;
		}
		return n;
	}
};

int main()
{
	return 0;
}