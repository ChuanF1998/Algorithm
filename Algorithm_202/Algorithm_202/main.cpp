/*
��Ŀ��
��Ŀ����
����һ��������дӢ����ĸ�����ֵľ��ӣ��ҳ��������������������ʮ������������
�������������ֵ�����ݱ�֤��������int��ʾ��Χ��

ʾ��1
����
����
"012345BZ16"
���
����
1193051
˵��
12345B��Ӧʮ����Ϊ1193051
��ע:
0<�ַ�������<=105
*/
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
	/**
	*
	* @param s string�ַ���
	* @return int����
	*/
	int func(string& str)
	{
		int num = 0;
		int k = 0;
		int end = str.size() - 1;
		for (int i = end; i >= 0; --i) {
			if (str[i] >= '0' && str[i] <= '9') {
				num += (str[i] - '0') * (int)pow(16, k);
			}
			if (str[i] >= 'A' && str[i] <= 'F') {
				num += (str[i] - 'A' + 10) * (int)pow(16, k);
			}
			k += 1;
		}
		return num;
	}
	int solve(string s) {
		// write code here
		int cur = 0;
		int max = 0;
		int pos = 0;
		int begin = 0;
		int wei = pos - begin;
		while (pos < s.size()) {
			if ((s[pos] >= '0' && s[pos] <= '9') || (s[pos] >= 'A' && s[pos] <= 'F')) {
				begin = pos;
				while ((s[pos] >= '0' && s[pos] <= '9') || (s[pos] >= 'A' && s[pos] <= 'F')) {
					pos++;
				}
				if (pos - begin >= wei) {
					wei = pos - begin;
					string str = s.substr(begin, wei);
					cur = func(str);
					if (cur > max) {
						max = cur;
					}
				}
			}
			pos++;
		}
		return max;
	}
};

int main()
{
	return 0;
}