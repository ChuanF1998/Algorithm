/*
��Ŀ����
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/

//ջ1��������Ԫ�أ���Ҫ����Ԫ�ص�ʱ�򣬽�ջ1��Ԫ�س�ջ��������ջ2������ջ2��ջ��Ԫ�أ����ظ��˹���
//����ջ2��Ԫ�أ��ָ��ֳ�
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