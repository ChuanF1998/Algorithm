/*
��Ŀ����
Ϊ���ҵ��Լ�����Ĺ�����ţţ�ռ���ÿ�ֹ������ѶȺͱ��ꡣţţѡ�����ı�׼�����ѶȲ�����
��������ֵ������£�ţţѡ�񱨳���ߵĹ�������ţţѡ�����Լ��Ĺ�����ţţ��С�������
��ţţ��æѡ������ţţ��Ȼʹ���Լ��ı�׼������С����ǡ�ţţ��С���̫���ˣ�������ֻ��
��������񽻸����㡣

��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а����������������ֱ��ʾ����������N(N<=100000)��С��������M(M<=100000)��
��������N��ÿ�а����������������ֱ��ʾ��������Ѷ�Di(Di<=1000000000)�ͱ���Pi(Pi<=1000000000)��
��������һ�а���M�����������ֱ��ʾM��С��������ֵAi(Ai<=1000000000)��
��֤������������ı�����ͬ��
�������:
����ÿ��С��飬�ڵ�����һ�����һ����������ʾ���ܵõ�����߱��ꡣһ���������Ա������ѡ��

ʾ��1
����
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

���
100
1000
1001
*/

/*
����ⷨ�������ƽ� ʱ�临�Ӷ�O��m*n��

��һ��Ľⷨ��
�������Ѷ��빤�����궨����һ���ṹ���У����˵��������˵���Ŷ�����һ���ṹ��
Ȼ��Ϊsort�����Զ���һ������ʽ��O(mlogn))�����������Ѷ������˰�����������
����Ϳ��Ա�������i��������j����
�������˵�����С�ڹ����Ѷȵ����-->����ǰ�����������ı��꣬���ұ��浱ǰ�Ĺ����Ѷȣ�
Ȼ����һ���˴ӵ�ǰ�Ĺ����Ѷȿ�ʼ��������Ϊ�˵��������򣬹����Ѷ��������Ժ�����˵�
����������Ȼ�����Ѿ����������˵Ĺ����Ѷȡ�ʱ�临�Ӷ� O(i+j)
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