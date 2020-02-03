/*
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/


/*
数字串： .123 表示 0.123；12. 表示12；12.123表示12.123，意思是小数点前后只有有一边有数字都可以
次方e或E: e前面必须要数字（小数和整数都可），e后面必须是整数，不能是小数。
在遍历的时候，字符串要分为带符号和不带符号
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

	//带符号
	bool scanUnsignedInt(char*& str)
	{
		if (*str == '-' || *str == '+') {
			str++;
		}
		return scanInt(str);
	}

	//不带符号
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