#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFO_FILE "information.txt"

void mainmenu();
void showmenu0();
void showmenu1();
int  ShowAll();
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
void shoppingcart();
void account();
void receipt();
void sortbycategory();
void sortbyprice();
//소비자 함수

int ID;
int back;
//전역변수
struct product
{
    char idx[20];
    char kind[20];
    char name[20];
    char price[20];
}pros[100];

int kind;