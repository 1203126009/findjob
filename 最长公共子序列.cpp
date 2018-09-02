/*
��Ŀ������ַ���һ�������ַ��������ַ����е�˳�����������һ���ַ������У����ַ���һ��֮Ϊ�ַ��������Ӵ���ע�⣬����Ҫ���Ӵ����ַ���һ�����ַ����������������ַ������С����дһ�����������������ַ����������ǵ�����������У�����ӡ������������С�
���磺���������ַ���BDCABA��ABCBDAB���ַ���BCBA��BDAB���������ǵ�����������У���������ǵĳ���4������ӡ����һ�������С�

*/

#include<bits/stdc++.h>
using namespace std;
void LCSLength(char* str1, char* str2,char*s)    //��������ַ�������󹫹��Ӵ����Ȳ���������Ӵ�  
{  
	int i, j, length1, length2;
	length1 = strlen(str1);
	length2 = strlen(str2);

	//˫ָ��ķ������붯̬��ά����  
	int **c = new int*[length1 + 1];      //����length1+1��  
	for (i = 0; i < length1 + 1; i++)
		c[i] = new int[length2 + 1];      //����length2+1��  

	for (i = 0; i < length1 + 1; i++)
		c[i][0] = 0;        //��0�ж���ʼ��Ϊ0  
	for (j = 0; j < length2 + 1; j++)
		c[0][j] = 0;        //��0�ж���ʼ��Ϊ0  

	for (i = 1; i < length1 + 1; i++)
	{
		for (j = 1; j < length2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])   //����c[][]��0��0��û��ʹ�ã�c[][]�ĵ�i��Ԫ�ض�Ӧstr1�ĵ�i-1��Ԫ��  
				c[i][j] = c[i - 1][j - 1] + 1;
			else if (c[i - 1][j]>c[i][j - 1])
				c[i][j] = c[i - 1][j];
			else
				c[i][j] = c[i][j - 1];
		}
	}
	int k;
	int  len=k = c[length1][length2];//kΪ����
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


	for (i = 0; i < length1 + 1; i++)    //�ͷŶ�̬����Ķ�ά����  
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


	

