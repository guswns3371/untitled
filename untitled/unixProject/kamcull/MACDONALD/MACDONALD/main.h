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
//관리자,소비자 함수
void Add();
void Revise();
void Delete();
void Search();
void sort();
void soldproducts();
void searchbycategory();
void searchbyname();
//관리자함수
void Buy();
void Service();
void shoppingcart();
void accout();
void receipt();
void sortbycategory();
void sortbyprice();
//소비자 함수

int ID;
int back = 3;
//전역변수
struct product
{
	char* index;
	char category[10];
	char name[10];
	char* price;
}pros[100];