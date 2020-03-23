/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使
得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> arr;
		multimap<int, int> m;
		for (size_t i = 0; i < array.size(); ++i) {
			m.insert(pair<int, int>(array[i], i));
		}
		for (size_t i = 0; i < array.size(); ++i) {
			int other = sum - array[i];
			auto it = m.find(other);
			if (it != std::end(m)) {
				if ((int)it->second == i) {
					if ((int)m.count(other) > 1) {
						arr.push_back(array[i]);
						arr.push_back(other);
						return arr;
					}
				}
				else {
					arr.push_back(array[i]);
					arr.push_back(other);
					return arr;
				}
			}
		}
		return arr;
	}
};

class Solution1 {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> arr;
		if (array.size() == 0) {
			return arr;
		}
		int begin = 0;
		int end = (int)array.size() - 1;
		while (begin < end) {
			if (array[begin] + array[end] == sum) {
				arr.push_back(array[begin]);
				arr.push_back(array[end]);
				break;
			}
			else if (array[begin] + array[end] > sum) {
				end--;
			}
			else {
				begin++;
			}
		}
		return arr;
	}
};

int main()
{
	return 0;
}