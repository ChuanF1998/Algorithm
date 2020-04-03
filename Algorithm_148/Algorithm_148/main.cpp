

#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	int GetInterest(vector<vector<int> >& arr, int k)
	{
		if (arr.size() == 0) {
			return 0;
		}
		int valOf01 = 0;    //K个数的总和
		int valOf1 = 0;     //k个中清醒的数的总和
		int valOf0 = 0;      //k个中睡觉的总和
		int max_val = -1;    //保存睡觉值大的
		int standard = 0;  //清醒的总大小
		int single = k - 1;
		size_t i = 0;
		size_t size = arr[0].size();
		while (i < size) {
			//第一次先直接判断前 K-1 个数,并且只执行一次
			while (i < size && single > 0) {
				if (arr[1][i] == 1) {
					standard += arr[0][i];
					valOf1 += arr[0][i];
				}
				valOf01 += arr[0][i];
				i++;
				single--;
			}
			//一次加一个数，变成K个
			valOf01 += arr[0][i];
			if (arr[1][i] == 1) {
				standard += arr[0][i];
				valOf1 += arr[0][i];
			}
			//k个数中睡觉的值
			valOf0 = valOf01 - valOf1;
			//保存睡觉值大的
			if (valOf0 > max_val) {
				max_val = valOf0;
			}
			//还原到k - 1个数，以便下次遍历
			valOf01 -= arr[0][i - k + 1];
			if (arr[1][i - k + 1] == 1) {
				valOf1 -= arr[0][i - k + 1];
			}
			//下标加1
			i++;
		}
		return standard + max_val;
	}
};
int main()
{
	solution s;
	int n;
	int k;
	while (cin >> n >> k) {
		vector<vector<int> > arr(2, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			cin >> arr[0][i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> arr[1][i];
		}
		cout << s.GetInterest(arr, k) << endl;
	}
	return 0;
}