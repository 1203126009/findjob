#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0)
			return;
		int originalLenght = 0, blanknum = 0;
		for (int i = 0; str[i] != '\0'; i++){
			originalLenght++;
			if (str[i] == ' ')
				blanknum++;
		}
		int newLength = originalLenght + blanknum * 2;//新长度
		int newIndex = newLength, originalIndex = originalLenght;
		while (originalIndex >= 0  &&newIndex>originalIndex){
			if (str[originalIndex] == ' '){
				str[newIndex--] = '0';
				str[newIndex--] = '2';
				str[newIndex--] = '%';
			}
			else
				str[newIndex--] = str[originalIndex];
			originalIndex--;
		}

	}
};

/* int main(){
	char str[100] ;
	gets(str);
	Solution A;
	A.replaceSpace(str, 100);
	cout << str << endl;
	system("pause");
	return 0;
} */