#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>

void mainmenu();
void showmenu0();
void showmenu1();
int  ShowAll();
//������,�Һ��� �Լ�
void Add();
void Revise();
void Delete();
void Search();
void sort();
void soldproducts();
void searchbycategory();
void searchbyname();
//�������Լ�
void Buy();
void shoppingcart();
void account();
void receipt();
void sortbycategory();
void sortbyprice();
//�Һ��� �Լ�

int ID;
int back = 3;
//��������
struct product
{
	char* index;
	char category[10];
	char name[10];
	char* price;
}pros[100];