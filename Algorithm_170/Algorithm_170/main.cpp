/*
��Ŀ�������
��Ŀ����
��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש��
��վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ���
��дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��
��������:
��������������ݡ�

ÿ�����ݵ�һ������������ m �� n��1��m, n��20���������� m �У�ÿ�а��� n ���ַ���
ÿ���ַ���ʾһ���ש����ɫ���������£�

1. ��.������ɫ�Ĵ�ש��
2. ��#������ɫ�Ĵ�ש��
3. ��@������ɫ�Ĵ�ש��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ�Ρ�
�������:
��Ӧÿ�����ݣ�����ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��
ʾ��1
����
����
9 6<br/>....#.<br/>.....#<br/>......<br/>......<br/>......<br/>......<br/>......<br/>#@...#<br/>.#..#.
���
����
45
*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	int Get(vector<vector<char> >& arr, int m, int n, int x, int y)
	{
		vector<vector<char> > tmp = arr;
		//func(arr, tmp, m, n, x, y);
		return func(arr, tmp, m, n, x, y) + 1;
		//return 0;
	}

	int func(vector<vector<char> >& arr, vector<vector<char> >& tmp, int m, int n, int x, int y)
	{
		if (x >= 0 && x < m && y >= 0 && y < n) {
			arr[x][y] = '#';
		}
		int count = 0;
		if (x - 1 >= 0 && arr[x - 1][y] == '.') {
			count += func(arr, tmp, m, n, x - 1, y) + 1;
		}
		if (x + 1 < m && arr[x + 1][y] == '.') {
			count += func(arr, tmp, m, n, x + 1, y) + 1;
		}
		if (y - 1 >= 0 && arr[x][y - 1] == '.') {
			count += func(arr, tmp, m, n, x, y - 1) + 1;
		}
		if (y + 1 < n && arr[x][y + 1] == '.') {
			count += func(arr, tmp, m, n, x, y + 1) + 1;
		}
		return count;
	}
};

int main()
{
	int m;
	int n;
	int x;
	int y;
	solution ss;
	while (cin >> m >> n) {
		vector<vector<char> > arr(m, vector<char>(n, '0'));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					x = i;
					y = j;
				}
			}
		}
		cout << ss.Get(arr, m, n, x, y) << endl;
	}
	return 0;
}