/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

//数据栈保存数据，辅组栈保存最小值
//当插入数据栈的值小于辅组栈的栈顶元素时，辅组栈插入该数据
//当插入数据栈的值大于辅组栈的栈顶元素时，辅组栈插入辅组栈的栈顶元素

#include <stack>
using namespace std;

class Solution {
public:
	void push(int value) {
		s.push(value);
		if (s_min.empty()) {
			s_min.push(value);
		}
		else {
			if (value < s_min.top()) {
				s_min.push(value);
			}
			else {
				s_min.push(s_min.top());
			}
		}
	}
	void pop() {
		if (!s.empty()) {
			s.pop();
		}
		if (!s_min.empty()) {
			s_min.pop();
		}
	}
	int top() {
		if (!s.empty()) {
			return s.top();
		}
	}
	int min() {
		if (!s_min.empty()) {
			return s_min.top();
		}
	}

private:
	stack<int> s;
	stack<int> s_min;
};

int main()
{
	return 0;
}