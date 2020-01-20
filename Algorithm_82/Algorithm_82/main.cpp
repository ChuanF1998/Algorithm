/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>

class Solution {
public:
	std::string addBinary(std::string a, std::string b) {
		if (a.size() == 0 && b.size() == 0) {
			return "";
		}
		std::string str1;
		std::string str2;
		if (a.size() > b.size()) {
			str1 = a;
			str2 = b;
		}
		else {
			str1 = b;
			str2 = a;
		}
		auto str1_rfirst = str1.rbegin();
		auto str2_rfirst = str2.rbegin();
		char carry = '0';
		while (str1_rfirst < str1.rend() && str2_rfirst < str2.rend()) {
			char bit_sum = *str1_rfirst + *str2_rfirst + carry - '0' - '0';
			carry = '0';
			if (bit_sum == '2') {
				carry = '1';
				*str1_rfirst = '0';
			}
			else if (bit_sum == '3') {
				carry = '1';
				*str1_rfirst = '1';
			}
			else {
				*str1_rfirst = bit_sum;
			}
			str1_rfirst++;
			str2_rfirst++;
		}
		while (str1_rfirst < str1.rend()) {
			char bit_sum = *str1_rfirst + carry - '0';
			carry = '0';
			if (bit_sum == '2') {
				*str1_rfirst = '0';
				carry = '1';
			}
			else {
				*str1_rfirst = bit_sum;
			}
			str1_rfirst++;
		}
		if (carry == '0') {
			return str1;
		}
		else {
			str1.insert(str1.begin(), carry);
			return str1;
		}
	}
};

int main()
{
	return 0;
}