/*
��Ŀ����
����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
*/


/*
����һ������ջ�Ƚ������ԭ���Ƚ������е�value�浽ջ�У��ٳ�ջ�ŵ�vector��
���������Ƚ��������ã���ֱ�ӷ��뵽vector��
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
			
		}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> arr;
		stack<int> s;
		while (head != nullptr) {
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty()) {
			arr.push_back(s.top());
			s.pop();
		}
		return arr;
	}
};

int main()
{
	return 0;
}