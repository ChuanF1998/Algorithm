/*
��Ŀ����
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
*/

/*
˼·��ʹ�ÿ���ָ�����ҳ����Ľڵ�������һ���飬һ���������л�����Ȼ��������·�̲�nΪ���ڵ�������
��������ָ��p1��p2, p1ָ��ͷ�ڵ㣬p2ָ��ͷ�ڵ�����ƶ�n���ڵ��λ�ã�������ͬ�ٶ������ߣ�������
�Ǹ��ڵ���Ϊ��ڽڵ�
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