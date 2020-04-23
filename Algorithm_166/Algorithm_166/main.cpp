/*
��Ŀ��ţ�õ�����
��Ŀ����
������֪��ţ���кܶ�ܶ��˿����˿���˺ܶ�ܶ������ţ�ã�ţ�õ���������˵ذ塣
�ذ���N\times MN��M�ĸ��ӣ�ÿ����������ֻ��һ�����ţ����֪ÿ������������
�ذ�����������Ͻ�(1,1)  ���½ǣ�N, M����
ţ��ֻ��Ҫ���������Ͻ��ߵ����½ǣ�ÿ����һ����ÿ��ֻ��������һ������������һ��������������һ��
ÿ���߹�һ�����ӣ����𣨲��ұ������ϣ���������ϵ����
ţ����֪���������ߵ����������������������С���Ƕ��٣�
ʾ��1
����
����
[[1,2,3],[2,3,4]]
���
����
7
˵��
(1,1)->(1,2)->(2,3)
��ע:
0<N,M<300
ÿ����������С��100
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param presentVolumn int����vector<vector<>> N*M�ľ���ÿ��Ԫ��������ذ�ש�ϵ��������
	* @return int����
	*/
	int selectPresent(vector<vector<int> >& presentVolumn) {
		// write code here
		int n = (int)presentVolumn.size();
		int m = (int)presentVolumn[0].size();
		if (n == 0 || m == 0) {
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 && j == 0) {
					presentVolumn[i][j] = presentVolumn[i][j];
				}
				else if (i == 0 && j > 0) {
					presentVolumn[i][j] += presentVolumn[i][j - 1];
				}
				else if (i > 0 && j == 0) {
					presentVolumn[i][j] += presentVolumn[i - 1][j];
				}
				else {
					int tmp = min(presentVolumn[i - 1][j], presentVolumn[i][j - 1]);
					presentVolumn[i][j] += min(presentVolumn[i - 1][j - 1], tmp);
				}
			}
		}
		return presentVolumn[n - 1][m - 1];
	}
};

int main()
{
	return 0;
}