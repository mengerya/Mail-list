#define _CRT_SECURE_NO_WARNINGS 1  
#include"contact.h"
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>

void LoadContct(pContact pc)
{
	FILE* pfread = fopen(FILE_NAME,"r");
	PeoInfo tmp;
	int i = 0;
	if(NULL == pfread)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	while(fread(&tmp,sizeof(PeoInfo),1,pfread))
	{
		CheckCapacity(pc);
		pc->sz++;
		pc->data[pc->sz] = tmp; 
	}

	fclose(pfread);
}

void InitContact(pContact pc)
{
	//初始化通讯录
	pc->sz = 0;
	pc->data = (PeoInfo*)malloc(sizeof(PeoInfo)*DEFAULT_SZ);
	if(pc ->data == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	pc->capacity = DEFAULT_SZ;
	LoadContct(pc);
}
//增容
void CheckCapacity(pContact pc)
{
	if(pc->sz == pc->capacity)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data,(pc->capacity + 2)*sizeof(PeoInfo));
		if(tmp != NULL)
		{
			pc->data = tmp;
		}
		pc->capacity += DEFAULT_INC;
		printf("增容成功\n");
	}
}

void DestroyContact(pContact pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

void AddContact(pContact pc)
{
	CheckCapacity(pc);
	printf("请输入要添加的姓名:>");
    scanf("%s",pc->data[pc->sz].name);
	printf("请输入要添加的年龄:>");
	scanf("%d",&(pc->data[pc->sz].age));
	printf("请输入要添加的性别:>");
	scanf("%s",pc->data[pc->sz].sex);
	printf("请输入要添加的电话号码:>");
    scanf("%s",pc->data[pc->sz].tele);
	printf("请输入要添加的地址:>");
	scanf("%s",pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
}
void ShowContact(const pContact pc)
{
	//显示通讯录信息
	int i = 0;
	printf("%10s\t%4s\t%5s\t%10s\t%10s\n","name","age","sex","tele","addr");
	for(i=0;i<pc->sz;i++)
	{
		printf("%10s\t%4d\t%5s\t%10s\t%10s\n",pc->data[i].name,pc->data[i].age,pc->data[i].sex,pc->data[i].tele,pc->data[i].addr);
	}
}
int Find(pContact pc,char name[])
{
	int i = 0;
	for(i=0;i<pc->sz;i++)
	{
		if(strcmp(pc->data[i].name,name)==0)
		{
			return i;
		}
		
	}
	return -1;
}
void DelContact(pContact pc)
{
	char name[NAME_MAX];
	int pos = 0;
	
	if(pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入要删除的人的姓名\n");
	scanf("%s",name);
	pos = Find(pc,name);
	if(pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除联系人
		int i = 0;
		for(i=pos;i<pc->sz-1;i++)
		{
			pc->data[i] = pc->data[i+1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}

void SearchContact(const pContact pc)
{
	//查询联系人
	char name[NAME_MAX];
	int pos = 0;
	
	if(pc->sz == 0)
	{
		printf("通讯录为空，无需查询\n");
		return;
	}
	printf("请输入要查找的人的姓名\n");
	scanf("%s",name);
	pos = Find(pc,name);
	if(pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%10s\t%4d\t%5s\t%10s\t%10s\n",pc->data[pos].name,pc->data[pos].age,pc->data[pos].sex,pc->data[pos].tele,pc->data[pos].addr);
	}
}
void ModifyContact(pContact pc)
{
	//修改通讯录
	char name[NAME_MAX];
	int pos = 0;
	
	if(pc->sz == 0)
	{
		printf("通讯录为空，无需修改\n");
		return;
	}
	printf("请输入要修改的人的姓名\n");
	scanf("%s",name);
	pos = Find(pc,name);
	if(pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入要添加的姓名:>");
	    scanf("%s",pc->data[pos].name);
	    printf("请输入要添加的年龄:>");
	    scanf("%d",&(pc->data[pos].age));
	    printf("请输入要添加的性别:>");
	    scanf("%s",pc->data[pos].sex);
	    printf("请输入要添加的电话号码:>");
	    scanf("%s",pc->data[pos].tele);
	    printf("请输入要添加的地址:>");
	    scanf("%s",pc->data[pos].addr);
	}
}


void EmptyContact(pContact pc)
{
	//清空通讯录
	pc->sz = 0;
}


void SortContact(pContact pc)
{
	//排序
	
	int i = 0;
    int j = 0;
    for(i=0;i<pc->sz-1;i++)
    {
        for(j=0;j<pc->sz-1-i;j++)
        {
            if(strcmp(pc->data[j].name,pc->data[j+1].name)>0)
            {
                PeoInfo temp;
                temp = pc->data[j];
                pc->data[j] = pc->data[j+1];
                pc->data[j+1] = temp;
            }
        }
    }
    printf("排序完成\n");
    return;
	
}

void SaveContact(pContact pc)
{
	FILE* pfwrite = fopen(FILE_NAME,"w");
	int i = 0;
	if(NULL == pfwrite)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<pc->sz;i++)
	{
		fwrite(pc->data+i,sizeof(PeoInfo),1,pfwrite);
	}
	fclose(pfwrite);
}
