/*
题目描述
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。
现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符


输入：
通配符表达式；
一组字符串。


输出：
返回匹配的结果，正确输出true，错误输出false

输入描述:
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述:
返回匹配的结果，正确输出true，错误输出false

示例1
输入
te?t*.*
txt12.xls

输出
false
*/

/*这个题是真的有点难想，首先说说非递归做法，我的思路大致是：通过 * 和 ？ 和 . 将通配字符串
分成一个个字串，？单独一个字串，遇到 * 号就输出一个字串（如示例1：分为三个 te  ? t ）
然后将这些字串按顺序（一定要按顺序）与普通字符串进行比较，先设置一个标置位flag=0，遇到？串，将flag处的字符设置为 *
（为什么设置为*号，因为*是通配的，不影响后续比较结果），普通字串也与普通字符串进行比较，若字串在普通字符串匹配上了，
则在普通字符串中将与字串相同的内容设置为 * ，flag设置为*的位置+1。若匹配不上，return false ；字串遍历完全，return true。

举一个例子好理解：通配 abc？qwe*rr*.*uu -> 字串 abc ？ qwe rr uu。普通字符串 abcrqwetttrr.uu
然后遍历，第一次：abc匹配上了 --》 ***rqwetttrr.uu ，flag位置为 r 这个位置
          第二次：？ ---》****qwetttrr.uu ,flag设置为 q 这个位置
		  第三次：qwe 匹配上了 --》*******tttrr.uu ,flag设置为 t 这个位置
		  .....
		  直到字串遍历完
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class str_matching
{
public:
	string str_ismatching(string str1, string str2)
	{
		vector<string> arr;
		auto str1_first = str1.begin();
		auto str1_last = str1.end();
		auto temp = str1_first;
		while (str1_first != str1_last) {
			if (*str1_first == '?' || *str1_first == '*' || *str1_first == '.') {
				if (*temp == '*' || *temp == '.'){
					temp++;
					str1_first++;
				}
				else if (*temp == '?') {
					string str(temp, str1_first + 1);
					arr.push_back(str);
					temp = str1_first + 1;
					str1_first++;
				}
				else{
					string str(temp, str1_first);
					arr.push_back(str);
					temp = str1_first + 1;
					str1_first++;
				}
			}
			else {
				str1_first++;
			}
		}
		if (str1_first>temp){
			string str3(temp, str1_first);
			arr.push_back(str3);
		}
		size_t str2_length = str2.size();
		size_t k = 0;
		for (size_t i = 0; i<arr.size(); ++i){
			if (arr[i] == "?"){
				str2.replace(k, 1, 1, '*');
			}
			else {
				size_t pos = str2.find(arr[i]);
				if (pos == string::npos) {
					return "false";
				}
				else {
					str2.replace(pos, arr[i].size(), arr[i].size(), '*');
					k = pos + arr[i].size() + 1;
				}
			}
		}
		return "true";
	}
};


int main()
{
	str_matching s;
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << s.str_ismatching(str1, str2) << endl;
	}
	return 0;
}



#if 0

//递归做法,这个真想不出来
#include <iostream>
#include <string>
using namespace std;
bool match(const char* pattern, const char *str)
{
	//当前字符结束，返回true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//两个字符串有一个先结束，则返回false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//遇到?号，匹配一个字符，跳过一个位置
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//如果当前字符相等，匹配下一个字符
		return match(pattern + 1, str + 1);
	}
	return false;
}
int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	cout << "false" << endl;
	return 0;
}

#endif