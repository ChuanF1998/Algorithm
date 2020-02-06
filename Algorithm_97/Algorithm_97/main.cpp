/*
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

/*
思路：使用快慢指针先找出环的节点数量，一个块，一个慢，若有环，必然会相遇，路程差n为环节点数量。
在用两个指针p1、p2, p1指向头节点，p2指向头节点向后移动n个节点的位置，再以相同速度往后走，相遇的
那个节点则为入口节点
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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		int ring_count = ring(pHead);
		if (ring_count == 0) {
			return nullptr;
		}
		ListNode* p1 = pHead;
		ListNode* p2 = p1;
		while (ring_count--) {
			p2 = p2->next;
		}
		while (p1 != p2) {
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
	int ring(ListNode* pHead)
	{
		int count = 0;
		if (pHead == nullptr) {
			return count;
		}
		ListNode* p1 = pHead;
		ListNode* p2 = p1;
		int p1_count = 0;
		int p2_count = 0;
		while (p1 != nullptr && p2 != nullptr) {
			p1 = p1->next;
			p1_count++;
			p2 = p2->next;
			p2_count++;
			if (p2 != nullptr) {
				p2 = p2->next;
				p2_count++;
			}
			if (p1 == p2 && p1 && p2) {
				count = p2_count - p1_count;
				break;
			}
		}
		return count;
	}
};

int main()
{
	return 0;
}