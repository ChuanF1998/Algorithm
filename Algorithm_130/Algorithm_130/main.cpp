/*
��Ŀ����
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵�����
�������ַ���ģ�����ָ���������������һ���������ַ�����S�������
��ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ��
����3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
*/

#include <string>
using namespace std;


//����һ���ָ��ַ���
class Solution1 {
public:
	string LeftRotateString(string str, int n) {
		int strSize = (int)str.size();
		if (strSize == 0) {
			return "";
		}
		n %= strSize;
		return str.substr(n, strSize) + str.substr(0, n);
	}
};

//���������ַ�������
class Solution2 {
public:
	string LeftRotateString(string str, int n) {
		int strSize = (int)str.size();
		if (strSize == 0) {
			return "";
		}
		n %= strSize;
		reverse(str.begin(), str.begin() + n);
		reverse(str.begin() + n, str.end());
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	return 0;
}