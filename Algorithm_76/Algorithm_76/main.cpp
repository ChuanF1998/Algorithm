/*
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

 

 示例 1：

 输入："ab-cd"
 输出："dc-ba"
 示例 2：

 输入："a-bC-dEf-ghIj"
 输出："j-Ih-gfE-dCba"
 示例 3：

 输入："Test1ng-Leet=code-Q!"
 输出："Qedo1ct-eeLg=ntse-T!"

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-only-letters
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路：双指针遍历
*/


#include <string>

class Solution {
public:
	std::string reverseOnlyLetters(std::string S) {
		auto first = S.begin();
		auto last = S.end() - 1;
		while (first < last) {
			if ((*first >= 'A' && *first <= 'Z') || (*first >= 'a' && *first <= 'z')) {
				if ((*last >= 'A' && *last <= 'Z') || (*last >= 'a' && *last <= 'z'))
				{
					char k = *first;
					*first = *last;
					*last = k;
					last--;
					first++;
				}
				else {
					last--;
				}
			}
			else {
				if ((*last >= 'A' && *last <= 'Z') || (*last >= 'a' && *last <= 'z'))
				{
					first++;
				}
				else {
					first++;
					last--;
				}
			}
		}
		return S;
	}
};

int main()
{
	return 0;
}