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
	printf("�����ٷֱ���Ϸ��ʼ\n");
	printf("��Ҫ��ʼ������Y/N\n");
	scanf(" %c",&start);
	if(start=='N') 
	{
		printf("�͹��´�����ѽ\n");
	}
	else if(start=='Y')
	{
			do{
			printf("-----------------------\n");
			printf("��Ϸ��ʼ\n");
			printf("�����������˵�����:\n");
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
				printf("��������û������\n");
			}
			else{
				printf("�������ǿ϶���ϣ����\n");
			}
			printf("\n");
			printf("���ǵ�����ָ���ǰٷ�֮%.2f\n",love);
			printf("\n");
			printf("��Ҫ�ٲ�����Y/N\n");
			scanf(" %c",&continuel);
		}while(continuel=='Y'||continuel=='y');
		
	}
	printf("�ڴ��´κ���㣡");
	
}
