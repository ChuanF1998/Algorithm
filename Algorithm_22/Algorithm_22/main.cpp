/*
题目描述
请设计一个算法完成两个超长正整数的加法。


输入描述:
输入两个字符串数字

输出描述 :
输出相加后的结果，string型

示例1
输入
99999999999999999999999999999999999999999999999999
1

输出
100000000000000000000000000000000000000000000000000
*/

//思路：设置一个进位cy=‘0’，当两数同位相加再加进位位的和大于‘9’，进位cy=‘1’
//做循环，先将比较短的那个数加完，然后再用进位cy与比较长的那个数剩下未加的位数相加，知道遍历到第一位
//若此时cy还为‘1’，则头插进去 （如 9999 和 1  -》10000）

#include <iostream>
#include <string>
using namespace std;

class string_add
{
public:
	string add(string str1, string str2)
	{
		char cy = '0';
		size_t length1 = str1.size();
		size_t length2 = str2.size();
		if (length1>length2){    //判断长短，因为需要用长的那个数保存结果
			while (length2>0) {
				str1[length1 - 1] += str2[length2 - 1] - '0' + cy - '0'; //相加
				cy = '0';                       //cy位置‘0’
				if (str1[length1 - 1]>'9'){     //相加的结果有进位
					cy = '1';                   //cy位置‘1’
					str1[length1 - 1] -= 10;    //减去进位
				}
				length2--;
				length1--;
			}
			for (int i = length1 - 1; i >= 0; --i){
				str1[i] += cy - '0';
				cy = '0';
				if (str1[i]>'9'){
					cy = '1';
					str1[i] -= 10;
				}
			}
			if (cy == '1'){
				str1.insert(str1.begin(), '1');
				return str1;
			}
			else {
				return str1;
			}
		}
		else {
			while (length1>0) {
				str2[length2 - 1] += str1[length1 - 1] - '0' + cy - '0';
				cy = '0';
				if (str2[length2 - 1]>'9'){
					cy = '1';
					str2[length2 - 1] -= 10;
				}
				length2--;
				length1--;
			}
			for (int i = length2 - 1; i >= 0; --i){
				str2[i] += cy - '0';
				cy = '0';
				if (str2[i]>'9'){
					cy = '1';
					str2[i] -= 10;
				}
			}
			if (cy == '1'){
				str2.insert(str2.begin(), '1');
				return str2;
			}
			else {
				return str2;
			}
		}
	}
};


int main()
{
	string_add s;
	string str1, str2;
	while (cin >> str1 >> str2){
		cout << s.add(str1, str2) << endl;
	}
	return 0;
}