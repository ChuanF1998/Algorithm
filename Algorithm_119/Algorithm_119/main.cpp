/*
��Ŀ����
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/

//�ַ����ȽϺ�������д��ע�ⷽ����ʹ��static����

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