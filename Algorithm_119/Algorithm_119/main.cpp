/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

//字符串比较函数的书写，注意方法和使用static修饰

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string> arr;
		for (size_t i = 0; i < numbers.size(); ++i) {
			arr.push_back(to_string(numbers[i]));
		}
		sort(arr.begin(), arr.end(), compare);
		string num;
		for (size_t i = 0; i < arr.size(); ++i) {
			num.append(arr[i]);
		}
		return num;
	}
	static bool compare(const string& str1, const string& str2)
	{
		string str12 = str1 + str2;
		string str21 = str2 + str1;
		return str12 < str21;
	}
};


int main()
{
	return 0;
}