#include<bits/stdc++.h>
using namespace std;

int main(){

	//指向二维数组的指针的指针
	int rows = 3, columns = 4;

	int** numbers = new int*[rows];

	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		
	}
	
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			numbers[i][j]=i+j+3;
	
	//输出
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			cout << numbers[i][j]<<" ";
		cout << endl;
	}
	//释放
	for (int i = 0; i < rows; ++i)
		delete[] numbers[i];

	delete[] numbers;
	system("pause");
}
