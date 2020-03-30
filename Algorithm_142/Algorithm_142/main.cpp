/*
��Ŀ����
��εõ�һ���������е���λ����������������ж�����������ֵ��
��ô��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ��
��ô��λ������������ֵ����֮���м���������ƽ��ֵ������ʹ��Insert()������ȡ��������
ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����
*/


#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		//�����Ϊ�ջ��߲�������С�ڴ���ѶѶ��������ݲ�������
		if (max_heap.empty() || num < max_heap.top()) {
			max_heap.push(num);
		}
		//����С����
		else {
			min_heap.push(num);
		}
		//�����������size����С����size������1�ͽ�����ѶѶ�pop��Ȼ����뵽С����
		if (max_heap.size() > min_heap.size() + 1) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		//������С����size���ڴ����size
		if (max_heap.size() < min_heap.size()) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
	}

	double GetMedian()
	{
		return (max_heap.size() > min_heap.size()) ? (double)max_heap.top() : ((double)max_heap.top() + (double)min_heap.top()) / 2;
	}
public:
	//��֤�����size���ڵ���С����size����������1. 
	//������ȡ��λ�������������������ѶѶ�
	//˫������������ѶѶ� + С���ѶѶ���  /  2 ��
	priority_queue<int, vector<int>, less<int> > max_heap;   //�����
	priority_queue<int, vector<int>, greater<int> > min_heap; //С����
};


int main()
{
	return 0;
}