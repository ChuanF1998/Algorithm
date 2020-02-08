/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr) {
			return pHead2;
		}
		if (pHead2 == nullptr) {
			return pHead1;
		}
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		while (p1 != nullptr && p2 != nullptr) {
			if (p2->val >= p1->val) {
				while (p1->next != nullptr && p2->val >= p1->val && p2->val >= p1->next->val) {
					p1 = p1->next;
				}
				ListNode* temp = p1;
				p1 = p1->next;
				temp->next = p2;
			}
			else {
				while (p2->next != nullptr && p2->val <= p1->val && p2->next->val <= p1->val) {
					p2 = p2->next;
				}
				ListNode* temp = p2;
				p2 = p2->next;
				temp->next = p1;
			}
		}
		return pHead1->val <= pHead2->val ? pHead1 : pHead2;
	}
};

int main()
{
	return 0;
}