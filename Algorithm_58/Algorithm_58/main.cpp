/*
��Ŀ����
������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ���������
�����������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ���
�뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38����
��Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
*/

/*
���ݷ���
������ø������������������ø��ӣ�Ȼ�󽫸ø��ӱ��Ϊ1����ʾ�Ѿ��߹���
��Ȼ������жϸø��ӵ��������ң�����������ִ�й��̢�
���Ѿ��жϹ��ø��ӵ��������ң����˳��ø��ӣ�����֮ǰ�ĸ��ӣ�
���Ѿ��˵���һ�ν���ĸ���ʱ������ʾ�ҳ��������������ĸ��ӣ�������
*/

#include <vector>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<int> arr(rows * cols, 0);
		return can_move(threshold, rows, cols, 0, 0, arr);
	}

	int can_move(int threshold, int rows, int cols, int x, int y, vector<int>& arr)
	{
		int count = 0;
		if (x >= 0 && x < rows && y >= 0 && y < cols && arr[x * cols + y] == 0 && plus_count(x) + plus_count(y) <= threshold) {
			arr[x * cols + y] = 1;
			count = 1 + can_move(threshold, rows, cols, x - 1, y, arr)
				+ can_move(threshold, rows, cols, x + 1, y, arr)
				+ can_move(threshold, rows, cols, x, y - 1, arr)
				+ can_move(threshold, rows, cols, x, y + 1, arr);
		}
		return count;

	}

	int plus_count(int n)
	{
		int count = 0;
		int position = 0;
		while (n) {
			position = n % 10;
			count += position;
			n = (n - position) / 10;
		}
		return count;
	}
};

int main()
{
	return 0;
}