/*
题目：Emacs计算器
题目描述
Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，
它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。
输入描述:
输入包含多组数据。

每组数据包括两行：第一行是一个正整数n (3≤n≤50)；
紧接着第二行包含n个由数值和运算符组成的列表。

“+- * /”分别为加减乘除四则运算，其中除法为整除，即“5 / 3 = 1”。
输出描述 :
对应每一组数据，输出它们的运算结果。
示例1
输入
复制
3<br / >2 3 + <br / >5<br / >2 2 + 3 * <br / >5<br / >2 2 3 + *
输出
复制
5<br / >12<br / >10
*/

// write your code here cpp
// write your code here cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	int n;
	string str;
	stack<string> s;
	while (cin >> n) {
		cin.get();
		getline(cin, str);
		int end = (int)str.size() - 1;
		int begin = 0;
		int re = 0;
		bool istrue = true;
		while (begin <= end) {
			if (str[begin] == ' ') {
				begin++;
				continue;
			}
			else if (str[begin] >= '0' && str[begin] <= '9') {
				string num;
				while (begin <= end && str[begin] != ' ') {
					num += str[begin];
					begin++;
				}
				s.push(num);
			}
			else {
				if (str[begin] == '+') {
					string num1 = s.top();
					s.pop();
					string num2 = s.top();
					s.pop();
					re = atoi(num2.c_str()) + atoi(num1.c_str());
					s.push(to_string(re));
				}
				else if (str[begin] == '-') {
					string num1 = s.top();
					s.pop();
					string num2 = s.top();
					s.pop();
					re = atoi(num2.c_str()) - atoi(num1.c_str());
					s.push(to_string(re));
				}
				else if (str[begin] == '*') {
					string num1 = s.top();
					s.pop();
					string num2 = s.top();
					s.pop();
					re = atoi(num2.c_str()) * atoi(num1.c_str());
					s.push(to_string(re));
				}
				else {
					string num1 = s.top();
					s.pop();
					string num2 = s.top();
					s.pop();
					if (atoi(num1.c_str()) == 0) {
						istrue = false;
						break;
					}
					re = atoi(num2.c_str()) / atoi(num1.c_str());
					s.push(to_string(re));
				}
			}
			begin++;
		}
		if (istrue == true) {
			cout << atoi(s.top().c_str()) << endl;
			s.pop();
		}
		while (!s.empty()) {
			s.pop();
		}
	}
	return 0;
}