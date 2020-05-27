/*
题目描述
航海
时间限制 :1sec / 空间限制: 256MB

题意：
二维平面的海上有nn只船，每只船所在位置为(X_i,Y_i).每只船还有一个权值W_i​
现在他们需要聚在一起商讨捕鱼大业，他们想请你找到一个点使得该点到其他点
的带权曼哈顿距离之和最小。带权曼哈顿距离=实际曼哈顿距离*∗权值。

输入：
n，x数组，y数组，w数组
(1 \leq n \leq10^{5}1≤n≤10
5
)
(1 \leq x[i],y[i],w[i] \leq 10^{3}1≤x[i],y[i],w[i]≤10
3
）

输出：
一行一个数字表示最小的带权输出最小的带权距离之和

示例1
输入
复制
2,[2,1],[1,1],[1,1]
输出
复制
1
说明
可以选取(1,1)点，答案为1
备注:
数组下标从0开始
*/


//中位数法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param n int整型 n
	* @param x int整型一维数组 x
	* @param xLen int x数组长度
	* @param y int整型一维数组 y
	* @param yLen int y数组长度
	* @param w int整型一维数组 w
	* @param wLen int w数组长度
	* @return long长整型
	*/
	struct point
	{
		int x;
		int y;
		int w;
	};
	long long MinimumDistance(int n, int* x, int xLen, int* y, int yLen, int* w, int wLen) {
		// write code here
		vector<point> arr(n);
		long long weight = 0;
		for (int i = 0; i < n; ++i) {
			arr[i].x = x[i];
			arr[i].y = y[i];
			arr[i].w = w[i];
			weight += w[i];
		}
		sort(arr.begin(), arr.end(), [](const point& a, const point& b){
			return a.x < b.x;
		});
		weight >>= 1;
		long long tmp_w = 0;
		int px;
		int py;
		for (int i = 0; i < n; ++i) {
			tmp_w += arr[i].w;
			if (tmp_w >= weight) {
				px = arr[i].x;
				break;
			}
		}
		sort(arr.begin(), arr.end(), [](const point& a, const point& b){
			return a.y < b.y;
		});
		tmp_w = 0;
		for (int i = 0; i < n; ++i) {
			tmp_w += arr[i].w;
			if (tmp_w >= weight) {
				py = arr[i].y;
				break;
			}
		}
		long long res = 0;
		int tmp_x = 0;
		int tmp_y = 0;
		for (int i = 0; i < n; ++i) {
			tmp_x = (arr[i].x - px) > 0 ? (arr[i].x - px) : (px - arr[i].x);
			tmp_y = (arr[i].y - py) > 0 ? (arr[i].y - py) : (py - arr[i].y);
			res += (tmp_x + tmp_y) * arr[i].w;
		}
		return res;
	}
};


//枚举法
class Solution1 {
public:
	/**
	*
	* @param n int整型 n
	* @param x int整型一维数组 x
	* @param xLen int x数组长度
	* @param y int整型一维数组 y
	* @param yLen int y数组长度
	* @param w int整型一维数组 w
	* @param wLen int w数组长度
	* @return long长整型
	*/
	struct point
	{
		int x;
		int y;
		int w;
		long long sum1;
		long long sum2;
	};
	long long MinimumDistance(int n, int* x, int xLen, int* y, int yLen, int* w, int wLen) {
		// write code here
		vector<point> arr(n);
		for (int i = 0; i < n; ++i) {
			arr[i].x = x[i];
			arr[i].y = y[i];
			arr[i].w = w[i];
		}
		sort(arr.begin(), arr.end(), [](const point& a, const point& b){
			return a.x < b.x;
		});
		long long sum = 0;
		long long tmp_sum = 0;
		long long ww = 0;
		long long tmp_w = 0;
		for (int i = 0; i < n; ++i) {
			arr[i].sum1 += arr[i].x * ww - sum;
			arr[n - 1 - i].sum1 += tmp_sum - arr[n - 1 - i].x * tmp_w;
			sum += arr[i].x * arr[i].w;
			ww += arr[i].w;
			tmp_sum += arr[n - 1 - i].x * arr[n - 1 - i].w;
			tmp_w += arr[n - 1 - i].w;
		}
		sort(arr.begin(), arr.end(), [](const point& a, const point& b){
			return a.y < b.y;
		});
		sum = 0;
		tmp_sum = 0;
		ww = 0;
		tmp_w = 0;
		for (int i = 0; i < n; ++i) {
			arr[i].sum2 += arr[i].y * ww - sum;
			arr[n - 1 - i].sum2 += tmp_sum - arr[n - 1 - i].y * tmp_w;
			sum += arr[i].y * arr[i].w;
			ww += arr[i].w;
			tmp_sum += arr[n - 1 - i].y * arr[n - 1 - i].w;
			tmp_w += arr[n - 1 - i].w;
		}
		long long res1 = LONG_MAX;
		long long res2 = LONG_MAX;
		for (int i = 0; i < n; ++i) {
			res1 = min(res1, arr[i].sum1);
			res2 = min(res2, arr[i].sum2);
		}
		return res1 + res2;
	}
};


int main()
{
	return 0;
}
