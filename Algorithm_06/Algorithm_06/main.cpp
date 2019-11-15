/*
��Ŀ����
���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ�
��������������ߡ�
��������:
��������������

�������:
���ؽ��

ʾ��1
����
2
2

���
6
*/

//�ⷨ��a[i][j]=a[i-1][j]+a[i][j-1],��ʾ�õ����·��=���·������+�ϱ�·������

#include <iostream>
#include <vector>
using namespace std;

class way_count
{
public:
	int Get_way(int n, int m)
	{
		vector< vector<int> >arr(n + 1, vector<int>(m + 1, 1));
		for (int i = 1; i<n + 1; ++i) {
			for (int j = 1; j < m + 1; ++j) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
		return arr[n][m];
	}
};

int main()
{
	way_count w;
	int n, m;
	while (cin >> n >> m) {
		cout << w.Get_way(n, m) << endl;
	}
	return 0;
}