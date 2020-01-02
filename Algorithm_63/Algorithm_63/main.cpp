/*
��Ŀ����
СQ���ڸ�һ������Ϊn�ĵ�·���·�ư��÷�����

Ϊ�����������,СQ�ѵ�·��Ϊn������,��Ҫ�����ĵط���'.'��ʾ, ����Ҫ�������ϰ��������'X'��ʾ��

СQ����Ҫ�ڵ�·������һЩ·��, ���ڰ�����posλ�õ�·��, ��յ·�ƿ�������pos - 1, pos, pos + 1������λ�á�

СQϣ���ܰ��þ����ٵ�·����������'.'����, ϣ�����ܰ�������һ��������Ҫ����յ·�ơ�

��������:
����ĵ�һ�а���һ��������t(1 <= t <= 1000), ��ʾ����������
������ÿ����һ����������, ��һ��һ��������n(1 <= n <= 1000),��ʾ��·�ĳ��ȡ�
�ڶ���һ���ַ���s��ʾ��·�Ĺ���,ֻ����'.'��'X'��
�������:
����ÿ����������, ���һ����������ʾ������Ҫ����յ·�ơ�
ʾ��1
����
2
3
.X.
11
...XX....XX

���
1
3
*/


/*
˼·��ֻҪ���������ǡ�.����������ͰѺ�����Ҳͬʱ��Ϊ��.����
���ӣ�Ҳ���Բ���������������һ����.�����ٴ�ֱ���������������.��
*/

#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
	int street_lamp_count(std::string& street)
	{
		int count = 0;
		size_t street_length = street.size();
		for (size_t i = 0; i < street_length - 1; ++i) {
			if (street[i] == '.') {
				street[i] = 'X';
				street[i + 1] = 'X';
				street[i + 2] = 'X';
				count++;
			}
		}
		if (street[street_length - 1] == '.') {
			count += 1;
		}
		return count;
	}
};

int main()
{
	int n;
	Solution s;
	std::vector<std::string> arr;
	while (std::cin >> n) {
		int length;
		std::string street;
		for (int i = 0; i < n; ++i) {
			std::cin >> length;
			std::cin >> street;
			arr.push_back(street);
		}
		for (int i = 0; i < n; ++i) {
			std::cout << s.street_lamp_count(arr[i]) << std::endl;
		}
		arr.clear();
	}
	return 0;
}