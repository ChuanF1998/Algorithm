/*
��Ŀ���ַ�������
��Ŀ����
���ֵ�����s1��s2֮��ģ�������len1��len2���ַ����ĸ��������mod 1000007��

��������:
ÿ�����ݰ���s1������С��100����s2������С��100����len1��С��100000����len2������len1��С��100000��
�������:
����𰸡�
ʾ��1
����
����
ab ce 1 2
���
����
56
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace  std;


int main()
{
	string s1;
	string s2;
	int len1;
	int len2;
	while (cin >> s1 >> s2 >> len1 >> len2) {
		if (s1.compare(s2) >= 0) {
			cout << 0 << endl;
		}
		else {
			if ((int)s1.size() <= len2) {
				string tmp(len2 - s1.size() + 1, 96);
				s1 += tmp;
			}
			if ((int)s2.size() <= len2) {
				string tmp(len2 - s2.size() + 1, 96);
				s2 += tmp;
			}
			long long count = 0;
			for (int i = len1; i <= len2; ++i) {
				for (int j = 0; j < i; ++j) {
					long long k = s2[i - j - 1] - s1[i - j - 1];
					if (s2[i - j] == 96) {
						k -= 1;
					}
					count += k * (int)pow(26, j);
					//if (count)
				}
			}
			cout << count % 1000007 << endl;
		}
	}
	return 0;
}