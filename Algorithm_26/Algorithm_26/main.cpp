/*
��Ŀ����
���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
��������:
���������ַ���
�������:
�����ظ����ֵ��ַ�

ʾ��1
����
abcdefghijklmnop
abcsafjklmnopqrstuvw

���
jklmnop
*/


#include <iostream>
#include <string>
using namespace std;

class max_substr
{
public:
	string get_max_substr(string str1, string str2)
	{
		size_t str1_length = str1.size();
		size_t str2_length = str2.size();
		if (str2_length<str1_length){   //Ϊ����str2�ĳ�����Զ����str1
			string temp = str1;
			str1 = str2;
			str2 = temp;
		}
		str1_length = str1.size(); //���¸�ֵ
		str2_length = str2.size();
		string min_str;
		string max_str;
		for (size_t i = 0; i<str1_length; ++i) {
			for (size_t j = 1; j<str1_length - i; ++j) {
				min_str = str1.substr(i, j);  //��min_str�����Ӵ�
				size_t pos = str2.find(min_str); //��str2�в���
				if (pos != string::npos) {        //���ҵ������룻δ�ҵ���������һ��ѭ��
					if (min_str.size() > max_str.size()){ //min_str�ĳ��ȴ���max_str��r
						max_str = min_str;                //��min_str�����ݸ���max_st
					}
				}
			}
		}
		return max_str;
	}
};

int main()
{
	max_substr m;
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2)) {
		cout << m.get_max_substr(str1, str2) << endl;
	}
	return 0;
}