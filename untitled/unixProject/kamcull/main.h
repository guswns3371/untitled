#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>

void menu();
void showmenu0();
void showmenu1();
int  ShowAll();
void Search();
void sort();
//������,�Һ��� �Լ�
void Add();
void Revise();
void Delete();
void Search();
void sort();
void turnover();
void searchbycategory();
void searchbyname();
//�������Լ�
void Buy();
void Service();
void shoppingcar();
void accout();
//�Һ��� �Լ�

int ID;
int back = 3;
//��������
struct product
{
	char category[10];
	char name[10];
	char price[10];
}pros[1000];