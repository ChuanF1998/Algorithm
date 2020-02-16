/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> arr;
		int cols = matrix[0].size();
		int rows = matrix.size();
		int i = 0;
		int j = 0;
		int x_pos = 0;
		int y_pos = 0;
		int module = 1;
		while (i < rows && j < cols) {
			if (module == 1) {
				while (x_pos < cols) {
					arr.push_back(matrix[i][x_pos]);
					x_pos++;
				}
				i++;
				y_pos = i;
				module = 2;
			}
			else if (module == 2) {
				while (y_pos < rows) {
					arr.push_back(matrix[y_pos][cols - 1]);
					y_pos++;
				}
				cols--;
				x_pos = cols - 1;
				module = 3;
			}
			else if (module == 3) {
				while (x_pos >= j) {
					arr.push_back(matrix[rows - 1][x_pos]);
					x_pos--;
				}
				rows--;
				y_pos = rows - 1;
				module = 4;
			}
			else {
				while (y_pos >= i) {
					arr.push_back(matrix[y_pos][j]);
					y_pos--;
				}
				j++;
				x_pos = j;
				module = 1;
			}
		}
		return arr;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > arr(4, vector<int>(3, 0));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			arr[i][j] = i + j;
		}
	}
	s.printMatrix(arr);
	return 0;
}