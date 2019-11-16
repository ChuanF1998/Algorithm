/*
题目描述
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。

一、密码长度:

5 分: 小于等于4 个字符

10 分: 5 到7 字符

25 分: 大于等于8 个字符

二、字母:

0 分: 没有字母

10 分: 全都是小（大）写字母

20 分: 大小写混合字母

三、数字:

0 分: 没有数字

10 分: 1 个数字

20 分: 大于1 个数字

四、符号:

0 分: 没有符号

10 分: 1 个符号

25 分: 大于1 个符号

五、奖励:

2 分: 字母和数字

3 分: 字母、数字和符号

5 分: 大小写字母、数字和符号

最后的评分标准:

>= 90: 非常安全

>= 80: 安全（Secure）

>= 70: 非常强

>= 60: 强（Strong）

>= 50: 一般（Average）

>= 25: 弱（Weak）

>= 0:  非常弱



对应输出为：

VERY_WEAK,

WEAK,

AVERAGE,

STRONG,

VERY_STRONG,

SECURE,

VERY_SECURE



请根据输入的密码字符串，进行安全评定。

注：

字母：a-z, A-Z

数字：-9

符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)

!"#$%&'()*+,-./     (ASCII码：x21~0x2F)

:;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)

[\]^_`              (ASCII码：x5B~0x60)

{|}~                (ASCII码：x7B~0x7E)

输入描述:
输入一个string的密码

输出描述:
输出密码等级

示例1
输入
38$@NoNoNo

输出
VERY_SECURE
*/






#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Password_evel
{
public:
	string Get_password_evel(string str)
	{
		int score = 0;
		size_t str_length = str.size();
		//获取长度
		if (str_length <= 4){
			score += 5;
		}
		else if (str_length >= 5 && str_length <= 7) {
			score += 10;
		}
		else {
			score += 25;
		}
		vector<char> password(255, 0);
		size_t i = 0;
		for (i = 0; i<str_length; ++i) {
			password[str[i]]++;
		}
		//数字得分
		if (Get_num(password) == 0){
			score += 0;
		}
		else if (Get_num(password)>1) {
			score += 20;
		}
		else {
			score += 10;
		}
		//字符得分
		if (Get_symbol(password) == 0) {
			score += 0;
		}
		else if (Get_symbol(password) > 1) {
			score += 25;
		}
		else {
			score += 10;
		}
		//字母得分
		if (Get_apital(password) == 0 && Get_lowercase(password) == 0) {
			score += 0;
		}
		else if (Get_apital(password)>0 && Get_lowercase(password) == 0) {
			score += 10;
		}
		else if (Get_apital(password) == 0 && Get_lowercase(password)>0) {
			score += 10;
		}
		else {
			score += 25;
		}
		//奖励
		if (Get_apital(password)>0 && Get_lowercase(password)>0 && Get_num(password)>0 && Get_symbol(password)>0) {
			score += 6;
		}
		else if (Get_apital(password) == 0 && Get_lowercase(password)>0 && Get_num(password)>0 && Get_symbol(password)>0){
			score += 3;
		}
		else if (Get_apital(password)>0 && Get_lowercase(password) == 0 && Get_num(password)>0 && Get_symbol(password)>0){
			score += 3;
		}
		else if (Get_apital(password) == 0 && Get_lowercase(password) == 0 && Get_num(password)>0 && Get_symbol(password)>0){
			score += 2;
		}
		else {
			score += 0;
		}
		//输出
		if (score >= 90) {
			return "VERY_SECURE";
		}
		else if (score >= 80) {
			return "SECURE";
		}
		else if (score >= 70) {
			return "VERY_STRONG";
		}
		else if (score >= 60) {
			return "STRONG";
		}
		else if (score >= 50) {
			return "AVERAGE";
		}
		else if (score >= 25) {
			return "WEAK";
		}
		else {
			return "VERY_WEAK";
		}
	}
	//输出数字个数
	int Get_num(vector<char> arr)
	{
		int num = 0;
		for (int i = 48; i<58; ++i) {
			if (arr[i]>0){
				num += arr[i];
			}
		}
		return num;
	}
	//输出字符个数
	int Get_symbol(vector<char> arr)
	{
		int symbol = 0;
		int i = 33;
		for (i = 33; i<48; ++i){
			if (arr[i]>0){
				symbol += arr[i];
			}
		}
		for (i = 58; i<65; ++i){
			if (arr[i]>0) {
				symbol += arr[i];
			}
		}
		for (i = 91; i<97; ++i) {
			if (arr[i]>0){
				symbol += arr[i];
			}
		}
		for (i = 123; i<127; ++i){
			if (arr[i]>0){
				symbol += arr[i];
			}
		}
		return symbol;
	}
	//输出大写字母个数
	int Get_apital(vector<char> arr)
	{
		int capital = 0;
		for (int i = 65; i<91; ++i) {
			if (arr[i]>0) {
				capital += arr[i];
			}
		}
		return capital;
	}
	//输出小写字母个数
	int Get_lowercase(vector<char> arr)
	{
		int lowercase = 0;
		for (int i = 97; i<123; i++) {
			if (arr[i]>0){
				lowercase += arr[i];
			}
		}
		return lowercase;
	}
};

int main()
{
	Password_evel p;
	string s;
	while (cin >> s) {
		cout << p.Get_password_evel(s) << endl;
	}
	return 0;
}
