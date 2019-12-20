
#include <vector>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		vector<vector<int> >arr(rows, vector<int>(cols, 0));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (fun(arr, matrix, i, j, str, 0,rows, cols)) {
					return true;
				}
			}
		}
		return false;
	}
	bool fun(vector<vector<int> >& arr, char* ma, int i, int j, char* s, int k, int row, int col)
	{
		bool istrue = false;
		bool isall = false;
		if (*(s + k) == '\0') {
			return true;
		}
		if (i >= 0 && i < row && j >= 0 && j < col && arr[i][j] == 0 && ma[col * i + j] == *(s + k)) {
			arr[i][j] = 1;
			++k;
			istrue = true;
			 isall = fun(arr, ma, i - 1, j, s, k, row, col)
				|| fun(arr, ma, i + 1, j, s, k, row, col)
				|| fun(arr, ma, i, j - 1, s, k, row, col)
				|| fun(arr, ma, i, j + 1, s, k, row, col);
		}
		if (istrue == true) {
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