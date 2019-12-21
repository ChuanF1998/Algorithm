/*
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标
和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进
入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

/*
回溯法：
①如果该格子满足条件，则进入该格子，然后将该格子标记为1，表示已经走过了
②然后继续判断该格子的上下左右，满足条件则执行过程①
当已经判断过该格子的上下左右，则退出该格子，返回之前的格子，
当已经退到第一次进入的格子时，即表示找出所有满足条件的格子，结束。
*/

#include <vector>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<int> arr(rows * cols, 0);
		return can_move(threshold, rows, cols, 0, 0, arr);
	}

	int can_move(int threshold, int rows, int cols, int x, int y, vector<int>& arr)
	{
		int count = 0;
		if (x >= 0 && x < rows && y >= 0 && y < cols && arr[x * cols + y] == 0 && plus_count(x) + plus_count(y) <= threshold) {
			arr[x * cols + y] = 1;
			count = 1 + can_move(threshold, rows, cols, x - 1, y, arr)
				+ can_move(threshold, rows, cols, x + 1, y, arr)
				+ can_move(threshold, rows, cols, x, y - 1, arr)
				+ can_move(threshold, rows, cols, x, y + 1, arr);
		}
		return count;

	}

	int plus_count(int n)
	{
		int count = 0;
		int position = 0;
		while (n) {
			position = n % 10;
			count += position;
			n = (n - position) / 10;
		}
		return count;
	}
};

int main()
{
	return 0;
}