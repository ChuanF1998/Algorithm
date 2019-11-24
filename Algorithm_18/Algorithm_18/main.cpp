/*
题目描述
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。

给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

测试样例：
4,[0,7,1,6],[1,5,0,6]
返回：10(解释：可以左手手套取2只，右手手套取8只)
*/


//思路：如果存在一种颜色的手套（左或右）数量为0的情况，那么该手套的另一半数量必须全部拿走；
//要先保证一半（左或右）的颜色要拿齐全，然后另一半只拿一只即可。需判断左右两种拿法


#include <vector>
#include <algorithm>
using namespace std;

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int way1_count = 0;  //左边种类拿全，右边拿一只
		int way2_count = 0;  //右边种类拿全，左边一只
		int w1 = 0;
		int w2 = 0;
		for (int i = 0; i<n; ++i) {  //存在某种某一边颜色为0，那么另一边要拿全
			if (left[i] == 0){
				way1_count += right[i];  
				way2_count += right[i];
				right[i] = 0;      //拿完后置0
			}
			if (right[i] == 0) {
				way1_count += left[i];
				way2_count += left[i];
				left[i] = 0;
			}
		}
		sort(left.begin(), left.end()); //排序，如排完序后为如[0,0,3,6]
		for (int i = 0; i<n; ++i){      
			if (left[i]>0){
				w1 = i;     //记下第一次不为0的下标
				break;
			}
		}
		for (int i = w1 + 1; i<n; i++){ //遍历左手边,需加 1，因为3不为0，但是
			way1_count += left[i];   //从6开始遍历
		}
		way1_count += 2;           //遍历完加1即可保证一边取完且最小，再在另一边取一只即可匹配

		sort(right.begin(), right.end());//排序
		for (int i = 0; i<n; ++i){
			if (right[i]>0){
				w2 = i;
				break;
			}
		}
		for (int i = w2 + 1; i<n; i++){ //遍历右手边
			way2_count += right[i];
		}
		way2_count += 2;
		return way1_count<way2_count ? way1_count : way2_count;
	}
};


int main()
{
	return 0;
}