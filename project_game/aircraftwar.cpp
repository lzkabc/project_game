#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>

#pragma comment(lib,"Winmm.lib")
#define High 800
#define Width 590

IMAGE img_bk; 
float position_x,position_y; 
float bullet_x,bullet_y; 
float enemy_x,enemy_y; 
IMAGE img_planeNormal1,img_planeNormal2; 
IMAGE img_planeExplode1,img_planeExplode2; 
IMAGE img_bullet1,img_bullet2; 
IMAGE img_enemyPlane1,img_enemyPlane2; 


void startup()
{
	mciSendString("open D:\\nizan.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  
	initgraph(Width,High);
	loadimage(&img_bk, "D:\\background.jpg");
	loadimage(&img_planeNormal1, "D:\\planeNormal_1.jpg");
	loadimage(&img_planeNormal2, "D:\\planeNormal_2.jpg");
	loadimage(&img_bullet1, "D:\\bullet1.jpg");
	loadimage(&img_bullet2, "D:\\bullet2.jpg");
	loadimage(&img_enemyPlane1, "D:\\enemyPlane1.jpg");
	loadimage(&img_enemyPlane2, "D:\\enemyPlane2.jpg");
	position_x = Width*0.5;
	position_y = High*0.7;
	bullet_x = position_x;
	bullet_y = -85;
	enemy_x = Width*0.5;
	enemy_y = 10;	
	BeginBatchDraw();	
}

void show()
{
	putimage(0, 0, &img_bk);
	putimage(position_x-50, position_y-60, &img_planeNormal1,NOTSRCERASE);
	putimage(position_x-50, position_y-60, &img_planeNormal2,SRCINVERT);

	putimage(bullet_x-7, bullet_y, &img_bullet1,NOTSRCERASE); 
	putimage(bullet_x-7, bullet_y, &img_bullet2,SRCINVERT);
	putimage(enemy_x, enemy_y, &img_enemyPlane1,NOTSRCERASE);
	putimage(enemy_x, enemy_y, &img_enemyPlane2,SRCINVERT);
	FlushBatchDraw();
	Sleep(5);
}
void updateWithoutInput()
{
	if(bullet_y>-50)
		bullet_y=bullet_y-2;
	if(enemy_y<High)
		enemy_y=enemy_y+2;
	else
	{
		
		enemy_y=0;
		enemy_x=rand()%Width;
	}
	if(abs(enemy_y-bullet_y)+abs(enemy_x-bullet_x)<70)
	{
		enemy_y=0;

		enemy_x=rand() % Width;
	}

	if(abs(enemy_y-position_y)+abs(enemy_x-position_x)<50)
	{
		exit(0);
	}



}

void updateWithInput()
{
		MOUSEMSG m;		
		while (MouseHit())  
		{
			m = GetMouseMsg();
			if(m.uMsg == WM_MOUSEMOVE)
			{
			
				position_x = m.x;
				position_y = m.y;			
			}
			else if (m.uMsg == WM_LBUTTONDOWN)
			{
				
				bullet_x = position_x;
				bullet_y = position_y-85;
				mciSendString("close fgmusic", NULL, 0, NULL);
				mciSendString("open D:\\f_gun.mp3 alias fgmusic", NULL, 0, NULL); 
				mciSendString("play fgmusic", NULL, 0, NULL); 
			}
		}

}


void gameover()
{
	EndBatchDraw();
	getch();
	closegraph();
}



int main()
{
	startup();  	
	while (1)  
	{
		show();  
		updateWithoutInput();  
		updateWithInput();     
	}
	gameover();     
	return 0;
}









