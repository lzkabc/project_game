#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int bird_x,bird_y;
int bar_y,bar_xtop,bar_xdown; //两个障碍物的坐标X1 X2  一个上一个下 并且Y一样
int width,hight;
int score;
//第一步每行每列（for for）都有可能输出（print）小鸟会自己下降（X++) 并且小鸟的坐标受到空格影响（X--)
//障碍物 的变化（X) 也就是 X的变化 随机(rand)
//得分 过了 和没过两种情况 

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
	width=25;
	hight=15;
	bird_x=0;
	bird_y=width/3;
	bar_y=width-1;
	bar_xtop=hight/4;
	bar_xdown=hight/2 +2  ;
	
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
			if((i==bird_x) && (j==bird_y))
				printf("@"); //输出小鸟
			else if((j==bar_y)&&((i<=bar_xtop)||(i>=bar_xdown))) //中间那几行不输出
				printf("*"); //输出长度的障碍物
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("得分:%d",score);

}
void withoutinput()
{
	if(bar_y==bird_y)
	{
		if((bird_x>bar_xtop)&&(bird_x<bar_xdown))  // 过了之后得分加
			score++;
		else
		{
			exit(0); 
		}
	}

	bird_x++;//小鸟往下落
	if(bar_y>0)
		bar_y--;    //如果 消失后又重新出现
	else
	{
		bar_y=width-1;
		int randposition=rand()%(hight-5);
		bar_xtop=randposition;
		bar_xdown=randposition+hight/3;
	}

	Sleep(150);

}


void goinput()
{
	char input;
	if (kbhit())
	{
		input=getch();
		if(input==' ')
		{
			bird_x=bird_x-2; //按空格键小鸟飞上去
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
