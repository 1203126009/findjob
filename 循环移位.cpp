#include<iostream>
using namespace std;
char* rotateLeft(char *start, int p){
	char *start1;
	start1 = start;
	int num = 0;
	while (*start != '\0')
	{
		num++;
		start++;
	}
    char * end = new char [num+1];
	for (int i = 0; i < p; i++)
		end[num - p +i] = start1[i];//start��ǰpλ�ƶ���end�ĺ�pλ
	for (int i = p; i < num; i++)
		end[i - p] = start1[i];//startʣ����ǰ��
	end[num] = '\0';
	return end;
	delete []end;
}
char * rotateRight(char *start,  int p)
{
	char *start1;
	start1 = start;
	int num = 0;
	while (*start != '\0')
	{
		num++;
		start++;
	}
	char * end1 = new char[num + 1];
	for (int i = num- p; i < num; i++)
		end1[i - (num - p)] = start1[i];// start�ĺ�pλ�ƶ���end��ǰpλ
	for (int i = 0; i < num - p; i++)
		end1[i + p] = start1[i];//startʣ��������
	end1[num] = '\0';
	return end1;
	delete[]end1;
}
/*
void rotateLeft(int *start, int *end, int len, int p){
	for (int i = 0; i < p; i++)
		end[len - p + i] = start[i];//start��ǰpλ�ƶ���end�ĺ�pλ
	for (int i = p; i < len; i++)
		end[i - p] = start[i];//startʣ����ǰ��
}
void rotateRight(int *start, int *end, int len, int p){

	for (int i = len - p; i < len; i++)
		end[i - (len - p)] = start[i];// start�ĺ�pλ�ƶ���end��ǰpλ
	for (int i = 0; i < len - p; i++)
		end[i + p] = start[i];//startʣ��������
}
*/
int main()
{
	
	char *s = "12345";
	//char *res = rotateLeft(s, 3);
	char *res1 = rotateRight(s, 3);
	//cout << res << endl;
	cout<< res1 << endl;
	system("pause");
}
/*
int main()
{
	int n, m;
	cin >> n >> m;//mΪ��λ���ٴ�
	m = m%n;
	int * start = new int[n];
	int * end = new int[n];
	for (int i = 0; i < n; i++)
	{
		start[i] = i;
	}
	printf("��λǰ�Ľ����");
	for (int i = 0; i < n; i++)
		cout << start[i] << " ";
	cout << endl;
	if (m != 0)
	{
		cout << "ѭ������λ" << m << "λ" << "��Ľ����";
		rotateLeft(start, end, n, m);
		for (int i = 0; i < n; i++)
			cout << end[i] << " ";
		cout << endl;
		rotateRight(start, end, n, m);
		cout << "ѭ������" << m << "λ" << "��Ľ����";
		for (int i = 0; i < n; i++)
			cout << end[i] << " ";
		cout << endl;
	
	}
	delete[] start;
	delete[] end;
	system("pause");
}
*/