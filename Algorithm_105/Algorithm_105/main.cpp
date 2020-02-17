/*
��Ŀ����
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
*/

//����ջ�������ݣ�����ջ������Сֵ
//����������ջ��ֵС�ڸ���ջ��ջ��Ԫ��ʱ������ջ���������
//����������ջ��ֵ���ڸ���ջ��ջ��Ԫ��ʱ������ջ���븨��ջ��ջ��Ԫ��

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