/*
题目描述
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过
自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来
找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好
把这个任务交给了你。

输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。
输出描述:
对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

示例1
输入
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

输出
100
1000
1001
*/

/*
常规解法：暴力破解 时间复杂度O（m*n）

简单一点的解法：
将工作难度与工作报酬定义在一个结构体中，将人的能力与人的序号定义在一个结构体
然后为sort排序自定义一个排序方式（O(mlogn))，工作按照难度升序，人按照能力升序，
这里就可以遍历，设i个工作，j个人
当遇到人的能力小于工作难度的情况-->保存前面遇到的最大的报酬，并且保存当前的工作难度，
然后下一个人从当前的工作难度开始遍历，因为人的能力升序，工作难度升序，所以后面的人的
工作能力必然大于已经遍历过的人的工作难度。时间复杂度 O(i+j)
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct job_node
{
	int job_difficulty;
	int job_reward;
};

struct people
{
	int peoson_id;
	int ability;
};
bool compare1(job_node a, job_node b)
{
	return a.job_difficulty < b.job_difficulty;
}

bool compare2(people a, people b)
{
	return a.ability < b.ability;
}
class offer
{
public:
	void max_offer(vector<int>& max_money, vector<job_node>& job, vector<people>& p_ability, int job_num, int people)
	{
		sort(job.begin(), job.end(), compare1);
		sort(p_ability.begin(), p_ability.end(), compare2);
		int max_reward = 0;
		int i = 0;
		int j = 0;
		while (i < people) {
			while (j < job_num) {
				if (p_ability[i].ability < job[j].job_difficulty) {
					break;
				}
				if (p_ability[i].ability >= job[j].job_difficulty) {
					if (job[j].job_reward > max_reward) {
						max_reward = job[j].job_reward;
					}
				}
				++j;
			}
			max_money[p_ability[i].peoson_id - 1] = max_reward;
			++i;
		}
	}
};


int main()
{
	offer o;
	int job_num;
	int people_num;
	vector<int> max_money;
	vector<job_node> job;
	vector<people> p_ability;
	while (cin >> job_num >> people_num) {
		max_money.resize(people_num, 0);
		job.resize(job_num);
		p_ability.resize(people_num);
		for (int i = 0; i < job_num; i++) {
			cin >> job[i].job_difficulty;
			cin >> job[i].job_reward;
		}
		for (int i = 0; i < people_num; ++i) {
			p_ability[i].peoson_id = i + 1;
			cin >> p_ability[i].ability;
		}
		o.max_offer(max_money, job, p_ability, job_num, people_num);
		for (int i = 0; i < people_num; ++i) {
			cout << max_money[i] << endl;
		}
		max_money.clear();
		job.clear();
		p_ability.clear();
	}
	return 0;
}