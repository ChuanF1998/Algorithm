/*
��Ŀ����
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. 
�����������Ϊ��beijing. like I

��������:
ÿ�������������1������������ I like beijing. ��������
���Ȳ�����100

�������:
�����������֮����ַ���,�Կո�ָ�

ʾ��1
����
I like beijing.

���
beijing. like I
*/

//˼·���ȵ��������ַ���������һ������λ���ٱ���������
//�ո�ʱ�͵��ñ���λ�뵱ǰ�ո�֮��ĵ��ʣ��ٽ�����λ���±��
//����ǰ�ո�ĺ�һ��λ�ã�ѭ���˳�ʱ������ñ���λ��end֮��ĵ���
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class string_reverse
{
public:
	void reverse_str(string& str)
	{
		reverse(str.begin(), str.end());
		auto first = str.begin();
		auto end = str.end();
		auto it = first;
		while (first != end) {
			if (*first == ' ') {
				reverse(it, first);
				it = first + 1;
			}
			++first;
		}
		reverse(it, end);
	}
};


int main()
{
	string_reverse s;
	string str;
	while (getline(cin, str)) {
		s.reverse_str(str);
		cout << str << endl;
	}
	return 0;
}