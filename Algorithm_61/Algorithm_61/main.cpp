/*
��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr) {
			return nullptr;
		}
		ListNode* p1 = pHead;
		int count1 = 1;
		while (p1->next) {
			if (p1->val != p1->next->val) {
				break;
			}
			count1++;
			p1 = p1->next;
		}
		ListNode* p2 = p1->next;
		ListNode* p3 = p2;
		ListNode* p4 = p1;
		int count2 = 0;
		while (p2) {
			if (p2->val == p3->val) {
				count2++;
			}
			else {
				if (count2 > 1) {
					p4->next = p2;
					//ɾ���ڵ����
				}
				else {
					p4 = p4->next;
				}
				p3 = p2;
				count2 = 1;
			}
			p2 = p2->next;
		}
		if (count2 > 1) {
			p4->next = p2;
		}
		if (count1 > 1) {
			ListNode* p5 = pHead;
			pHead = p1->next;
			//ɾ���ڵ����
		}
		return pHead;
	}
};

int main()
{
	return 0;
}