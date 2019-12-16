/*
��Ŀ����
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/


#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length < 1) {
			return;
		}
		char* p = str;
		int count = 0;
		int original_length = 0;
		while (*p != '\0') {
			++original_length;
			if (*p == ' ') {
				++count;
			}
			++p;
		}
		int newlength = original_length + 2 * count;
		if (newlength > length) {
			return;
		}
		char* p1 = str + newlength;
		char* p2 = str + original_length;
		while (p1 != p2) {
			if (*p2 == ' ') {
				*(p1--) = '0';
				*(p1--) = '2';
				*(p1--) = '%';
				p2--;
			}
			else {
				*(p1--) = *(p2--);
			}
		}
	}
};

int main()
{
	Solution s;
	char b[30] = "da s as";
	cout << b + 1 << endl;
	s.replaceSpace(b, 30);
	return 0;
}