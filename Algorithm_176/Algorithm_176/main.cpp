
/*
��Ŀ��ţ�õ�����
��Ŀ����
������֪��ţ����һ��offer�ո�����������������������һ�����⡣
����һ�����У����ҳ���ġ�͹�����С�
��Ϊ��͹�����С�����������һ��xi,ʹ������x0<x1<x2��.xi-1<xi��xi>xi+1>xi+1>��.>xn
eg��12345431,��ɽ�����У�12345234����ɽ������
ע�����������򵥵��ݼ�����Ҳ��ɽ�����У�����һ�����ǳ���Ϊ1��ɽ������

ʾ��1
����
����
[1,2,3,6,1]
���
����
5
ʾ��2
����
[1,2,2,1]
���
3
˵��
1,2,1
��ע:
��������������������0 �Ҳ�����10000�������г��Ȳ�����1000
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* �������ɽ�����г���
	* @param numberList int����vector ����������
	* @return int����
	*/
	int mountainSequence(vector<int>& numberList) {
		// write code here
		int size = (int)numberList.size();
		vector<int> arr1(size, 1);
		vector<int> arr2(size, 1);
		int ma = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < i; ++j) {
				if (numberList[i] > numberList[j]) {
					arr1[i] = max(arr1[i], arr1[j] + 1);
				}
				if (numberList[size - i - 1] > numberList[size - j - 1]) {
					arr2[size - i - 1] = max(arr2[size - 1 - i], arr2[size - j - 1] + 1);
				}
			}
		}
		for (int i = 0; i < size; ++i) {
			ma = max(ma, arr1[i] + arr2[i] - 1);
		}
		return ma;
	}
};

int main()
{
	return 0;
}