/*
��Ŀ����
����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� 
{2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
*/

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> arr;
		if (size == 1) {
			return num;
		}
		if (size == 0) {
			return arr;
		}
		deque<int> dq;
		for (size_t i = 0; i < num.size(); ++i) {
			while (!dq.empty() && num[i] > num[dq.back()]) {
				dq.pop_back();
			}
			while (!dq.empty() && i - dq.front() >= size) {
				dq.pop_front();
			}
			dq.push_back(i);
			if (i + 1 >= size) {
				arr.push_back(num[dq.front()]);
			}
		}
		return arr;
	}
};

int main()
{
	vector<int> arr{ 2, 3, 4, 2, 6, 2, 5, 1 };
	Solution s;
	s.maxInWindows(arr, 3);
	return 0;
}