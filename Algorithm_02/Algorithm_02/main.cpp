/*
��Ŀ����:
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���

����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���

����������
"(()())",6
���أ�true
����������
"()a()()",7
���أ�false
*/

//˼·�����������ǳɶԳ��ֵģ�ֻ��Ϊż��������Ϊ������
//Ȼ��Ƚϡ������͡������������������Ϊ�Ϸ������Ŵ�

#include <iostream>
#include <string>
using namespace std;


class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		int i = 0;
		if (n % 2 == 1) {
			return false;
		}
		int count1 = 0;
		int count2 = 0;
		while (i< n) {
			if (A[i] == '('){
				count1++;
				++i;
			}
			else if (A[i] == ')'){
				count2++;
				++i;
			}
			else {
				return false;
			}
		}
		if (count1 == count2) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	string s;
	Parenthesis p;
	while (getline(cin, s)) {
		int n = s.size();
		cout << p.chkParenthesis(s, n) << endl;
	}
	return 0;
}