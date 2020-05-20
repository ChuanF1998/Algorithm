/*
��Ŀ��ţ�����·�
��Ŀ����
������֪��ţ����Ҫ�ܶ��·�����ֱ����ʱ�򴩵ġ����轣��ʱ�򴩵ġ��������ʱ�򴩵ġ��е��ٵ�ʱ�򴩵ģ��ȵ�
��Щ�·������ɹ̶���С�ľ��β��ϲü����ɣ��������ɵ�ţ��Ҳ֪��ÿ���·�����Ҫ�ľ�����β��ϵĳ��Ϳ�
Ȼ������ֻ��һ���Ĳ��Ͽɹ����ü����ü���ʱ���������
��ô�������ˣ������ţ�����������������ټ��·��أ�


ʾ��1
����
3,5,[[3 ,1],[4,1],[2,2],[2,2]]
���
5
��ע:
1.����ʹ��ʱ�޷���Ҫ�󣬵��� �����԰ѱ߽���ƴ�ɴ���
2.ÿ���·�ţ�ÿ��Բ�ֹҪһ��

���ݱ�֤ ��

0 < �·����� <=10

0 < ���ϵĳ�&��ÿ���·���&��  <= 1000  ��Ϊ����

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param L int���� �������ϵĳ�
	* @param W int���� �������ϵĿ�
	* @param clothSize int����vector<vector<>> �����о�ÿ���·�����ĳ��Ϳ�
	* @return int����
	*/
	int clothNumber(int L, int W, vector<vector<int> >& clothSize) {
		// write code here
		vector<vector<int> > arr(L + 1, vector<int>(W + 1, 0));
		int ma = 0;
		for (int i = 1; i <= L; ++i) {
			for (int j = 1; j <= W; ++j) {
				for (int k = 0; k < clothSize.size(); ++k) {
					int m = clothSize[k][0];
					int n = clothSize[k][1];
					if (i - m >= 0 && j - n >= 0) {
						arr[i][j] = max(arr[i][j], arr[i - m][j] + arr[m][j - n] + 1);
						arr[i][j] = max(arr[i][j], arr[i][j - n] + arr[i - m][n] + 1);
					}
					if (i - n >= 0 && j - m >= 0) {
						arr[i][j] = max(arr[i][j], arr[i - n][j] + arr[n][j - m] + 1);
						arr[i][j] = max(arr[i][j], arr[i][j - m] + arr[i - n][m] + 1);
					}
				}
				ma = max(ma, arr[i][j]);
			}
		}
		return ma;
	}
};

int main()
{
	Solution ss;
	vector<vector<int> > arr{ { 2, 2 }, { 2, 3 }, { 3, 2 }, { 2, 2 }, { 6, 1 }, { 7, 1 }, { 4, 4 }, { 5, 1 }, { 5, 2 }, { 5, 3 } };
	ss.clothNumber(7, 7, arr);
	return 0;
}
