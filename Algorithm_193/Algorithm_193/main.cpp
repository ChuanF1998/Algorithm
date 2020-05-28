/*
题目：设计LRU缓存结构
题目描述
设计LRU缓存结构，该结构在构造时确定大小，假设大小为K，并有如下两个功能
set(key, value)：将记录(key, value)插入该结构
get(key)：返回key对应的value值
[要求]
set和get方法的时间复杂度为O(1)
某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的。
当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
输入描述:
第一行两个个整数N, K，表示操作数量以及缓存结构大小
接下来N行，第一行一个整数opt表示操作类型。
若opt=1，接下来两个整数x, y，表示set(x, y)
若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
输出描述:
对于每个操作2，输出一个答案
示例1
输入
复制
6 3
1 1 1
1 2 2
1 3 2
2 1
1 4 4
2 2
输出
复制
1
-1
说明
第一次操作后：最常使用的记录为("1", 1)
第二次操作后：最常使用的记录为("2", 2)，("1", 1)变为最不常用的
第三次操作后：最常使用的记录为("3", 2)，("1", 1)还是最不常用的
第四次操作后：最常用的记录为("1", 1)，("2", 2)变为最不常用的
第五次操作后：大小超过了3，所以移除此时最不常使用的记录("2", 2)，加入记录("4", 4)，
并且为最常使用的记录，然后("3", 2)变为最不常使用的记录
备注:
1 \leqslant K \leqslant N \leqslant 10^51⩽K⩽N⩽10
5

-2 * 10^9 \leqslant x, y \leqslant 2 * 10^9−2∗10
9
⩽x,y⩽2∗10
9

*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	int k;
	while (cin >> n >> k) {
		vector<int> res;
		unordered_map<int, int> m;
		list<pair<int, int> > q;
		int opt;
		int key;
		int val;
		for (int i = 0; i < n; ++i) {
			cin >> opt;
			if (opt == 1) {
				cin >> key >> val;
				if (q.size() < k && m.count(key) == 0) {
					q.push_back({ key, val });
					m[key] = val;
				}
				if (q.size() == k && m.count(key) == 0) {
					int tmp = q.front().first;
					m.erase(tmp);
					q.pop_front();
					q.push_back({ key, val });
					m[key] = val;
				}
			}
			if (opt == 2) {
				cin >> key;
				if (m.count(key) != 0) {
					res.push_back(m[key]);
					auto it = q.begin();
					for (; it != q.end(); ++it) {
						if (key == it->first) {
							break;
						}
					}
					int tmp_k = it->first;
					int tmp_v = it->second;
					q.erase(it);
					q.push_back({ tmp_k, tmp_v });
				}
				if (m.count(key) == 0) {
					res.push_back(-1);
				}
			}
		}
		for (size_t i = 0; i < res.size(); ++i) {
			cout << res[i] << endl;
		}
	}
	return 0;
}