/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

//栈1用来插入元素，当要弹出元素的时候，将栈1的元素出栈并依次入栈2，弹出栈2的栈顶元素，再重复此过程
//弹出栈2的元素，恢复现场
#include <stack>
using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int pop = stack2.top();
		stack2.pop();
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return pop;

	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	return 0;
}