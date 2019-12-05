/*
��Ŀ����
����һ����ά����N*M������2<=N<=10;2<=M<=10������5 �� 5��������ʾ��

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻�
�����ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ�
��ڵ�Ϊ[0,0],�ȵ�һ�ո��ǿ����ߵ�·��

Input

һ��N �� M�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ��,�������ж�
�����������Թ�ֻ��һ��ͨ����

Output

���Ͻǵ����½ǵ����·������ʽ��������ʾ��

Sample Input

0 1 0 0 0

0 1 0 1 0

0 0 0 0 0

0 1 1 1 0

0 0 0 1 0

Sample Output

(0, 0)

(1, 0)

(2, 0)

(2, 1)

(2, 2)

(2, 3)

(2, 4)

(3, 4)

(4, 4)

��������:
���������������ֱ��ʾ��λ�������������������������Ӧ�����飬
���е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·�����ݱ�֤��Ψһ��,��������
������������Թ�ֻ��һ��ͨ����

�������:
���Ͻǵ����½ǵ����·������ʽ��������ʾ��

ʾ��1
����
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

���
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
*/



#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	void get_min(int i, int j, vector<vector<int> >& arr, vector<vector<int> >& arr_short, vector<vector<int> >& arr_long)
	{
		int n = arr.size();
		int m = arr[0].size();
		arr[i][j] = 1;
		arr_long.push_back({ i, j });
		if (i == n - 1 && j == m - 1) {
			if (arr_short.empty() || arr_long.size() < arr_short.size()) {
				arr_short = arr_long;
			}
		}
		//����
		if (j - 1 >= 0 && arr[i][j - 1] == 0) {
			get_min(i, j - 1, arr, arr_short, arr_long);
		}
		//����
		if (j + 1 < m && arr[i][j + 1] == 0) {
			get_min(i, j + 1, arr, arr_short, arr_long);
		}
		//����
		if (i - 1 >= 0 && arr[i - 1][j] == 0) {
			get_min(i - 1, j, arr, arr_short, arr_long);
		}
		//����
		if (i + 1 < n && arr[i + 1][j] == 0) {
			get_min(i + 1, j, arr, arr_short, arr_long);
		}
		arr[i][j] = 0;  //�ָ�����ǰ
		arr_long.pop_back(); //����β����Ԫ��
	}
};


int main()
{
	int n, m;
	solution s;
	while (cin >> n >> m) {
		vector<vector<int> > arr(n, vector<int>(m, 0));
		vector<vector<int> > arr_long;
		vector<vector<int> > arr_short;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j< m; ++j) {
				cin >> arr[i][j];
			}
		}
		s.get_min(0, 0, arr, arr_short, arr_long);
		for (size_t i = 0; i < arr_short.size(); ++i) {
			cout << '(' << arr_short[i][0] << ',' << arr_short[i][1] << ')' << endl;
		}
	}
	return 0;
}