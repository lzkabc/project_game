#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int bird_x,bird_y;
int bar_y,bar_xtop,bar_xdown; //�����ϰ��������X1 X2  һ����һ���� ����Yһ��
int width,hight;
int score;
//��һ��ÿ��ÿ�У�for for�����п��������print��С����Լ��½���X++) ����С��������ܵ��ո�Ӱ�죨X--)
//�ϰ��� �ı仯��X) Ҳ���� X�ı仯 ���(rand)
//�÷� ���� ��û��������� 

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


void data()    //��һ��Ҫ����ɻ���λ�ã�����Ҫ��������X,Y
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
	for (i=0;i<hight;i++) //ÿ�ж�Ӧ�������ո�ȷ��λ�� �����˷ɻ�λ�þ�����ɻ�
	{
		for (j=0;j<width;j++)
		{
			if((i==bird_x) && (j==bird_y))
				printf("@"); //���С��
			else if((j==bar_y)&&((i<=bar_xtop)||(i>=bar_xdown))) //�м��Ǽ��в����
				printf("*"); //������ȵ��ϰ���
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("�÷�:%d",score);

}
void withoutinput()
{
	if(bar_y==bird_y)
	{
		if((bird_x>bar_xtop)&&(bird_x<bar_xdown))  // ����֮��÷ּ�
			score++;
		else
		{
			exit(0); 
		}
	}

	bird_x++;//С��������
	if(bar_y>0)
		bar_y--;    //��� ��ʧ�������³���
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
			bird_x=bird_x-2; //���ո��С�����ȥ
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
