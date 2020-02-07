/*
��Ŀ����
����һ��������ת��������������ı�ͷ��
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr) {
			return nullptr;
		}
		ListNode* p1 = pHead;
		ListNode* p2 = p1;
		ListNode* p3 = nullptr;
		while (p1) {
			p2 = p1->next;
			p1->next = p3;
			p3 = p1;
			p1 = p2;
		}
		return p3;
	}
};

int main()
{
	return 0;
}