/*
��Ŀ����
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}��
��ô��Ӧ������ǵ�һ���ظ�������2��
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


/* ��һ��д����ʱ�临�Ӷ�ΪO(n),��ÿ�����ֶ��ص��Լ���λ��
�����ظ������֣���ô����Ȼ���Լ���ǰλ���ϵ������
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