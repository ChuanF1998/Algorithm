/*
��Ŀ����
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,
���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ��
�ҳ����к�ΪS��������������? Good Luck!

�������:
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > arr;
		vector<int> sub;
		int s = 0;
		for (int i = 1; i < sum; ++i) {
			for (int j = i; j <= sum; ++j) {
				s += j;
				sub.push_back(j);
				if (s == sum && sub.size() > 1) {
					arr.push_back(sub);
					break;
				}
				if (s > sum) {
					break;
				}
			}
			sub.clear();
			s = 0;
		}
		return arr;
	}
};


int main()
{
	return 0;
}