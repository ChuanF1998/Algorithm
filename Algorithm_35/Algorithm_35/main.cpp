/*
��Ŀ����
С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ��
�齱��Ϸ����Ϸ��һ��6*6�������Ͻ��У��������36����ֵ���ȵ����ÿ��С��
�������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ
�����������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨ʹС��
�õ���ֵ��ߵ����

����һ��6*6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],��
�����ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000��
*/

/*
������Ҫʹ�ö�̬�滮��⡣
����f(i,j)��ʾ�����Ͻ��ߵ�����(i��j)���ܻ�õ��������
�������д����Ͻ��ߵ����½ǵ�·�����ҵ�����·����
f(i,j)�����������
��һ�У�f(i, 0) = f(i-1, 0) + board(i, 0)
��һ�У�f(0,j) = f(0, j - 1) + b(0, j)
����λ�ã�f(i, j) = max{f(i-1, j), f(i, j - 1)} + board(i, j)
*/

#include <algorithm>
#include <vector>
using namespace std;

class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int x = board.size();
		int y = board[0].size();
		for (int i = 1; i<x; ++i) {
			board[i][0] = board[i - 1][0] + board[i][0];
		}
		for (int i = 0; i<y; ++i) {
			board[0][i] = board[0][i] + board[0][i - 1];
		}
		for (int i = 1; i<x; ++i) {
			for (int j = 1; j<y; ++j) {
				board[i][j] = board[i][j] + max(board[i - 1][j], board[i][j - 1]);
			}
		}
		return board[x - 1][y - 1];
	}
};

int main()
{
	return 0;
}