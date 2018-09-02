#include<bits/stdc++.h>
using namespace std;
int **rotatePictureMethod(int **matrix, int m, int n, int flag){
	int **mat = new int*[m];
	for (int i = 0; i < m; i++)
		mat[i] = new int[n];
	
	if (flag == 1)
	{
		for (int i = 0; i<m; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				mat[n - 1 - j][m - 1 - i] = matrix[i][n - 1 - j];
			}
		}
	}
	else
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				mat[n - 1 - j][m - 1 - i] = matrix[m - 1 - i][j];
			}
		}
	}
	
		return mat;
		for (int i = 0; i < m; ++i)
			delete[] mat[i];
		delete[] mat;
}
int main()
{
	int m, n,flag;
	cin >> m >> n>>flag;
	int **mat1 = new int*[m];
	for (int i = 0; i < m; i++)
		mat1[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> mat1[i][j];
		}

	int **mat = rotatePictureMethod(mat1, m, n, flag);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << mat[i][j] <<" ";
		cout << endl;
	}
	//ÊÍ·Å¿Õ¼ä
	for (int i = 0; i < m; ++i)
		delete[] mat1[i];
	delete[] mat1;

	system("pause");
}


	

