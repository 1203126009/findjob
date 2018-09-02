/*
描述
判断是否能从迷宫的入口到达出口
 
输入
先输入两个整数表示迷宫的行数m和列数n，再输入口和出口的坐标，最后分m行输入迷宫，其中1表示墙，0表示空格每个数字之间都有空格。
 
输出
若能到达，则输出"Yes"，否则输出"No"，结果占一行。
 
输入样例
3 3
0 0
2 2
0 0 0
1 1 0
0 1 0
 
输出样例
Yes
*/
#include<stdio.h>
int Arr[30][30];//最大迷宫为30*30
int Rownum=0,Colnum=0;//行列数
int Beginrow,Begincol,Endrow,Endcol;//终点坐标
int state=0;//迷宫走通与否状态
int canplace(int row,int col)//判断当前点能否走通
{
    if(row>=0 &&col>=0 &&row<Rownum &&col<Colnum &&Arr[row][col]==0)//为越界且可走通
        return 1;
    return 0;
}
void search(int row,int col)
{
    if(row==Endrow && col==Endcol)//是目标终点    
    {    state=1;  return ;   }
    
    int r,c;
    Arr[row][col]=1;//对可走通的点进行标记
    r=row-1; c=col; //上
    if(canplace(r,c))  search(r,c); 
    r=row; c=col+1;//右 
    if(canplace(r,c))  search(r,c); 
    r=row+1;  c=col;//下
    if(canplace(r,c))  search(r,c); 
    r=row;    c=col-1;//左
    if(canplace(r,c))  search(r,c); 
}
int main()
{ 
    int i,j;
    scanf("%d%d",&Rownum,&Colnum);//输入迷宫行列数  
    scanf("%d%d%d%d",&Beginrow,&Begincol,&Endrow,&Endcol);//起始点，终点坐标
    for(i=0;i<Rownum;i++)
        for(j=0;j<Colnum;j++)
           scanf("%d",&Arr[i][j]);       //一行一行的输入迷宫布局
    
    Arr[Beginrow][Begincol]=1;
    search(Beginrow,Begincol);
    //一个迷宫搜索路径后的最终状态，起始点接通与否
    if(state==1)
        printf("Yes\n");
    else
        printf("No\n");    
    return 0;
}
