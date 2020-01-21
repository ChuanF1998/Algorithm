/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:

����: "race a car"
���: false

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/valid-palindrome
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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