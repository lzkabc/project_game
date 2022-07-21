#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define width 35
#define high 20
#define enemynumber 5

int position_x,position_y;
int canvas[high][width]={0};
int enemy_x[enemynumber],enemy_y[enemynumber];
int score;
int i,j;
int enemymove;
int bulletwidth;


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


void data()    //
{
	position_x=high/2;
	position_y=width/2;
	canvas[position_x][position_y]=1;
	for(i=0;i<enemynumber;i++)
	{
		enemy_x[i]=0;
		enemy_y[i]=rand()%width;
		canvas[enemy_x[i]][enemy_y[i]]=3;
	}
	bulletwidth=0;
	enemymove=20;



}

void show()
{
	HideCursor();
	int i,j;
	gotoxy(0,0);
	for (i=0;i<high;i++) 
	{
		for (j=0;j<width;j++)
		{
			if(canvas[i][j]==1)
				printf("A");
			else if(canvas[i][j]==2)
				printf("|");

			else if (canvas[i][j]==3)
				printf("v");
				
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("ตรทึ:%d\n",score);
}
void withoutinput()
{
	int i,j,k;
	for (i=0;i<high;i++) 
	{
		for (j=0;j<width;j++)
		{
			if(canvas[i][j]==2)
			{
				for(k=0;k<enemynumber;k++)
				{
					if((i==enemy_x[k])&&(j==enemy_y[k]))
					{
						canvas[enemy_x[k]][enemy_y[k]]=0;
						enemy_x[k]=0;
						enemy_y[k]=rand()%width;
						canvas[enemy_x[k]][enemy_y[k]]=3;
						score++;
						if(score % 5==0)
							bulletwidth++;
						if(score%20==0)
							enemymove--;

					}

				}



				canvas[i][j]=0;
				if(i>0)
					canvas[i-1][j]=2;


			}
		}
	}


	for(k=0;k<enemynumber;k++)
	{
		if(enemy_x[k]>high)
		{
			canvas[enemy_x[k]][enemy_y[k]]=0;
			enemy_x[k]=0;
			enemy_y[k]=rand()%width;
			canvas[enemy_x[k]][enemy_y[k]]=3;
			score--;

		}

	}

	

	
	static int speed=0;

	if (speed<enemymove)
		speed++;

	
	else
	{
		if(speed==enemymove)
		{
			for(k=0;k<enemynumber;k++)
			{
				canvas[enemy_x[k]][enemy_y[k]]=0;
				enemy_x[k]++;
				canvas[enemy_x[k]][enemy_y[k]]=3;
			}

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
		{
			canvas[position_x][position_y]=0;
			position_x--;
			canvas[position_x][position_y]=1;
		}
		if(input=='s')
		{
			canvas[position_x][position_y]=0;
			position_x++;
			canvas[position_x][position_y]=1;
		}
		if(input=='a')
		{
			canvas[position_x][position_y]=0;
			position_y--;
			canvas[position_x][position_y]=1;
		}
		if(input=='d')
		{
			canvas[position_x][position_y]=0;
			position_y++;
			canvas[position_x][position_y]=1;
		}
		if(input==' ')
		{
			int left,right,x;
			left=position_y-bulletwidth;
			right=position_y+bulletwidth;
			if(left<0)
				left=0;
			if(right>width-1)
				right=width-1;
			for(x=left;x<=right;x++)		
				canvas[position_x-1][x]=2;
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


