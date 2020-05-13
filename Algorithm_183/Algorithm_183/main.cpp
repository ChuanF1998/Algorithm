

/*
题目：查找兄弟单词
*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		vector<string> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		string str;
		int pos;
		cin >> str >> pos;
		string str_tmp = str;
		sort(str_tmp.begin(), str_tmp.end());
		string re;
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i].compare(str) == 0) {
				continue;
			}
			if (str.size() == arr[i].size()) {
				string tmp = arr[i];
				sort(tmp.begin(), tmp.end());
				if (tmp.compare(str_tmp) == 0) {
					count++;
					pos -= 1;
					if (pos == 0) {
						re = arr[i];
					}
				}
			}
		}
		cout << count << endl;
		if (re.size() != 0)
			cout << re << endl;
	}
	return 0;
}