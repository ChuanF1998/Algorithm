/*
��Ŀ����
����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
��������:
����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
�������:
Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����
Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�

ʾ��1
����
7 2

���
111
*/



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class conversion_of_system
{
public:
	string get_system(int n, int sys)
	{
		int k = 0;
		if (n < 0) {
			k = 1;
			n = -n;
		}
		string str;
		while (n > 0) {
			int remainder = n % sys;
			if (remainder == 10) {
				str.push_back('A');
			}
			else if (remainder == 11) {
				str.push_back('B');
			}
			else if (remainder == 12) {
				str.push_back('C');
			}
			else if (remainder == 13) {
				str.push_back('D');
			}
			else if (remainder == 14) {
				str.push_back('E');
			}
			else if (remainder == 15) {
				str.push_back('F');
			}
			else {
				str.push_back(remainder + '0');
			}
			n = (n - remainder) / sys;
		}
		if (k == 1) {
			str.push_back('-');
		}
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	conversion_of_system c;
	int n, sys;
	while (cin >> n >> sys) {
		cout << c.get_system(n, sys) << endl;
	}
	return 0;
}