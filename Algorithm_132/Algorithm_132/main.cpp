/*
��Ŀ����
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,
�ٺ٣���������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,��
����\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5
��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������
�Ĺ���,Ȼ���������LL��������Σ� ����������˳�Ӿ����true����������false��Ϊ�˷������
,�������Ϊ��С����0��
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() == 0) {
			return false;
		}
		bool isContinuous = true;
		sort(numbers.begin(), numbers.end());
		int numOf0 = 0;
		size_t i = 0;
		for (; i < numbers.size(); ++i) {
			if (numbers[i] == 0) {
				numOf0++;
			}
			else {
				break;
			}
		}
		int numOfSpace = 0;
		for (size_t j = i + 1; j < numbers.size(); ++j) {
			if (numbers[j] == numbers[j - 1]) {
				isContinuous = false;
				break;
			}
			numOfSpace += numbers[j] - numbers[j - 1] - 1;
		}
		if (isContinuous == false) {


			return false;
		}
		return (numOf0 >= numOfSpace);
	}
};

int main()
{
	return 0;
}