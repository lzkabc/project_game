#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int position_x,position_y;
int bullet_x,bullet_y;
int enemy_x,enemy_y;
int score;
int width,hight;

void gotoxy(int x,int y)
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}


void data()    //第一步要输出飞机的位置，所以要定义他的X,Y
{
	width=30;
	hight=18;
	position_x=hight/2;
	position_y=width/2;
	bullet_x=-1;//确定子弹的位置
	bullet_y=position_y;
	enemy_x=0;
	enemy_y=rand()%width;
	score=0;
	HideCursor();


}

void show()
{

	int i,j;
	gotoxy(0,0);
	for (i=0;i<hight;i++) //每行对应输出输出空格确定位置 当到了飞机位置就输出飞机
	{
		for (j=0;j<width;j++)
		{
			if((i==position_x) && (j==position_y))
				printf("*");
			else if((i==bullet_x)&&(j==bullet_y))
				printf("|");
			else if ((i==enemy_x)&&(j==enemy_y))
				printf("$");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("得分:%d\n",score);
}
void withoutinput()
{

	if((bullet_y==enemy_y)&&(bullet_x==enemy_x))
	{
		enemy_x=0;
		bullet_x=-1;
		score++;
		enemy_y=rand()%width;
	}

	
	static int speed=0;
	if (speed<50)
		speed++;

	if(bullet_x>-1)
		bullet_x--;


	if(enemy_x>hight)
	{

		enemy_x=0;
		enemy_y=rand()%width;
	}
	else
	{
		if(speed==50)
		{
			enemy_x++;
			speed=0;
		}
	}


}


void goinput()
{
	char input;
	if (kbhit())
	{
		input=getch();
		if(input=='w')
			position_x--;
		if(input=='s')
			position_x++;
		if(input=='a')
			position_y--;
		if(input=='d')
			position_y++;
		if(input==' ')
		{
			bullet_x=position_x-1;
			bullet_y=position_y;
		}

		
	}
}

int main ()
{

	data ();
	while(1)
	{
		show();
		withoutinput();
		goinput();
	}
	return 0;

}
