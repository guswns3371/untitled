#include "main.h"
void mainmenu()
{

    system("clear");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|     Welcome to McDonald (메인 메뉴)    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t|      모드를 먼저 선택하십시오     |\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t ----------------------------------\n");
    printf("\tAdmin 메뉴 0\n \t손님 메뉴 1 :");
    scanf("%d", &ID);
}
// 메인 메뉴 표시
void showmenu0()
{
    system("clear");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|     Welcome to McDonald (Admin 메뉴)     |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|\t1-제품 정보 보기               |\n");//ShowAll();
    printf("\t|\t2-제품 추가하기               |\n");//Add();
    printf("\t|\t3-제품 정보 편집하기            |\n");//Revise();
    printf("\t|\t4-제품 삭제하기		          |\n");//Delete();
    printf("\t|\t5-제품 검색하기              |\n");//Search();
    printf("\t|\t6-판매 된 목록 및 매출보기    |\n");//soldproducts();
    printf("\t|\t7-종료                     |\n");//exit(0);
    printf("\t ----------------------------------\n");
    printf("\n      ENTER YOUR CHOICE(1-7):");
}
//관리자 메뉴 표시

void showmenu1()
{
    system("clear");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to McDonald (손님 메뉴)    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|\t1-상품 구매                     |\n");//Buy();
    printf("\t|\t2-가격순으로 제품 보기           |\n");//sort();
    printf("\t|\t3-장바구니에 상품 추가           |\n");//shoppingcart();
    printf("\t|\t4-계산하기                      |\n");//account();
    printf("\t|\t5-종료                          |\n");//exit(0);
    printf("\t ----------------------------------\n");
    printf("\n      ENTER YOUR CHOICE(1-5):");
}
//소비자 메뉴 표시


/*************/

void displayMainMenu() {
    system("clear");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to McDonald (메인 메뉴)   |\n");
    printf("\t|---------------------------------|\n");

    printf("\tAdmin 메뉴 0\n \t손님 메뉴 1 :");
    scanf("%d", &ID);
}

void displayCustomer()
{
    system("clear");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to McDonald (손님 메뉴)   |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|\t1-전체 메뉴 보기            |\n");
    printf("\t|\t2-직접 상품 구매                |\n");
    printf("\t|\t3-Service                |\n");
    printf("\t|\t4-메뉴 검색              |\n");
    printf("\t|\t5-순서대로 제품 정보보기         |\n");
    printf("\t|\t6-장바구니에 상품 추가           |\n");
    printf("\t|\t7-장바구니에 상품을 정산하십시오  |\n");
    printf("\t|\t8-종료                          |\n");
    printf("\t ----------------------------------\n");
    printf("\n\t\t메뉴를 입력하세요 (1-6):");
}
//소비자 메뉴 표시

void displayAdmin()
{
    system("clear");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to McDonald (Admin 메뉴)   |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|\t1-전체 메뉴 보기        |\n");
    printf("\t|\t2-메뉴 추가                |\n");
    printf("\t|\t3-메뉴 수정           |\n");
    printf("\t|\t4-메뉴 삭제				 |\n");
    printf("\t|\t5-메뉴 검색           |\n");
    printf("\t|\t6-종료                    |\n");
    printf("\t ----------------------------------\n");
    printf("\n\t\t메뉴를 입력하세요 (1-6):");
}
//공급 업체 메뉴 표시

int displayAll()       //모든 제품 정보 표시
{
    system("clear");
    FILE *fp;
    int i;

    if ((fp = fopen(INFO_FILE, "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("\n\n\n\n\n");
    printf("\t -----------------------------------------------\n");
    printf("\t|   Welcome to McDonald                          |\n");
    printf("\t|  번호   종류            제품명           상품 가격   |\n");
    printf("\t|------------------------------------------------|\n");
    for (i = 0; (fread(&pros[i], sizeof(struct product), 1, fp)) != 0; i++)
    {
        printf("\t|%5s %8s%20s%20s   |\n", pros[i].idx,pros[i].kind, pros[i].name, pros[i].price);
    }
    //제품 정보를 살펴보고 파일에서 인쇄
    printf("\t -------------------------------------------\n\n\n");

    printf("           총 %d 개의 항목이 있습니다\n", i);
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }

    return i;
    //파일을 닫을 수 있는지 확인
}
