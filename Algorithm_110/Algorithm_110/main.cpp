/*
��Ŀ����
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size()) {
			return false;
		}
		int pushVSize = pushV.size();
		int pushVpos = 0;  //pushV���±�
		int popVpos = 0;   //popv���±�
		stack<int> s;
		bool isPopOrder = true;  //�����ȼ��������ǳ�����
		while (popVpos < (int)popV.size()) { //ѭ����������ջ����δ�ж���
			//ջ��Ϊ�ջ�ջ��Ԫ���뵱ǰ��ջ��Ԫ�ز���ʱ��������δ��ȫѹ��ջ��
			if (s.empty() || (s.top() != popV[popVpos] && pushVpos < pushVSize)) {
				s.push(pushV[pushVpos]);  //��ջ�������Ԫ��
				pushVpos++;
			}
			//ջ��Ϊ����ջ��Ԫ�ص��ڵ�ǰ��ջ���е�ֵʱ�ͳ�ջ
			if (!s.empty() && s.top() == popV[popVpos]) { 
				s.pop();
				popVpos++;
			}
			//ջ��Ϊ����ѹջ�����Ѿ�ѹ����ջ�������ڵ�ǰ��ջ���е�ֵʱ���Ϳ����жϼ��費�������˳�
			if (!s.empty() && pushVSize == pushVpos && s.top() != popV[popVpos]) {
				isPopOrder = false;
				break;
			}
		}
		return isPopOrder;
	}
};

int main()
{
	return 0;
}