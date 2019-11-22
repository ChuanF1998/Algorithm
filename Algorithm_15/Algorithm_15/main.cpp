/*
题目描述
根据输入的日期，计算是这一年的第几天。。

详细描述：

输入某年某月某日，判断这一天是这一年的第几天？。

接口设计及说明：

Description   : 数据转换
Input Param   : year 输入年份
Month 输入月份
Day 输入天

Output Param  :
Return Value  : 成功返回0，失败返回-1（如：数据错误）



Description   :
Input Param   :

Output Param  :
Return Value  : 成功:返回outDay输出计算后的第几天;
失败:返回-1


输入描述:
输入三行，分别是年，月，日

输出描述 :
成功 : 返回outDay输出计算后的第几天;
失败:返回 - 1

	示例1
	输入
	2012
	12
	31

	输出
	366
*/


#include <iostream>
using namespace std;

class what_day
{
public:
	int Get_a_year_ofday(int year, int month, int day)
	{
		if (year<0) {
			return -1;
		}
		if (month>12 || month <= 0) {
			return -1;
		}
		int mon_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (is_leap_year(year)) {
			mon_days[2] = 29;
		}
		if (mon_days[month]<day){
			return -1;
		}
		int value = 0;
		for (int i = 1; i<month; ++i) {
			value += mon_days[i];
		}
		return value + day;
	}

	bool is_leap_year(int year)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			return true;
		}
		if (year % 400 == 0) {
			return true;
		}
		return false;
	}
};




int main()
{
	what_day w;
	int year;
	int month;
	int day;
	while (cin >> year >> month >> day) {
		cout << w.Get_a_year_ofday(year, month, day) << endl;
	}
	return 0;
}