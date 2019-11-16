/*
��Ŀ����
���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�

һ�����볤��:

5 ��: С�ڵ���4 ���ַ�

10 ��: 5 ��7 �ַ�

25 ��: ���ڵ���8 ���ַ�

������ĸ:

0 ��: û����ĸ

10 ��: ȫ����С����д��ĸ

20 ��: ��Сд�����ĸ

��������:

0 ��: û������

10 ��: 1 ������

20 ��: ����1 ������

�ġ�����:

0 ��: û�з���

10 ��: 1 ������

25 ��: ����1 ������

�塢����:

2 ��: ��ĸ������

3 ��: ��ĸ�����ֺͷ���

5 ��: ��Сд��ĸ�����ֺͷ���

�������ֱ�׼:

>= 90: �ǳ���ȫ

>= 80: ��ȫ��Secure��

>= 70: �ǳ�ǿ

>= 60: ǿ��Strong��

>= 50: һ�㣨Average��

>= 25: ����Weak��

>= 0:  �ǳ���



��Ӧ���Ϊ��

VERY_WEAK,

WEAK,

AVERAGE,

STRONG,

VERY_STRONG,

SECURE,

VERY_SECURE



���������������ַ��������а�ȫ������

ע��

��ĸ��a-z, A-Z

���֣�-9

���Ű������£� (ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴)

!"#$%&'()*+,-./     (ASCII�룺x21~0x2F)

:;<=>?@             (ASCII<=><=><=><=><=>�룺x3A~0x40)

[\]^_`              (ASCII�룺x5B~0x60)

{|}~                (ASCII�룺x7B~0x7E)

��������:
����һ��string������

�������:
�������ȼ�

ʾ��1
����
38$@NoNoNo

���
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
		//��ȡ����
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
		//���ֵ÷�
		if (Get_num(password) == 0){
			score += 0;
		}
		else if (Get_num(password)>1) {
			score += 20;
		}
		else {
			score += 10;
		}
		//�ַ��÷�
		if (Get_symbol(password) == 0) {
			score += 0;
		}
		else if (Get_symbol(password) > 1) {
			score += 25;
		}
		else {
			score += 10;
		}
		//��ĸ�÷�
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
		//����
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
		//���
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
	//������ָ���
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
	//����ַ�����
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
	//�����д��ĸ����
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
	//���Сд��ĸ����
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
