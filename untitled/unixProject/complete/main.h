#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFO_FILE "information.txt"
//dos창에선 utf-8로 설정해야 한글이 안깨짐 >chcp 65001
void mainmenu();
void showmenu0();
void CustomerMenu();
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
struct product
{
    char idx[20];
    char kind[20];
    char name[20];
    char price[20];
};//구조체
struct shoppinglist
{
    char idx[20];
    char kind[20];
    char name[20];
    char price[20];
    int num;
};
Enter
#define Enter 10
#define Tab 9
#define Space 32
extern char ID;
extern int back;
extern struct product pros[100];
extern int kind;
//전역변수
int convert(char num[]);
int GetCount(char *filename);
int GetLastIndex(char *filename);

void displayAdmin();
void displayCustomer();
void displayMainMenu();
int  displayAll();

void Add2();
void Search2();
void Revise2();
void Delete2();

void searchbyname2();
void searchbykind2();