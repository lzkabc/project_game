#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<stdlib.h>
#include"vt.h"

#define row 10
#define col 10

int gameover(int bg[][col],int x,int y,int chess);

int show(int bg[][col])
{
	int i;
	int j;
	printf(" ");
	for(i=0;i<col;i++){
	   /* if(i<10)
			printf(" ");*/
		printf(" %d",i);
		}
	printf("\n");

	for(i=0;i<row;i++){
		/*if(i<10)
			printf(" ");*/
		printf("%d ",i);
		for(j=0;j<col;j++){//检查是否有子
			if(bg[i][j]==0)
				printf("\033[30m+\033[0m ");
			else if(bg[i][j]==1)
				printf("\033[32mB\033[0m ");
			else if(bg[i][j]==2)
				printf("\033[37mw\033[0m ");
				}
		printf("\n");
		}
}

int chesserr(int bg[][col],int chess_x,int chess_y)
{
	int iferr=1;
	//不能越界
	if(chess_x<0||chess_x>col || chess_y<0 || chess_y>row)
		iferr=1;
	//有子
	else if(bg[chess_x][chess_y]>0)
		iferr=1;
	else
		iferr=0;
	return iferr;
}

int main(void)
{
	int chess=1;
	int chess_x,chess_y;
	char xian[20];
	int num;
	int i;
	int bg[row][col]={0};//棋盘
	srand(time(NULL));
	for(i=0;i<30;i++)
	{
		num=rand()%1000+1;
		if(num%2==0)
		{
			printf("\033[3;6H黑子先");
			chess=1;
			}
		else
		{
			printf("\033[3;6H白子先");
			chess=-1;
			}
		usleep(100000);
		fflush(NULL);
		}
		usleep(1000000);
		printf("\033[3;6H     ");
	while(1)//开始游戏	{
		gotoxy(5,1);
		show(bg);
		if(chess==1){
			printf("\033[30m请[黑子下棋]:033[K");
			scanf("%d%d",&chess_x,&chess_y);
			}
		else{
			printf("\033[30m请[白子下棋]:033[K");
			scanf("%d%d",&chess_x,&chess_y);
			}
		//		if(chesserr(bg,chess_x,chess_y))
			continue;
		if(chess==1)
			 bg[chess_x][chess_y]=1;//有子
		else
			 bg[chess_x][chess_y]=2;//有子
		//判断输赢
		if(gameover(bg,chess_x,chess_y,chess))
		{
			if(chess==1)
				printf("黑子获胜");
			else
				printf("白子获胜");
			break;
		}
		//交换玩家
		chess=chess*-1;
	}

	return 0;
}

int gameover(int bg[][col],int x,int y,int chess)
{
	int ifwin=0;
	int getfive=0;
	int what;
	int yijin=0;
	int i,j;
	if(chess==1)
		what=1;
	else
		what=2;

	//3种赢法 横竖斜
	for(i=x-4;i<=x+4;i++){
		if(i<0 || i>col)
			continue;
		if(bg[i][y]==what)
			getfive++;
		else
			getfive=0;
		if(getfive==5)
			return 1;
		}
		getfive=0;
	for(i=y-4;i<=y+4;i++){
		if(y<0 || y>row)
			continue;
		if(bg[x][i]==what)
			getfive++;
		else
			getfive=0;
		if(getfive==5)
			return 1;
			}
	for(i=x-4;i<=x+4;i++){
		yijin=0;
		if(i<0 || i>col)
			continue;
		for(j=y-4;j<=y+4;y++){
			if(j<0 || j>row)
				continue;
			if(bg[i][j]==what)
				getfive++;
			else
				getfive=0;
			yijin=1;
			if(yijin==1)
				break;
			}
		if(getfive==5)
			return 1;
		}
	return 0;
}