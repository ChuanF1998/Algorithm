/*
��Ŀ����
���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磬���롱They are students.���͡�aeiou������ɾ��֮���
��һ���ַ�����ɡ�Thy r stdnts.��

��������:
ÿ�������������2���ַ���
�������:
���ɾ������ַ���

ʾ��1
����
They are students.
aeiou

���
Thy r stdnts.
*/

/*
˼·���ȶ���һ��255��С�����飬��ʼ��Ϊ0�����ַ���ASCLL����Ϊ�����±�
����str2�����ַ���Ӧ�±�������ֵ��1
����str1�����ַ���Ӧ�±������ֵΪ0���ַ����

���� a��ascll���Ӧ97����ôarr[97]��ֵ��1.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class public_string_delete
{
public:
	void delete_public(string& str1, string& str2)
	{
		size_t str1_length = str1.size();
		size_t str2_length = str2.size();
		vector<int> arr(255, 0);
		for (size_t i = 0; i < str2_length; ++i) {
			++arr[str2[i]];
		}
		for (size_t i = 0; i < str1_length; ++i) {
			if (arr[str1[i]] == 0) {
				cout << str1[i];
			}
		}
		cout << endl;
	}
};


int main()
{
	public_string_delete p;
	string str1;
	string str2;
	while (getline(cin, str1) && getline(cin, str2)) {
		p.delete_public(str1, str2);
	}
	return 0;
}