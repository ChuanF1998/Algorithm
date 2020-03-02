/*
��Ŀ����
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
��������:
����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��
*/

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
	std::vector<std::string> Permutation(std::string str) {
		sort(str.begin(), str.end());
		int length = str.size();
		std::vector<std::string> arr;
		if (length == 1)  {
			arr.push_back(str);
			return arr;
		}
		func(arr, str, length, 0);
		std::sort(arr.begin(), arr.end());
		return arr;
	}
	void func(std::vector<std::string>& arr, std::string& str, int length, int prev)
	{
		if (prev == length && length != 0) {
			arr.push_back(str);
			return;
		}
		for (int i = prev; i < length; ++i) {
			if (i != prev && str[i] == str[prev]) {
				continue;
			}
			std::swap(str[prev], str[i]);
			func(arr, str, length, prev + 1);
			std::swap(str[prev], str[i]);
		}
	}

};

int main()
{
	return 0;
}