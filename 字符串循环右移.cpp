#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

#define MAX_LEN 100  
void Loop1(char *pstr, int steps)
{
	char temp[MAX_LEN];
	int n = strlen(pstr) - steps;
	strcpy(temp, pstr + n);
	strcpy(temp + steps, pstr);
	*(temp + strlen(pstr)) = '\0';
	strcpy(pstr, temp);
}
void Loopmem(char *pstr, int steps)
{
	char temp[MAX_LEN];
	int n = strlen(pstr) - steps;
	memcpy(temp, pstr + n, steps);
	memcpy(temp + steps, pstr, n);
	memcpy(pstr, temp, strlen(pstr));

}
int main(){
	char s[1000];
	int steps;
	gets(s);
	cin >> steps;
	Loop1(s, steps);
	cout << s << endl;
	system("pause");

}