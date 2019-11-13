/*
题目描述:
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。

给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
*/

//思路：由于括号是成对出现的，只能为偶数，不能为奇数，
//然后比较‘（’和‘）’的数量，相等则为合法的括号串

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