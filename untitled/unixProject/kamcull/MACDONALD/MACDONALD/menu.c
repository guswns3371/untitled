#include "main.h"
void mainmenu()
{

	system("cls");
	printf("\n\n\n\n\n");
	printf("\t ----------------------------------\n");
	printf("\t|      Welcome to this machine    |\n");
	printf("\t|---------------------------------|\n");
	printf("\t|                                 |\n");
	printf("\t|                                 |\n");
	printf("\t|      ��带 ���� �����Ͻʽÿ�     |\n");
	printf("\t|                                 |\n");
	printf("\t|                                 |\n");
	printf("\t ----------------------------------\n");
	printf("   please choose your id(0��ǥ ���� ��ü��1�Һ��ڸ� ����Ͽ�):");
	scanf("%d", &ID);
}
// ���� �޴� ǥ��
void showmenu0()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t ----------------------------------\n");
	printf("\t|      Welcome to this machine    |\n");
	printf("\t|---------------------------------|\n");
	printf("\t|\t1-��ǰ ���� ����               |\n");//ShowAll();
	printf("\t|\t2-��ǰ �߰��ϱ�               |\n");//Add();
	printf("\t|\t3-��ǰ ���� �����ϱ�            |\n");//Revise();
	printf("\t|\t4-��ǰ �����ϱ�		          |\n");//Delete();
	printf("\t|\t5-��ǰ �˻��ϱ�              |\n");//Search();
	printf("\t|\t6-�Ǹ� �� ��� �� ���⺸��    |\n");//soldproducts();
	printf("\t|\t7-����                     |\n");//exit(0);
	printf("\t ----------------------------------\n");
	printf("\n      ENTER YOUR CHOICE(1-7):");
}
//������ �޴� ǥ��

void showmenu1()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t ----------------------------------\n");
	printf("\t|      Welcome to this machine    |\n");
	printf("\t|---------------------------------|\n");
	printf("\t|\t1-��ǰ ����                     |\n");//Buy();
	printf("\t|\t2-���ݼ����� ��ǰ ����           |\n");//sort();
	printf("\t|\t3-��ٱ��Ͽ� ��ǰ �߰�           |\n");//shoppingcart();
	printf("\t|\t4-����ϱ�                      |\n");//account();
	printf("\t|\t5-����                          |\n");//exit(0);
	printf("\t ----------------------------------\n");
	printf("\n      ENTER YOUR CHOICE(1-5):");
}
//�Һ��� �޴� ǥ��