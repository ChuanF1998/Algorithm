/*
��Ŀ����
�����Ĵ�����һ�������ͷ�����һ�����ַ�����
���硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�
ʱ�����õ���������ֱ����ַ���A���ַ���B��
�������ǳ�������û�а취���ַ���B�����ַ���
Aʹ�������ַ�����һ�����Ĵ�������ܻ���������
������Ѱ���ж����ֲ���취����ʹ�´���һ������
��������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ���
* ����ĸ��b��֮��: "abba" �ǻ���
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
�������������Ĵ�Ϊ2
��������:
ÿ���������ݹ����С�
��һ��Ϊ�ַ���A
�ڶ���Ϊ�ַ���B
�ַ������Ⱦ�С��100��ֻ����Сд��ĸ
�������:
���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����
ʾ��1
����
aba
b

���
2
*/




#include <iostream>
#include <string>
using namespace std;

class Palindrome_string
{
public:
	int get(string str1, string str2)
	{
		int count = 0;
		int flag = 1;
		string str_temp;
		size_t str1_length = str1.size();
		auto t_first = str_temp.begin();
		auto t_last = str_temp.end();
		for (size_t i = 0; i <= str1_length; ++i) {
			str_temp = str1;
			str_temp.insert(i, str2);
			t_first = str_temp.begin();
			t_last = str_temp.end() - 1;
			flag = 1;
			while (t_first < t_last) {
				if (*t_first != *t_last) {
					flag = 0;
					break;
				}
				++t_first;
				--t_last;
			}
			if (flag == 1) {
				++count;
			}
			str_temp.clear();
		}
		return count;
	}
};


int main()
{
	Palindrome_string p;
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << p.get(str1, str2) << endl;
	}
	return 0;
}