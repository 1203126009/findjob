# include<stdio.h>
#include<iostream>
#include<string.h>
char * str(char *s, int *p);
int main(){
	char s[11] = "0123456789";
	char *t ;
	int a = 1;
	t=str(s, &a);
	puts(t);
	system("pause");
}
char * str(char *s,int *p){
	char *tem=s;
	for (int i = 0; i < 10; i++){
		tem[i] = tem[i]+ *p;
	}
	return tem;
}