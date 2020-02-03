/*
��Ŀ����
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�
�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/

#include <vector>
#include <iostream>

#if 0
class Solution {
public:
	void reOrderArray(std::vector<int> &array) {
		std::vector<int> arr;
		for (int i = 0; i < (int)array.size(); ++i) {
			if (array[i] % 2 == 1) {
				arr.push_back(array[i]);
			}
		}
		for (int i = 0; i < (int)array.size(); ++i) {
			if (array[i] % 2 == 0) {
				arr.push_back(array[i]);
			}
		}
		array = arr;
	}
};
#endif

//�������¿ռ䣬ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(1)
class Solution {
public:
	void reOrderArray(std::vector<int> &array) {
		int odd_count = 0;
		//���������ĸ����Ա����ҳ���һ��ż�����±�
		for (int i = 0; i < (int)array.size(); ++i) {
			if (array[i] % 2 == 1) {
				odd_count++;
			}
		}
		int odd_pos = 0; //�������±�
		int pos = 0;      //�����±�
		int even_pos = odd_count; //ż�����±�
		int temp;
		/*
		����˼·����Ĭ�Ͻ������Ϊ��ż�����֣���������ʼλ�ÿ�ʼ������ֻҪ����ż����������
		��������������һ���жϣ������±����������Ϊ����ʱ����˵����������ȷ��λ���ϣ�
		                        �����±����������Ϊż��ʱ���򽻻��������������£�
								��ʱ�������浱ǰ�����±��������ֵ����ǰ�����±��������ֵ���ɵ�ǰ�����±��
								��ֵ��Ҳ�������ڱ�����������������ǰ�����±�������ɵ�ǰż���±������������
								Ȼ��ǰż���±����������ʱ������Ҳ���������ĵ�һ��ż�����������Ա�֤��ż��������
								��ɺ�ż���±��1����ǰ�����±����Ϊż��ʱ�������±�ż�1
		��[1,2,3,4,5,6,7],4��������3��ż������ô������ĵ�һ��ż���±��Ϊ4���������±�oddΪ0��ż��even�±�Ϊ4
		                 pos��0��ʼ������pos = 0��arr[pos] = 1,arr[odd] = 1,����ȷλ�ã�odd��1��pos��1 
						                 pos = 1��arr[pos] = 2,ż����pos��1
										 pos = 2��arr[pos] = 3,arr[odd] = arr[1] = 2,�򽻻�������������� [1,3,5,4,2,6,7],
								��Ϊ��ʱarr[2] = 5,pos���䣬odd = 2,even = 5;
										 pos = 2, arr[pos] = 5��arr[odd] = 5,��ȷ, pos��1��odd��1 = 3
										 pos = 3��arr[pos] = 4, arr[odd] = 4��pos��1��
										 pos = 4��pos��1
									  	 ������
										 ֱ��pos = 6��arr[pos] = 7, arr[odd] = 4��arr[even] = 6,�����������[1,3,5,7,2,4,6]
		*/
		while (pos < (int)array.size()) {
			if (array[pos] % 2 == 1) {   //��ǰ�±����Ϊ����ʱ
				if (array[odd_pos] % 2 == 0) { //����ʱ�������±�Ϊż��ʱ���򽻻�
					temp = array[odd_pos];
					array[odd_pos] = array[pos];
					array[pos] = array[even_pos];
					array[even_pos] = temp;
					odd_pos++;
					even_pos++;
					if (array[pos] % 2 == 0) {
						pos++;
					}
				}
				else {    //�����±����������Ϊ�����������������ȷ��λ���ϣ������±��1
					pos++;
					odd_pos++;
				}
			}
			else {  //��ǰ�±����Ϊż��ʱ
				pos++;
			}
		}
	}
};

int main()
{
	Solution s;
	std::vector <int> arr{ 1,2 ,3 ,4,5,6,7};
	s.reOrderArray(arr);
	return 0;
}