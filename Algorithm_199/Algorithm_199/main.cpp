/*
题目：线段树编号问题
题目描述
给定一段线段树构造代码，按如下方式构造线段树。
定义变量ans，初始ans=0
定义函数build(x,y,z)，意义如下
/////////////////////////
start build
赋值 ans=x
判断 若(y=z) 则 end build
定义变量mid
赋值 mid=(y+z)/2 {此处除法为下取整}
运行 build(x*2,y,mid)
运行 build(x*2+1,mid+1,z)
end build
/////////////////////////
你的任务是，对于T组询问，每个询问给出n，求对于每个n，运行build(1,1,n)后，输出ans。
对于每个n，询问相互独立，即ans在上一个询问结束后归零。
输入时T单独给出，每个n会存储在数组a中给出。

示例1
输入
复制
2,[4,5]
输出
复制
[7,9]
说明
当n=4时，构造出的线段树的区间编号及其对应的区间为
1[1,4],2[1,2],3[3,4],4[1,1],5[2,2],6[3,3],7[4,4]
当n=5时，构造出的线段树的区间编号及其对应的区间为
1[1,5],2[1,3],3[4,5],4[1,2],5[3,3],6[4,4],7[5,5],8[1,1],9[2,2]
其中[]外的是编号，[]内表示区间的起始位置和终末位置。
可知，当n=4时编号最大为7，当n=5时编号最大为9
备注:
T<=100000
0<n<=10^8
*/
#include <vector>
using namespace std;

class Solution {
public:
	/**
	*
	* @param T int整型
	* @param a int整型一维数组
	* @param aLen int a数组长度
	* @return int整型vector
	*/
	void build(int& max, int x, int y, int z)
	{
		if (y == z) {
			if (x > max) {
				max = x;
			}
			return;
		}
		int mid = (y + z) >> 1;
		build(max, x * 2, y, mid);
		build(max, x * 2 + 1, mid + 1, z);
		return;
	}
	vector<int> wwork(int T, int* a, int aLen) {
		// write code here
		vector<int> result;
		int max = 0;
		for (int i = 0; i < aLen; ++i) {
			max = 0;
			build(max, 1, 1, a[i]);
			result.push_back(max);
		}
		return result;
	}
};


class Solution1 {
public:
	/**
	*
	* @param T int整型
	* @param a int整型一维数组
	* @param aLen int a数组长度
	* @return int整型vector
	*/
	vector<int> wwork(int T, int* a, int aLen) {
		// write code here
		vector<int> result;
		for (int i = 0; i < aLen; ++i) {
			int n = a[i];
			int rt = 1;
			while (n != 1) {
				int l = n >> 1;
				int r = n - l;
				if ((l & (-l)) == l && r > l) {
					n = r;
					rt = rt * 2;
				}
				else {
					n = l;
					rt = rt * 2 + 1;
				}

			}
			result.push_back(rt);
		}
		return result;
	}
};


int main()
{
	//int k = (2 & (-2) == 2);
	int l = (2 & (-2)) == 2;
	return 0;
}