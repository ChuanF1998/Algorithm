/*
��Ŀ����������
��Ŀ����
����һ������ΪN(N>1)����������A�����Խ�A���ֳ������������֣�
�󲿷�A[0..K]���Ҳ���A[K+1..N-1]��K����ȡֵ�ķ�Χ��[0,N-2]��
����ô�໮�ַ����У��󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ������Ƕ��٣�

������������A������Ĵ�Сn���뷵����Ŀ����Ĵ𰸡�

����������
[2,7,3,1,1],5
���أ�6
*/

#include <vector>
#include <algorithm>
using namespace std;

class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		vector<int> m(n, 0);
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1) {
				m[i] = A[i];
				continue;
			}
			m[i] = max(m[i + 1], A[i]);
		}
		int max_poor = 0;
		int max_num;
		for (int i = 0; i < n - 1; ++i) {
			if (i == 0) {
				max_num = A[0];
				max_poor = max_num - m[i + 1];
				max_poor = max_poor >= 0 ? max_poor : -max_poor;
				continue;
			}
			if (A[i] > max_num) {
				max_num = A[i];
			}
			int tmp = max_num - m[i + 1];
			tmp = tmp >= 0 ? tmp : -tmp;
			if (tmp > max_poor) {
				max_poor = tmp;
			}
		}
		return max_poor;
	}
};

int main()
{
	return 0;
}