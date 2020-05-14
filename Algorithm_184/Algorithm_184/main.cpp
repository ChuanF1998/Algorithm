/*
题目：简单错误记录
题目描述
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。


处理：


1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），
对相同的错误记录（净文件名（保留最后16位）称和行号完全匹配）只记录一条，错误计数增加；


2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；


3、 输入的文件可能带路径，记录文件名称不能带路径。


输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

输出描述:
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：

示例1
输入
复制
E:\V1R2\product\fpgadrive.c   1325
输出
复制
fpgadrive.c 1325 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string split(string& path)
{
	size_t pos = path.rfind('\\');
	string tmp = path.substr(pos + 1);
	if (tmp.size() > 16) {
		tmp = tmp.substr(tmp.size() - 16);
	}
	return tmp;
}

struct errlog
{
public:
	string _path;
	int _line;
	int _count;
public:
	bool operator==(const errlog& e)
	{
		if (e._path.compare(_path) == 0 && e._line == _line) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	string path;
	int line;
	vector<errlog> arr;
	while (cin >> path >> line) {
		errlog e;
		e._path = split(path);
		e._line = line;
		e._count = 1;
		auto res = find(arr.begin(), arr.end(), e);
		if (res == arr.end()) {
			arr.push_back(e);
		}
		else {
			res->_count++;
		}
	}
	for (size_t i = 0; i < arr.size(); ++i) {
		if (i + 8 >= arr.size()) {
			cout << arr[i]._path << " " << arr[i]._line << " " << arr[i]._count << endl;
		}
	}
	return 0;
}