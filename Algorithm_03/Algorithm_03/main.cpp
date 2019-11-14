/*
题目描述
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
输入描述:
输入第一行为字符串个数n(n ≤ 100)
接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
输出描述:
如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",

如果根据长度排列而不是字典序排列输出"lengths",

如果两种方式都符合输出"both"，否则输出"none"
*/


/*下面注释掉的代码是与题意不符，我的想法是只要是排序（不管是降序，升序）就算，题目意思是只是升序才算*/





#include <iostream>
#include <string>
#include <vector>
using namespace std;


class str_sort
{
public:
	string Get_way(vector<string> str)
	{
		int lex_way = 1;
		int len_way = 1;
		size_t i = 1;
		size_t n = str.size();
		if (n == 1) {
			return "both";
		}
		if (str[i].compare(str[i - 1]) > 0) {
			while (i<n) {
				if (str[i].compare(str[i - 1]) > 0) {
					++i;
				}
				else {
					lex_way = 0;
					break;
				}
			}
		}
		else {
			lex_way = 0;
			//while(i<n) {
			//   if(str[i].compare(str[i-1]) < 0) {
			//       ++i;
			//   }
			//   else {
			//       lex_way=0;
			//       break;
			//   }
			// }
		}
		i = 1;
		if (str[i].size()>str[i - 1].size()) {
			while (i<n) {
				if (str[i].size()>str[i - 1].size()) {
					++i;
				}
				else {
					len_way = 0;
					break;
				}
			}
		}
		else {
			len_way = 0;
			//while(i<n) {
			//     if(str[i].size()< str[i-1].size()) {
			//         ++i;
			//     }
			//     else {
			//         len_way=0;
			//         break;
			//     }
			// }
		}
		if (lex_way == 1 && len_way == 1) {
			return "both";
		}
		else if (lex_way == 1 && len_way == 0) {
			return "lexicographically";
		}
		else if (lex_way == 0 && len_way == 1) {
			return "lengths";
		}
		else {
			return "none";
		}
	}
};


int main()
{
	str_sort s;
	int n;
	string k;
	while (cin >> n){
		if (n >= 1){
			vector<string> str(n);
			for (int i = 0; i<n; i++) {
				cin >> k;
				str[i] = k;
			}
			cout << s.Get_way(str) << endl;
		}

	}
	return 0;
}