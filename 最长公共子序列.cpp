/*
题目：如果字符串一的所有字符按其在字符串中的顺序出现在另外一个字符串二中，则字符串一称之为字符串二的子串。注意，并不要求子串（字符串一）的字符必须连续出现在字符串二中。请编写一个函数，输入两个字符串，求它们的最长公共子序列，并打印出最长公共子序列。
例如：输入两个字符串BDCABA和ABCBDAB，字符串BCBA和BDAB都是是它们的最长公共子序列，则输出它们的长度4，并打印任意一个子序列。

*/

#include<bits/stdc++.h>
using namespace std;
void LCSLength(char* str1, char* str2,char*s)    //求得两个字符串的最大公共子串长度并输出公共子串  
{  
	int i, j, length1, length2;
	length1 = strlen(str1);
	length2 = strlen(str2);

	//双指针的方法申请动态二维数组  
	int **c = new int*[length1 + 1];      //共有length1+1行  
	for (i = 0; i < length1 + 1; i++)
		c[i] = new int[length2 + 1];      //共有length2+1列  

	for (i = 0; i < length1 + 1; i++)
		c[i][0] = 0;        //第0列都初始化为0  
	for (j = 0; j < length2 + 1; j++)
		c[0][j] = 0;        //第0行都初始化为0  

	for (i = 1; i < length1 + 1; i++)
	{
		for (j = 1; j < length2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])   //由于c[][]的0行0列没有使用，c[][]的第i行元素对应str1的第i-1个元素  
				c[i][j] = c[i - 1][j - 1] + 1;
			else if (c[i - 1][j]>c[i][j - 1])
				c[i][j] = c[i - 1][j];
			else
				c[i][j] = c[i][j - 1];
		}
	}
	int k;
	int  len=k = c[length1][length2];//k为长度
	s[k--] = '\0';
	i = length1, j = length2;
	while (i>0 && j>0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			s[k--] = str1[i - 1];
			i--;
			j--;
		}
		else if (c[i - 1][j]<c[i][j - 1])
			j--;
		else
			i--;
	}
	s[len ]= '\0';


	for (i = 0; i < length1 + 1; i++)    //释放动态申请的二维数组  
		delete[] c[i];
	delete[] c;
	
}

int main()
{
	char str1[100], str2[100],res[100];
	
	gets(str1);
	gets(str2);
	 LCSLength(str1, str2,res);
	 cout << res << endl;
	system("pause");
}


	

