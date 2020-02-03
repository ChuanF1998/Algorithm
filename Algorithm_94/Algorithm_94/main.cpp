/*
��Ŀ����
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� 
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
*/


/*
���ִ��� .123 ��ʾ 0.123��12. ��ʾ12��12.123��ʾ12.123����˼��С����ǰ��ֻ����һ�������ֶ�����
�η�e��E: eǰ�����Ҫ���֣�С�����������ɣ���e���������������������С����
�ڱ�����ʱ���ַ���Ҫ��Ϊ�����źͲ�������
*/

class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string == nullptr && *string == '\0') {
			return false;
		}
		bool isNumeric = scanUnsignedInt(string);
		if (*string == '.') {
			string++;
			isNumeric = scanInt(string) || isNumeric;
		}
		if (*string == 'e' || *string == 'E') {
			string++;
			isNumeric = isNumeric && scanUnsignedInt(string);
		}
		return isNumeric && *string == '\0';
	}

	//������
	bool scanUnsignedInt(char*& str)
	{
		if (*str == '-' || *str == '+') {
			str++;
		}
		return scanInt(str);
	}

	//��������
	bool scanInt(char*& str)
	{
		char* prev = str;
		while (*str != '\0' && *str >= '0' && *str <= '9') {
			str++;
		}
		return str > prev;
	}
};


int main()
{
	Solution s;
	char* str = "123.45e+6";
	bool h = s.isNumeric(str);
	return 0;
}