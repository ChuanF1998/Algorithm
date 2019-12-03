/*
��Ŀ����
Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��
ת������һ����������ٱ༭������������ɵı༭����������һ��
�ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ����༭�����
�㷨�������ɶ����ѧ��Levenshtein����ģ����ֽ�Levenshtein Distance��

Ex��

�ַ���A:abcdefg

�ַ���B: abcdef

ͨ�����ӻ���ɾ���ַ���g���ķ�ʽ�ﵽĿ�ġ������ַ�������Ҫ
һ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��롣

Ҫ��

�������������ַ�����д��һ���㷨�������ǵı༭���롣

��������:
���������ַ���

������� :
�õ�������

ʾ��1
����
abcdefg
abcdef

���
1

*/

/*
������Ҫ�ö�̬�滮���� ״̬�� ��״̬��word1��ǰ1��2��3��...m���ַ�ת����word2��ǰ1��2��3��...n
���ַ���Ҫ�ı༭����
F(i,j):word1��ǰi���ַ���word2��ǰj���ַ��ı༭���� ״̬���ƣ� F(i,j) = min { F(i-1,j��+1, F(i,j-1) +1, F(i-
1,j-1) +(w1[i]==w2[j]?0:1) } ��ʽ��ʾ��ɾ�������Ӻ��滻������ѡ��һ����С������ F(i-1,j): w1[1,...,i-1]��
w2[1,...,j]�ı༭���룬ɾ��w1[i]���ַ�--->F(i,j) F(i,j-1): w1[1,...,i]��w2[1,...,j-1]�ı༭���룬����һ���ַ�---
>F(i,j) F(i-1,j-1): w1[1,...,i-1]��w2[1,...,j-1]�ı༭���룬���w1[i]��w2[j]��ͬ�� �����κβ������༭���벻
�䣬���w1[i]��w2[j]��ͬ���滻w1[i]���ַ�Ϊw2[j]--->F(i,j) ��ʼ���� ��ʼ��һ��Ҫ��ȷ����ֵ���������
������մ�����ʼֵ�޷�ȷ�� F(i,0) = i :word��մ��ı༭���룬ɾ������ F(0,i) = i :�մ���word�ı༭��
�룬���Ӳ��� ���ؽ����F(m,n)


*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int get_editor(string& str1, string& str2)
	{
		if (str1.empty() || str2.empty()) {
			return max(str1.size(), str2.size());
		}
		int str1_length = str1.size();
		int str2_length = str2.size();
		vector< vector<int> > arr(str1_length + 1, vector<int>(str2_length + 1, 0));
		for (int i = 0; i <= str1_length; ++i) {
			arr[i][0] = i;
		}
		for (int i = 0; i <= str2_length; ++i) {
			arr[0][i] = i;
		}
		for (int i = 1; i <= str1_length; ++i) {
			for (int j = 1; j <= str2_length; ++j) {
				if (str1[i - 1] == str2[i - 1]) {
					arr[i][j] = 1 + min(arr[i][j - 1], arr[i - 1][j]);
					arr[i][j] = min(arr[i][j], arr[i - 1][j - 1]);
				}
				else {
					arr[i][j] = 1 + min(arr[i][j - 1], arr[i - 1][j]);
					arr[i][j] = min(arr[i][j], 1 + arr[i - 1][j - 1]);
				}
			}
		}
		return arr[str1_length][str2_length];
	}
};


int main()
{
	Solution s;
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << s.get_editor(str1, str2) << endl;
	}
	return 0;
}