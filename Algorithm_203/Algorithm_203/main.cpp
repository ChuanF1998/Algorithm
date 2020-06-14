

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mm
{
	char kind;
	int size;
	int num;
	int price;
};

int main()
{
	int n;
	vector<mm> arr{ { 'A', 1, 2, 2 }, { 'B', 1, 3, 2 }, { 'C', 1, 1, 3 }, { 'D', 1, 5, 1 }, { 'E', 1, 4, 5 }, { 'F', 1, 3, 2 } };
	while (cin >> n) {
		vector<vector<int> > result(7, vector<int>(n + 1, 0));
		for (int i = 1; i <= 6; ++i) {
			for (int j = 1; j <= n; ++j) {
				result[i][j] = max(result[i - 1][j], result[i][j - 1]);
				if (j >= arr[i - 1].price) {
					result[i][j] = max(result[i][j], result[i - 1][j - arr[i - 1].price] + arr[i - 1].num);
				}
			}
		}
		cout << result[6][n] << endl;
	}
	return 0;
}