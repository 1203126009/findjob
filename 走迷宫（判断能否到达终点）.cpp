/*
����
�ж��Ƿ��ܴ��Թ�����ڵ������
 
����
����������������ʾ�Թ�������m������n��������ںͳ��ڵ����꣬����m�������Թ�������1��ʾǽ��0��ʾ�ո�ÿ������֮�䶼�пո�
 
���
���ܵ�������"Yes"���������"No"�����ռһ�С�
 
��������
3 3
0 0
2 2
0 0 0
1 1 0
0 1 0
 
�������
Yes
*/
#include<stdio.h>
int Arr[30][30];//����Թ�Ϊ30*30
int Rownum=0,Colnum=0;//������
int Beginrow,Begincol,Endrow,Endcol;//�յ�����
int state=0;//�Թ���ͨ���״̬
int canplace(int row,int col)//�жϵ�ǰ���ܷ���ͨ
{
    if(row>=0 &&col>=0 &&row<Rownum &&col<Colnum &&Arr[row][col]==0)//ΪԽ���ҿ���ͨ
        return 1;
    return 0;
}
void search(int row,int col)
{
    if(row==Endrow && col==Endcol)//��Ŀ���յ�    
    {    state=1;  return ;   }
    
    int r,c;
    Arr[row][col]=1;//�Կ���ͨ�ĵ���б��
    r=row-1; c=col; //��
    if(canplace(r,c))  search(r,c); 
    r=row; c=col+1;//�� 
    if(canplace(r,c))  search(r,c); 
    r=row+1;  c=col;//��
    if(canplace(r,c))  search(r,c); 
    r=row;    c=col-1;//��
    if(canplace(r,c))  search(r,c); 
}
int main()
{ 
    int i,j;
    scanf("%d%d",&Rownum,&Colnum);//�����Թ�������  
    scanf("%d%d%d%d",&Beginrow,&Begincol,&Endrow,&Endcol);//��ʼ�㣬�յ�����
    for(i=0;i<Rownum;i++)
        for(j=0;j<Colnum;j++)
           scanf("%d",&Arr[i][j]);       //һ��һ�е������Թ�����
    
    Arr[Beginrow][Begincol]=1;
    search(Beginrow,Begincol);
    //һ���Թ�����·���������״̬����ʼ���ͨ���
    if(state==1)
        printf("Yes\n");
    else
        printf("No\n");    
    return 0;
}
