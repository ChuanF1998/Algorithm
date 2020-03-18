/*
有股神吗？

有，小赛就是！

经过严密的计算，小赛买了一支股票，他知道从他买股票的那天开始，股票会有以下变化：
第一天不变，以后涨一天，跌一天，涨两天，跌一天，涨三天，跌一天...依此类推。

为方便计算，假设每次涨和跌皆为1，股票初始单价也为1，请计算买股票的第n天每股股票值多少钱？
*/

#include <iostream>
using namespace std;

int Getmoney(int n)
{
	int start = 1;
	if (n == 1) {
		return start;
	}
	int day = 1;
	int tempDay = day;
	for (int i = 1; i < n; ++i) {
		tempDay--;
		if (tempDay >= 0) {
			start++;
		}
		if (tempDay < 0) {
			day++;
			start--;
			tempDay = day;
		}
	}
	return start;
}

int main()
{
	int n;
	while (cin >> n) {
		cout << Getmoney(n) << endl;
	}
	return 0;
}

