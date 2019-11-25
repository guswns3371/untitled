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
    printf("\t|      모드를 먼저 선택하십시오     |\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t ----------------------------------\n");
    printf("   please choose your id(0대표 공급 업체，1소비자를 대신하여):");
    scanf("%d", &ID);
}
// 메인 메뉴 표시
void showmenu0()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to this machine    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|\t1-제품 정보 보기               |\n");//ShowAll();
    printf("\t|\t2-제품 추가하기               |\n");//Add();
    printf("\t|\t3-제품 정보 편집하기            |\n");//Revise();
    printf("\t|\t4-제품 삭제하기		          |\n");//Delete();
    printf("\t|\t5-제품 검색하기              |\n");//Search();
    printf("\t|\t6-판매 된 목록 및 매출보기    |\n");//turnover();
    printf("\t|\t7-종료                     |\n");//exit(0);
    printf("\t ----------------------------------\n");
    printf("\n      ENTER YOUR CHOICE(1-7):");
}
//관리자 메뉴 표시

void showmenu1()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to this machine    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|\t1-상품 구매                     |\n");//Buy();
    printf("\t|\t2-가격순으로 제품 보기           |\n");//sort();
    printf("\t|\t3-장바구니에 상품 추가           |\n");//shoppingcar();
    printf("\t|\t4-계산하기                      |\n");//account();
    printf("\t|\t5-종료                          |\n");//exit(0);
    printf("\t ----------------------------------\n");
    printf("\n      ENTER YOUR CHOICE(1-5):");
}
//소비자 메뉴 표시