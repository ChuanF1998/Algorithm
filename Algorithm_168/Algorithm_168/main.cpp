

// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	string command;
	while (cin >> n) {
		vector<string> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		for (int i = 1; i < n; ++i) {
			//注意 /a 和 /b/a 这种情况不满足，需要给前一个字符串加上 '/'才能保证前一个是根目录
			if (arr[i].find(arr[i - 1] + '/') != string::npos) {
				continue;
			}
			else {
				cout << "mkdir -p " << arr[i - 1] << endl;
			}
		}
		cout << "mkdir -p " << arr[n - 1] << endl;
		cout << endl;
	}
	return 0;
}