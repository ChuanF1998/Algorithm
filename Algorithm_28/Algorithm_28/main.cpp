/*
��Ŀ����
��Ŀ���⣺

���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд


��������:
���������ַ���

�������:
���һ������

ʾ��1
����
asdfas werasdfaswer

���
6
*/



#include <iostream>
#include <string>
using namespace std;

class max_str_length
{
public:
	size_t get_max_strlength(string str1, string str2)
	{
		size_t str1_length = str1.size();
		size_t str2_length = str2.size();
		string max_str;
		string min_str;
		for (size_t i = 0; i<str1_length; ++i) {
			for (size_t j = 1; j <= str1_length - i; ++j) {
				min_str = str1.substr(i, j);
				size_t pos = str2.find(min_str);
				if (pos != string::npos) {
					if (min_str.size() > max_str.size()) {
						max_str = min_str;
					}
				}
			}
		}
		return max_str.size();
	}
};



int main()
{
	max_str_length m;
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << m.get_max_strlength(str1, str2) << endl;
	}
	return 0;
}