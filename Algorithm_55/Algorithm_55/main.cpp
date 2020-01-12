
#include <vector>
using namespace std;

class Solution {
public:
	//rows表示矩阵长，cols表示宽
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		vector<vector<int> >arr(rows, vector<int>(cols, 0));
		//矩阵中每一个节点都要被当做开头
		for (int i = 0; i < rows; ++i) {        
			for (int j = 0; j < cols; ++j) {
				if (fun(arr, matrix, i, j, str, 0,rows, cols)) {
					return true;
				}
			}
		}
		return false;
	}
	//i , j 表示此时的横纵坐标， arr是一个与矩阵相同规格的二维数组，用来标记格子是否已进入
	bool fun(vector<vector<int> >& arr, char* ma, int i, int j, char* s, int k, int row, int col)
	{
		bool istrue = false;
		bool isall = false;
		//字符串到‘\0’说明匹配上了，则返回true
		if (*(s + k) == '\0') {
			return true;
		}
		if (i >= 0 && i < row && j >= 0 && j < col && arr[i][j] == 0 && ma[col * i + j] == *(s + k)) {
			arr[i][j] = 1; //进入该格子，标记为1，此后不能进入
			++k;
			istrue = true;
			 isall = fun(arr, ma, i - 1, j, s, k, row, col)
				|| fun(arr, ma, i + 1, j, s, k, row, col)
				|| fun(arr, ma, i, j - 1, s, k, row, col)
				|| fun(arr, ma, i, j + 1, s, k, row, col);
		}
		if (istrue == true) { //退出该格子，恢复成0，表示后面可以进入
			arr[i][j] = 0;
		}
		return  isall;
	}
};

int main()
{
	char* str = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	char* str1 = "SGGFIECVAASABCEHJIGQEM";
	Solution s;
	bool l = s.hasPath(str, 5, 8, str1);
	return 0;
}