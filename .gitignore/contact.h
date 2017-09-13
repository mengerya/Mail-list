#ifndef __CONTECT_H__
#define __CONTECT_H__
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define DEFAULT_SZ 2
#define DEFAULT_INC 2
#define FILE_NAME "contact.dat"
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;


typedef struct Contact
{
	PeoInfo *data;
	int sz;
	int capacity;
}Contact,*pContact;

void InitContact(pContact pc);//初始化
void AddContact(pContact pc);//添加联系人
void ShowContact(const pContact pc);//显示通讯录
void DelContact(pContact pc);//删除联系人
void SearchContact(const pContact pc);
void ModifyContact(pContact pc);
void EmptyContact(pContact pc);
void SortContact(pContact pc);
void Exit_con(pContact pc);
void CheckCapacity(pContact pc);
void DestroyContact(pContact pc);
void SaveContact(pContact pc);
void LoadContct(pContact pc);


#endif//__CONTECT_H__
