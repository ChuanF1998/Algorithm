/*
题目描述
MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过
上下键才能浏览所有的歌曲。为了简化处理，假设每屏只能显示4首歌曲，光标初始的
位置为第1首歌。

现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：

歌曲总数<=4的时候，不需要翻页，只是挪动光标位置。

光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，
按Down键光标挪到第一首歌曲。

其他情况下用户按Up键，光标挪到上一首歌曲；用户按Down键，光标挪到下一首歌曲。



2. 歌曲总数大于4的时候（以一共有10首歌为例）：

特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，
用户按Up键后，屏幕要显示最后一页（即显示第7-10首歌），同时光标放到最后一
首歌上。同样的，屏幕显示最后一页时，光标在最后一首歌曲上，用户按Down键，屏
幕要显示第一页，光标挪到第一首歌上。

一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户
按Up键后，屏幕从当前歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当前
屏幕的最后一首歌时的Down键处理也类似。

其他情况，不用翻页，只是挪动光标就行。

输入描述:
输入说明：
1 输入歌曲数量
2 输入命令 U或者D

输出描述:
输出说明
1 输出当前列表
2 输出当前选中歌曲

示例1
输入
10
UUUU

输出
7 8 9 10
7
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class music_page
{
public:
	int get_music(int n, string options, vector<int>& arr)
	{
		int cursor = 1; //初始光标为1
		int option_size = options.size();
		//歌曲数量小于等于4，只需移动光标
		if (n<5) {   
			for (int i = 1; i <= n; ++i) {
				arr.push_back(i);
			}
			for (int i = 0; i<option_size; ++i) {
				if (options[i] == 'D'){
					if (cursor == n) { //光标在n时，向下则光标置1，其他情况加1
						cursor = 1;
					}
					else {
						++cursor;
					}
				}
				if (options[i] == 'U'){
					if (cursor == 1){ //光标在1时，向上则光标置n，其他情况减1
						cursor = n;
					}
					else {
						--cursor;
					}
				}
			}
		}
		else {
			for (int i = 1; i<5; ++i) { //设置初始1，2，3，4
				arr.push_back(i);
			}
			for (int i = 0; i<option_size; ++i) {
				if (options[i] == 'D'){
					if (cursor == n){  //光标在n时，向下则光标置1，数组重新赋值
						cursor = 1;
						arr.clear();
						for (int j = 0; j<4; ++j) {
							arr.push_back(j + 1);
						}
					}
					else{              //其他情况加1
						++cursor;
						if (cursor>arr.back()){  //当光标大小超过数组最后一个值大小，删除第一个
							arr.erase(arr.begin());
							arr.push_back(cursor); //插入此时的光标
						}
					}

				}
				if (options[i] == 'U'){
					if (cursor == 1){    //光标在1时，向上则光标置n，数组重新赋值
						cursor = n;
						arr.clear();
						for (int j = 3; j >= 0; --j) {
							arr.push_back(n - j);
						}
					}
					else {             //其他情况减1
						--cursor;
						if (cursor<arr.front()){ //当光标大小超过数组第一个值大小，删除最后一个
							arr.pop_back();
							arr.insert(arr.begin(), cursor); //插入此时的光标
						}
					}
				}
			}
		}
		return cursor;
	}
};


int main()
{
	music_page m;
	int n;
	string str;
	while (cin >> n >> str) {
		vector<int> arr;
		int cursor = m.get_music(n, str, arr);
		for (int i = 0; i<arr.size(); ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << cursor << endl;
	}
	return 0;
}