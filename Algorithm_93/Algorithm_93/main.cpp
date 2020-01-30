/*
��Ŀ����
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ���������
�ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
*/

/*
˼·��
������'.'ʱstr��pattern�Ͷ�����ƶ�һ�񣬵���".*"��������ƥ��
��pattern + 1����'*'ʱ����pattern��str�����Ҫô
str + 1,pattern + 2 ---�� *����1��
str + 1, pattern���� ---��*������
str���䣬pattern + 2 ---��*����0��

������str���䣬pattern + 2                                          
��pattern + 1����'*'�ţ���pattern��str�����������һ�񣻲�����򷵻�false

*/

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr) {
			return false;
		}
		return is_matching(str, pattern);
	}

	bool is_matching(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0') {
			return true;
		}
		if (*str != '\0' && *pattern == '\0') {
			return false;
		}
		if (*(pattern + 1) == '*') {
			if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
				return is_matching(str + 1, pattern + 2)
					|| is_matching(str + 1, pattern)
					|| is_matching(str, pattern + 2);
			}
			else {
				return is_matching(str, pattern + 2);
			}
		}
		if (*(pattern + 1) != '*') {
			if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
				return is_matching(str + 1, pattern + 1);
			}
			else {
				return false;
			}
		}
		return false;
	}
};




int main()
{
	Solution s;
	char* a = "aaa";
	char* b = "aa*";
	bool m = s.match(a, b);
	return 0;
}