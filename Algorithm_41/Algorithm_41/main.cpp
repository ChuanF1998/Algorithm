/*
��Ŀ����
����һ���ַ���str������ַ���str�е�����������ִ�
��������:
�������������1������������һ���ַ���str�����Ȳ�����255��
�������:
��һ�������str��������������ִ���
ʾ��1
����
abcd12345ed125ss123456789

���
123456789
*/



#include <iostream>
#include <string>
using namespace std;

class num_str
{
public:
	string get_max(string str)
	{
		string min_str;
		string max_str;
		size_t str_length = str.size();
		for (size_t i = 0; i < str_length; ++i) {
			if (str[i] >= '0' && str[i] <= '9') {
				min_str.push_back(str[i]);
			}
			else {
				if (min_str.size() > 0) {
					if (min_str.size() > max_str.size()) {
						max_str = min_str;
					}
					min_str.clear();
				}
			}
		}
		if (min_str.size() > max_str.size()) {
			max_str = min_str;
		}
		return max_str;
	}
};


int main()
{
	num_str n;
	string str;
	while (getline(cin, str)) {
		cout << n.get_max(str) << endl;
	}
	return 0;
}