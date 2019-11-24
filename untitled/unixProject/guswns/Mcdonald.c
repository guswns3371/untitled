#include <stdio.h>
#include <string.h>
//#include <process.h>
#include <stdlib.h>
struct product
{
    char name[10];
    char price[10];
}pros[100];
int count = 0;
int ID;
int back = 3;
int convert(char num[]);

void displayMainMenu();
void displayBurgerMenu();
void displayInput();

int  displayAll();
void Add();
void Search();
void Buy();
void shoppingcar();

void searchbyname();
void searchbysize();


int main()
{

}

void displayMainMenu() {
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to McDonald    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t|      신분을 먼저 선택하십시오   |\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t ----------------------------------\n");
    printf("   0(대표 공급 업체)，1(소비자):");
    scanf("%d", &ID);
}