/*
��Ŀ�����ʵ���
��Ŀ����
���ַ����е����е��ʽ��е��š�

˵����

1�����ɵ��ʵ��ַ�ֻ��26����д��СдӢ����ĸ��

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ��
����ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��

��������:
����һ���Կո����ָ��ľ���

�������:
������ӵ�����

ʾ��1
����
I am a student

���
student a am I
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str)) {
		int times = 0;
		int be = 0;
		int space_count = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))) {
				space_count++;
			}
			else {
				if (space_count > 0 && times > 0) {
					str[be++] = ' ';
				}
				times += 1;
				space_count = 0;
				str[be++] = str[i];
			}

		}
		str = str.substr(0, be);
		reverse(str.begin(), str.end());
		be = 0;
		int end = 0;
		while (end < str.size()) {
			if (str[end] == ' ') {
				reverse(str.begin() + be, str.begin() + end);
				be = end + 1;
			}
			end++;
		}
		reverse(str.begin() + be, str.end());
		cout << str << endl;
	}
	return 0;
}