/*
��Ŀ����
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת������
�Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
��������:
����һ���ַ���,����������ĸ����,����Ϊ��
�������:
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
ʾ��1
����
+2147483647
1a33

���
2147483647
0
*/

/*
1���������ж�  2������жϣ�int�ͱ�ʾ��Χ��  3���Ƿ��ַ��ж�
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		//int�� -2147483648��2147483647 
		//��unsigned int ��ԭ���������ж����ķ�Χ����int�͵Ļ��ڼӼ���ʱ��������
		//�Ļ��жϲ��ˣ����� 2147483648������Χ�ᱻת�� -2147483648
		unsigned int num = 0; 
		int symbol = 2;       
		int i = 0;
		if (str[0] == '+') {
			symbol = 0;
			++i;
		}
		if (str[0] == '-') {
			symbol = 1;
			++i;
		}
		for (int j = i; j < str.size(); ++j) {
			if (str[j] > '0' && str[j] <= '9') {
				num = 10 * num + str[j] - '0';
				if ((symbol == 0 || symbol == 2) && (num > 0x7fffffff)) {
					return 0;
				}
				if ((symbol == 1) && (num > 0x80000000)) {
					return 0;
				}
			}
			else {
				return 0;
			}
		}

		return (symbol == 1) ? -(int)num : (int)num;
	}
};

int main()
{
	Solution s;
	string str;
	while (cin >> str) {
		cout << s.StrToInt(str) << endl;
	}
	return 0;
}