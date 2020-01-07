/*
��Ŀ����
ţţȥ�Ġ���ʦ�Ҳ��Σ����ŵ�ʱ�����򱱷���������������·�ˡ���Ȼ��������һ�ŵ�ͼ��
��������Ҫ֪���Լ������ĸ���������������
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а���һ������������ʾת����Ĵ���N(N<=1000)��
��������һ�а���һ������ΪN���ַ�������L��R��ɣ�L��ʾ����ת��R��ʾ����ת��
�������:
���ţţ�������ķ���N��ʾ����S��ʾ�ϣ�E��ʾ����W��ʾ����
ʾ��1
����
3
LRR

���
E
*/

/*
˼·�����ÿһ�ζ�תһ����������Ҫ4�β����뿪ʼ����һ�£����Կ��Խ�����򻯣�
��ת����ת�Ĵ���ģ4�õ�һ������������Ϳ�������ת������ͬ��ֵʱ�ķ���
*/

#include <iostream>
#include <string>

class Solution
{
public:
	char direction_of(std::string& str)
	{
		int L_count = 0;
		int R_count = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == 'L') {
				++L_count;
			}
			if (str[i] == 'R') {
				++R_count;
			}
		}
		int L_remain = L_count % 4;
		int R_remain = R_count % 4;
		if (L_remain == R_remain) {
			return 'N';
		}
		else if (L_remain - R_remain == 1 || R_remain - L_remain == 3) {
			return 'W';
		}
		else if (R_remain - L_remain == 1 || L_remain - R_remain == 3) {
			return 'E';
		}
		else {
			return 'S';
		}
	};
};

int main()
{
	Solution s;
	int n;
	std::string str;
	while (std::cin >> n) {
		str.resize(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> str[i];
		}
		std::cout << s.direction_of(str) << std::endl;
		str.clear();
	}
	return 0;
}