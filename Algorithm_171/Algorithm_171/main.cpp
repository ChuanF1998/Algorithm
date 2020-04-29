/*
��Ŀ��Ģ����
��Ŀ����
��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1,1),B��(n,m)��
����A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�����ÿ����ֻ����(i,j+1)��(i+1,j)������·�ߣ�
�ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����),�ʣ�A���ÿһ�����ѡ��Ļ�
(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�
��������:
��һ��N��M��K(1 �� N,M �� 20, k �� 100),N,MΪ�ݵش�С��������K�У�
ÿ����������x��y������(x,y)����һ��Ģ����
�������:
���һ�У������������(������2λС��)
ʾ��1
����
����
2 2 1<br/>2 1<br/>
���
����
0.50
*/



#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	void Get(vector<vector<double> >& arr, vector<vector<int> >& mogu, int n, int m)
	{
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (i == 1 && j == 1) {
					arr[i][j] = 1.0;
					continue;
				}
				if (i == n && j == m) {
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
					continue;
				}
				if (mogu[i][j] == 1) {
					arr[i][j] = 0;
					continue;
				}
				if (i == n) {
					arr[i][j] = arr[i - 1][j] * 0.5 + arr[i][j - 1];
				}
				else if (j == m) {
					arr[i][j] = arr[i][j - 1] * 0.5 + arr[i - 1][j];
				}
				else if (i == 1) {
					arr[i][j] = arr[i][j - 1] * 0.5;
				}
				else if (j == 1) {
					arr[i][j] = arr[i - 1][j] * 0.5;
				}
				else {
					arr[i][j] = arr[i][j - 1] * 0.5 + arr[i - 1][j] * 0.5;
				}
			}
		}
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << arr[n][m] << endl;
		return;
	}
};

int main()
{
	solution ss;
	int n;
	int m;
	int k;
	int x;
	int y;
	while (cin >> n >> m >> k) {
		vector<vector<double> > arr(n + 1, vector<double>(m + 1, 0));
		vector<vector<int> > mogu(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			mogu[x][y] = 1;
		}
		ss.Get(arr, mogu, n, m);
	}
	return 0;
}