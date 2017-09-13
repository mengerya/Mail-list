#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include"contact.h"

void meau()
{
	printf("*********************************************\n");
	printf("*********       My address book       *******\n");
	printf("********* 1.Add              2.Del    *******\n");
	printf("********* 3.Search           4.Modify *******\n");
	printf("********* 5.Empty            6.Sort   *******\n");
	printf("********* 7.Show             0.Exit   *******\n");
	printf("*********************************************\n");
}


void test()
{
	
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		meau();
		printf("请选择你要进行的操作:\n");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			{
				AddContact(&con);
			}
			break;
	
		case 2:
			{
				DelContact(&con);
			}
			break;
		case 3:
			{
				SearchContact(&con);
			}
			break;
		case 4:
			{
				ModifyContact(&con);
			}
			break;
		case 5:
			{
				EmptyContact(&con);
			}
			break;
		case 6:
			{
				SortContact(&con);
			}
			break;
		case 7:
			{
				ShowContact(&con);
			}
			break;
		case 0:
			SaveContact(&con);
			DestroyContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}while(input);
}

int main()
{
	test();
	system("pause");
	return 0;
}
