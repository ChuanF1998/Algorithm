/*
��Ŀ�����Թ�
��Ŀ����
NowCoder��ϲ�����ֳ����Թ���Ϸ������С����Ǳ���˭���߳��Թ���
���ڰ��Թ��ĵ�ͼ���㣬���ܰ����������߳��Թ���Ҫ���ٲ���
��������:
��������������ݡ�

ÿ�����ݰ���һ��10*10���ɡ�#���͡�.����ɵ��Թ������С�#������ǽ����.������ͨ·��

����ڵ�һ�еڶ��У����������һ�еھ��С�

������һ����.���㶼��һ���ߵ����������ĸ�����ġ�.���㡣
�������:
��Ӧÿ�����ݣ��������ڵ����������Ҫ������

*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > arr(10, vector<char>(10, '0'));
vector<vector<int> > tmp(10, vector<int>(10, 0));

bool input()
{
	char k;
	if (cin >> k) {
		for (int i = 0; i < 10; ++i){
			for (int j = 0; j < 10; ++j) {
				if (i == 0 && j == 0) {
					arr[i][j] = k;
				}
				else {
					cin >> arr[i][j];
				}
			}
		}
		return true;
	}
	return false;
}


void func(int x, int y)
{
	if (x + 1 <= 9 && arr[x + 1][y] == '.') {
		if (tmp[x + 1][y] == 0 || tmp[x][y] + 1 < tmp[x + 1][y]) {
			tmp[x + 1][y] = tmp[x][y] + 1;
			func(x + 1, y);
		}
	}
	if (x - 1 >= 0 && arr[x - 1][y] == '.') {
		if (tmp[x - 1][y] == 0 || tmp[x][y] + 1 < tmp[x - 1][y]) {
			tmp[x - 1][y] = tmp[x][y] + 1;
			func(x - 1, y);
		}
	}
	if (y + 1 <= 9 && arr[x][y + 1] == '.') {
		if (tmp[x][y + 1] == 0 || tmp[x][y] + 1 < tmp[x][y + 1]) {
			tmp[x][y + 1] = tmp[x][y] + 1;
			func(x, y + 1);
		}
	}
	if (y - 1 >= 0 && arr[x][y - 1] == '.') {
		if (tmp[x][y - 1] == 0 || tmp[x][y] + 1 < tmp[x][y - 1]) {
			tmp[x][y - 1] = tmp[x][y] + 1;
			func(x, y - 1);
		}
	}
	return;
}

int Least_step()
{
	func(0, 1);
	return tmp[9][8];
}

int main()
{
	while (input()) {
		cout << Least_step() << endl;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				tmp[i][j] = 0;
			}
		}
		//tmp.resize(10, vector<int>(10, 0));
	}
	return 0;
}