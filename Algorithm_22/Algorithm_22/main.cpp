/*
��Ŀ����
�����һ���㷨������������������ļӷ���


��������:
���������ַ�������

������� :
�����Ӻ�Ľ����string��

ʾ��1
����
99999999999999999999999999999999999999999999999999
1

���
100000000000000000000000000000000000000000000000000
*/

//˼·������һ����λcy=��0����������ͬλ����ټӽ�λλ�ĺʹ��ڡ�9������λcy=��1��
//��ѭ�����Ƚ��Ƚ϶̵��Ǹ������꣬Ȼ�����ý�λcy��Ƚϳ����Ǹ���ʣ��δ�ӵ�λ����ӣ�֪����������һλ
//����ʱcy��Ϊ��1������ͷ���ȥ ���� 9999 �� 1  -��10000��

#include <iostream>
#include <string>
using namespace std;

class string_add
{
public:
	string add(string str1, string str2)
	{
		char cy = '0';
		size_t length1 = str1.size();
		size_t length2 = str2.size();
		if (length1>length2){    //�жϳ��̣���Ϊ��Ҫ�ó����Ǹ���������
			while (length2>0) {
				str1[length1 - 1] += str2[length2 - 1] - '0' + cy - '0'; //���
				cy = '0';                       //cyλ�á�0��
				if (str1[length1 - 1]>'9'){     //��ӵĽ���н�λ
					cy = '1';                   //cyλ�á�1��
					str1[length1 - 1] -= 10;    //��ȥ��λ
				}
				length2--;
				length1--;
			}
			for (int i = length1 - 1; i >= 0; --i){
				str1[i] += cy - '0';
				cy = '0';
				if (str1[i]>'9'){
					cy = '1';
					str1[i] -= 10;
				}
			}
			if (cy == '1'){
				str1.insert(str1.begin(), '1');
				return str1;
			}
			else {
				return str1;
			}
		}
		else {
			while (length1>0) {
				str2[length2 - 1] += str1[length1 - 1] - '0' + cy - '0';
				cy = '0';
				if (str2[length2 - 1]>'9'){
					cy = '1';
					str2[length2 - 1] -= 10;
				}
				length2--;
				length1--;
			}
			for (int i = length2 - 1; i >= 0; --i){
				str2[i] += cy - '0';
				cy = '0';
				if (str2[i]>'9'){
					cy = '1';
					str2[i] -= 10;
				}
			}
			if (cy == '1'){
				str2.insert(str2.begin(), '1');
				return str2;
			}
			else {
				return str2;
			}
		}
	}
};


int main()
{
	string_add s;
	string str1, str2;
	while (cin >> str1 >> str2){
		cout << s.add(str1, str2) << endl;
	}
	return 0;
}