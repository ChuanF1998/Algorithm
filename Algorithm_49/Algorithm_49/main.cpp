/*
题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。
*/




class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		for (int i = 0; i < length; ++i) {
			for (int j = i + 1; j < length; ++j) {
				if (numbers[i] == numbers[j]) {
					//duplication = &numbers[i];
					*duplication = numbers[i];
					return true;
				}
			}
		}
		return false;
	}
};


int main()
{
	Solution s;
	int numbers[] = { 2, 2, 6, 8, 4 };
	int n = 5;
	int *k = &n;
	s.duplicate(numbers, 5, k);
	return 0;
}


/* 另一种写法，时间复杂度为O(n),让每个数字都回到自己的位置
若有重复的数字，那么它必然与自己当前位置上的数相等
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        if((numbers == nullptr)||(length < 1)) {
            return false;
        }
        for(int i = 0; i < length; ++i) {
            if((numbers[i] < 0)||(numbers[i] > length - 1)) {
                return false;
            }
        }
        for(int i = 0; i < length; ++i) {
            while(numbers[i] != i) {
                if(numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                }
                int temp = numbers[numbers[i]];
                numbers[numbers[i]] = numbers[i];
                numbers[i] = temp;
            }
        }
        return false;
    }
};

*/