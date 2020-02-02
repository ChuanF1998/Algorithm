


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
			scanUnsignedInt(string);
			isNumeric = isNumeric || scanUnsignedInt(string);
		}
		if (*string == 'e' || *string == 'E') {
			string++;
			isNumeric = isNumeric && scanUnsignedInt(string);
		}
		return isNumeric && *string == '\0';
	}

	bool scanUnsignedInt(char*& str)
	{
		if (*str == '-' || *str == '+') {
			str++;
		}
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