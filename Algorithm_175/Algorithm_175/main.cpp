/*
��Ŀ��ţ�ܺ�ţ���ֵ�����
��Ŀ����
������֪��ţ�ܺ�ţ���־����յ�С��˿�����������ÿ���������ض��ļ�ֵ��
������Ҫ�����ܰ����Լ����ü�ֵ��ƽ�������������

��ô�������ˣ������ŵ�����£��������еõ��������ֵ�͵���С��ֵ�Ƕ����أ�
p.s ���ﶼ��������Բ����Բ���Ŷ

ʾ��1
����
����
[1,2,3,4]
���
����
0
˵��
����һ������1,4 ����һ������2,3
ʾ��2
����
����
[1,3,5]
���
����
1
˵��
����һ������1��3.��һ������5
��ע:
���������ֵ������100���������С��100�����������ܼ�ֵ������10000
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param presentVec int����vector ÿ������ļ�ֵ
	* @return int����
	*/
	int maxPresent(vector<int>& presentVec) {
		// write code here
		int sum = 0;
		for (size_t i = 0; i < presentVec.size(); ++i) {
			sum += presentVec[i];
		}
		vector<int> arr(sum / 2 + 1, 0);
		for (int i = 0; i < presentVec.size(); ++i) {
			for (int j = arr.size() - 1; j >= presentVec[i]; --j) {
				arr[j] = max(arr[j], arr[j - presentVec[i]] + presentVec[i]);
			}
		}
		int remain = sum - arr[arr.size() - 1];
		int poor = remain - arr[arr.size() - 1];
		return poor > 0 ? poor : -1 * poor;
	}
};

int main()
{
	return 0;
}