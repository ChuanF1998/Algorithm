/*
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
�������ж��������Ƿ��и�������
*/

/*
˼·�����ά���鳤��Ϊx��y����Ҫ���ҵĶ���Ϊtarget����arr[x-1][0]��ʼ���������
target����arr[x-1][0]����ô�Ϳ���������һ����arr[0][0]--arr[x-1][0];�������target
С��arr[x-1][0]����ô����������һ����arr[x-1][0]--arr[x-1][y-1];
ѭ��������i>=0&&j<y; 
ͬ��Ҳ���Դ�arr[0][y-1]��ʼ
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		size_t x_size = array.size();
		size_t y_size = array[0].size();
		int x = x_size - 1;
		int y = 0;
		int i = x;
		int j = y;
		if (array[0][0] > target) {
			return false;
		}
		if (array[x_size - 1][y_size - 1] < target) {
			return false;
		}
		while (x >= 0 && y < y_size) {
			if (target == array[x][y]) {
				return true;
			}
			else if (target > array[x][y]) {
				y += 1;

			}
			else {
				x -= 1;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	vector<vector<int> >arr = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 25 }, { 6, 8, 11, 200 } };
	cout << arr[0][0] << " " << arr[3][3] << endl;
	s.Find(15, arr);
	return 0;
}