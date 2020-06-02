/*
��Ŀ��ţţ����
��Ŀ����
ţţ��һ��3*n�����ء����������3�У�n�С�ţţ����������������һ�仨��

Ϊ�˻����ܹ���׳�ɳ���ÿһ�仨�����������ĸ��������������Ļ������ж������ֻ��ķ�����

Ϊ��ֹ�𰸹��󣬴𰸶�1e9+7ȡģ��

ʾ��1
����
����
1
���
����
4
˵��
ֻ��1�У���1������0����յء���һ�е��ַ�������[1,0,0],[0,1,0],[0,0,1],[1,0,1]����
��ע:
1\le n\le 1e51��n��1e5
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	* ţţ����
	* @param n int���� ����
	* @return int����
	*/
	int solve(int n) {
		// write code here
		int fg = 1000000007;
		vector<vector<int> > arr(2, vector<int>(8, 0));
		int cur = 0;
		int pre = 1;
		arr[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			swap(cur, pre);
			for (int j = 0; j < 8; ++j) {
				arr[cur][j] = 0;
			}
			for (int mask = 0; mask < 8; ++mask) {
				if (mask == 3 || mask == 6 || mask == 7) {
					continue;
				}
				for (int index = 0; index < 8; ++index) {
					if (index == 3 || index == 6 || index == 7) {
						continue;
					}
					if ((index & mask) != 0) {
						continue;
					}
					arr[cur][mask] += arr[pre][index];
					arr[cur][mask] %= fg;
				}
			}
		}
		int result = 0;
		for (int i = 0; i < 8; ++i) {
			result = (result + arr[cur][i]) % fg;
		}
		return (result + fg - 1) % fg;
	}
};

int main()
{
	return 0;
}