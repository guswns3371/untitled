#include <stdio.h>
<<<<<<< Updated upstream
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
=======
#include <stdlib.h>
#include <string.h>

void mainmenu();
void showmenu0();
void showmenu1();
int  ShowAll();
//愿�由ъ옄,�냼鍮꾩옄 �븿�닔
>>>>>>> Stashed changes
void Add();
void Revise();
void Delete();
void Search();
void sort();
<<<<<<< Updated upstream
void turnover();
void searchbycategory();
void searchbyname();
//관리자함수
void Buy();
void Service();
void shoppingcar();
void accout();
//소비자 함수

int ID;
int back = 3;
//전역변수
struct product
{
	char category[10];
	char name[10];
	char price[10];
}pros[1000];
=======
void soldproducts();
void searchbycategory();
void searchbyname();
//愿�由ъ옄�븿�닔
void Buy();
void shoppingcart();
void account();
void receipt();
void sortbycategory();
void sortbyprice();
//�냼鍮꾩옄 �븿�닔

int ID;
int back;
//�쟾�뿭蹂��닔
struct product
{
    char idx[20];
    char kind[20];
    char name[20];
    char price[20];
}pros[100];
>>>>>>> Stashed changes
