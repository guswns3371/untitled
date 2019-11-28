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
//°ü¸®ÀÚ,¼ÒºñÀÚ ÇÔ¼ö
=======
#include <stdlib.h>
#include <string.h>

void mainmenu();
void showmenu0();
void showmenu1();
int  ShowAll();
//ê´€ë¦¬ìž,ì†Œë¹„ìž í•¨ìˆ˜
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
//°ü¸®ÀÚÇÔ¼ö
void Buy();
void Service();
void shoppingcar();
void accout();
//¼ÒºñÀÚ ÇÔ¼ö

int ID;
int back = 3;
//Àü¿ªº¯¼ö
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
//ê´€ë¦¬ìží•¨ìˆ˜
void Buy();
void shoppingcart();
void account();
void receipt();
void sortbycategory();
void sortbyprice();
//ì†Œë¹„ìž í•¨ìˆ˜

int ID;
int back;
//ì „ì—­ë³€ìˆ˜
struct product
{
    char idx[20];
    char kind[20];
    char name[20];
    char price[20];
}pros[100];
>>>>>>> Stashed changes
