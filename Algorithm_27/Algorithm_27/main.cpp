/*
��Ŀ����
д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������磺
��������:
����N���ַ�

�������:
������ַ�����ת����ַ���

ʾ��1
����
abcd

���
dcba
*/

//����C++��׼�⺯��reverse�����д���
//����C����������̵�˼ά��Ҳ���ѣ���������ָ�룬һ��
//ָͷ��һ��ָβ���������ݣ�ͷָ�����βָ��ʱ�˳�ѭ��

#if 0
//C++����
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	string str;
	while (getline(cin, str)) {
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}
#endif


//C��������
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

void c_reverse(char* str, size_t n)
{
	char* first = str;
	char* last = str + n - 1;
	while (last>first) {
		char temp = *first; //����
		*first = *last;
		*last = temp;
		++first;
		--last;
	}
}


int main()
{
	string str1;
	while (cin >> str1) {
		char *c_str1 = new char[str1.size() + 1]; //���ٿռ�
		strcpy(c_str1, str1.c_str());        //�����ַ���
		size_t n = str1.size();
		c_reverse(c_str1, n);       
		while (*c_str1 != '\0'){
			cout << *c_str1;
			++c_str1;
		}
		cout << endl;
	}
	return 0;
}