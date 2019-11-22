/*
��Ŀ����
������������ڣ���������һ��ĵڼ��졣��

��ϸ������

����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��

�ӿ���Ƽ�˵����

Description   : ����ת��
Input Param   : year �������
Month �����·�
Day ������

Output Param  :
Return Value  : �ɹ�����0��ʧ�ܷ���-1���磺���ݴ���



Description   :
Input Param   :

Output Param  :
Return Value  : �ɹ�:����outDay��������ĵڼ���;
ʧ��:����-1


��������:
�������У��ֱ����꣬�£���

������� :
�ɹ� : ����outDay��������ĵڼ���;
ʧ��:���� - 1

	ʾ��1
	����
	2012
	12
	31

	���
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