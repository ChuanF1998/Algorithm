/*
��Ŀ����
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(nullptr), random(nullptr) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		ListClone(pHead);
		RandomNode(pHead);
		return ListBreakUp(pHead);
	}

	//���ȸ���ÿ���ڵ㣬�������ƺ�Ľڵ����ԭ�ڵ����
	void ListClone(RandomListNode* pHead)
	{
		RandomListNode* Head = pHead;
		while (Head != nullptr) {
			RandomListNode* temp = new RandomListNode(Head->label);
			temp->next = Head->next;
			Head->next = temp;
			Head = Head->next->next;
		}
	}

	//��������ڵ�
	void RandomNode(RandomListNode* pHead)
	{
		RandomListNode* Head = pHead;
		while (Head != nullptr) {
			if (Head->random == nullptr) {}
			//˫���ڵ�����ָ��ָ��ǰһ�����������ָ�����һ���ڵ�
			//next:a->a'->b->b'->c->c'
			//random:a->c,��ô a'->c'
			else if (Head->random->next != nullptr) {
				Head->next->random = Head->random->next;
			}
			//���a->d, ��ô��Ҫ��Ϊd���ٿռ�
			else {
				RandomListNode* temp = new RandomListNode(Head->random->label);
				Head->next->random = temp;
			}
			Head = Head->next->next;
		}
	}

	//�������
	RandomListNode* ListBreakUp(RandomListNode* pHead)
	{
		if (pHead == nullptr) {
			return nullptr;
		}
		RandomListNode* Head = pHead;
		RandomListNode* pRoot = pHead->next;
		RandomListNode* newNode = pHead->next;
		Head->next = newNode->next;
		Head = Head->next;
		while (Head != nullptr) {
			newNode->next = Head->next;
			newNode = newNode->next;
			Head->next = newNode->next;
			Head = Head->next;
		}
		return pRoot;
	}
};

int main()
{
	return 0;
}