/*
��Ŀ����
��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��
ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.
*/

#include <string>
#include <vector>

class Solution {
public:
	int FirstNotRepeatingChar(std::string str) {
		if (str.size() == 0) {
			return -1;
		}
		std::vector<int> arr(255, 0);
		for (size_t i = 0; i < str.size(); ++i) {
			arr[str[i]]++;
		}
		for (size_t i = 0; i < str.size(); ++i) {
			if (arr[str[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	return 0;
}