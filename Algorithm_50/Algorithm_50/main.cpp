/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
整数，判断数组中是否含有该整数。
*/

/*
思路：设二维数组长度为x，y；需要查找的对象为target。从arr[x-1][0]开始，如果遇到
target大于arr[x-1][0]，那么就可以跳过这一竖列arr[0][0]--arr[x-1][0];如果遇到target
小于arr[x-1][0]，那么可以跳过这一横列arr[x-1][0]--arr[x-1][y-1];
循环条件是i>=0&&j<y; 
同理也可以从arr[0][y-1]开始
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