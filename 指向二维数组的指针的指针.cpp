#include<bits/stdc++.h>
using namespace std;

int main(){

	//ָ���ά�����ָ���ָ��
	int rows = 3, columns = 4;

	int** numbers = new int*[rows];

	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		
	}
	
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			numbers[i][j]=i+j+3;
	
	//���
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			cout << numbers[i][j]<<" ";
		cout << endl;
	}
	//�ͷ�
	for (int i = 0; i < rows; ++i)
		delete[] numbers[i];

	delete[] numbers;
	system("pause");
}
