#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void lovestar()
{
	int i,j;
	printf("      ****        ****\n");
	printf("   *********    *********\n");
	printf("*************  *************\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<29;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<2*(i+1)-1;j++)
		{
			printf(" ");
		}
		for(j=0;j<27-i*4;j++)
		{ 
		 printf("*");
		}
		printf("\n");
	}
	for(i=0;i<14;i++)
	{
		printf(" ");
	}
	printf("*\n");
	

}
int main()
{
	char start;
	char people1[20],people2[20];
	float love;
	char continuel;
	int ret;
	int i,j;
	printf("恋爱百分比游戏开始\n");
	printf("你要开始测试吗？Y/N\n");
	scanf(" %c",&start);
	if(start=='N') 
	{
		printf("客官下次来玩呀\n");
	}
	else if(start=='Y')
	{
			do{
			printf("-----------------------\n");
			printf("游戏开始\n");
			printf("请输入两个人的名字:\n");
			scanf(" %s %s",people1,people2);
			srand(time(NULL));
			love=rand()%100;
			printf("\n");
			if(love>=80)
			{
				lovestar();
			}
			else if(love<=20)
			{
				printf("你们两个没机会啦\n");
			}
			else{
				printf("加油你们肯定有希望的\n");
			}
			printf("\n");
			printf("你们的恋爱指数是百分之%.2f\n",love);
			printf("\n");
			printf("还要再测试吗？Y/N\n");
			scanf(" %c",&continuel);
		}while(continuel=='Y'||continuel=='y');
		
	}
	printf("期待下次和你搞！");
	
}
