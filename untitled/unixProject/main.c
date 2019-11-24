#include <stdio.h>
#include <string.h>
//#include <process.h>
#include <stdlib.h>

struct product
{
    char name[10];
    char color[10];
    char size[10];
    char price[10];
}pros[1000];
int count = 0;
int ID;
int convert(char num[]);
int back = 3;
void mainmenu();
void showmenu1();
void showmenu0();
int  ShowAll();
void Add();
void Revise();
void Delete();
void Search();
void Buy();
void Service();
void sort();
void sortbyprice();
void sortbysize();
void searchbycolor();
void searchbyname();
void searchbysize();
void turnover();
void shoppingcar();
void account();
void deletes(char name[]);

int main()
{
    int n;
    char password[20];
    char *correctpassword = "123456";
    backtomain:mainmenu();                         //메인 메뉴 표시

    if (ID == 0)
    {
        printf("제품 관리 권한을 얻으려면 비밀번호를 입력하십시오:\n");
        scanf("%s", password);
        //비밀번호 입력
        while (strcmp(password, correctpassword) != 0)
        {
            printf("비밀번호 입력이 잘못되었습니다. 다시 입력하십시오:\n");
            scanf("%s", password);
        }
        //올바른 비밀번호 결정

        backtomenu0:showmenu0();
        scanf("%d", &n);
        // while(n)
        //   {
        switch (n){
            case 1:ShowAll();
                break;
            case 2:Add();
                break;
            case 3:Revise();
                break;
            case 4:Delete();
                break;
            case 5:Search();
                break;
            case 6:sort();
                break;
            case 7:turnover();
                break;
            case 8:exit(0);
            default:break;
        }
        // scanf("%d",&n);
        // }
    }
        //공급 업체 사이드 메뉴 표시
    else
    {
        backtomenu1:  showmenu1();
        scanf("%d", &n);
        //   while(n)
        // {
        switch (n){
            case 1:ShowAll();
                break;
            case 2:Buy();
                break;
            case 3:Service();
                break;
            case 4:Search();
                break;
            case 5:sort();
                break;
            case 6:shoppingcar();
                break;
            case 7:account();
                break;
            case 8:exit(0);
                break;
            default:break;
        }
        //}
    }
    //소비자 메뉴 표시
    printf("\n\n\n");
    printf("다음으로 메인 메뉴로 돌아갑니다0,공급자 버튼으로 돌아 가기1,소비자 버튼으로 돌아 가기2： ");
    scanf("%d", &back);
    if (back == 0)
        goto backtomain;
    else if (back == 1)
        goto backtomenu0;
    else if (back == 2)
        goto backtomenu1;

    return 0;
}


void mainmenu()
{

    system("cls");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to this machine    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t|      신분을 먼저 선택하십시오   |\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t ----------------------------------\n");
    printf("   please choose your id(0대표 공급 업체，1소비자를 대신하여):");
    scanf("%d", &ID);
}
// 메인 메뉴 표시



void showmenu1()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to this machine    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|\t1-모든 제품 정보 표시            |\n");
    printf("\t|\t2-직접 상품 구매                |\n");
    printf("\t|\t3-판매 서비스 후                |\n");
    printf("\t|\t4-제품 정보 쿼리                |\n");
    printf("\t|\t5-순서대로 제품 정보보기         |\n");
    printf("\t|\t6-장바구니에 상품 추가           |\n");
    printf("\t|\t7-장바구니에 상품을 정산하십시오  |\n");
    printf("\t|\t8-출구                          |\n");
    printf("\t ----------------------------------\n");
    printf("\n      ENTER YOUR CHOICE(1-6):");
}
//소비자 메뉴 표시



void showmenu0()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to this machine    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|\t1-모든 제품 정보 표시        |\n");
    printf("\t|\t2-선반에                |\n");
    printf("\t|\t3-제품 정보 편집            |\n");
    printf("\t|\t4-품절				 |\n");
    printf("\t|\t5-제품 정보 쿼리            |\n");
    printf("\t|\t6-순서대로 제품 정보보기        |\n");
    printf("\t|\t7-판매 된 목록 및 매출보기    |\n");
    printf("\t|\t8-출구                    |\n");
    printf("\t ----------------------------------\n");
    printf("\n      ENTER YOUR CHOICE(1-6):");
}
//공급 업체 메뉴 표시



int ShowAll()       //모든 제품 정보 표시
{
    system("cls");
    FILE *fp;
    int i;

    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("\n\n\n\n\n");
    printf("\t -------------------------------------------\n");
    printf("\t|          Welcome to this machine          |\n");
    printf("\t|   제품명   제품 색상   제품 크기  상품 가격|\n");
    printf("\t|-------------------------------------------|\n");
    for (i = 0; (fread(&pros[i], sizeof(struct product), 1, fp)) != 0; i++)
    {
        printf("\t|%10s%10s%10s%10s   |\n", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
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



void Add()      //제품 정보 추가
{
    FILE *fp;
    int i = 0;
    int loop = 1;     //루프가 설정되어 있는지 확인
    system("cls");

    do
    {
        printf("선반에 항목 이름을 입력하십시오，색깔，크기와 가격：");
        scanf("%s%s%s%s", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
        //키보드에서 제품 정보 읽기
        if ((fp = fopen("E:\information.txt", "ab")) == NULL)
        {
            printf("can not open the file\n");
            exit(0);
        }
        //파일을 열 수 있는지 확인
        if (fwrite(&pros[i], sizeof(struct product), 1, fp) != 1)
            printf("file write error\n");
        //배열의 항목 정보를 파일에 씁니다.，그리고 쓰기 성공 여부를 결정
        if (fclose(fp))
        {
            printf("can not close the file\n");
            exit(0);
        }
        //파일을 닫을 수 있는지 확인
        printf("계속 입력：(계속 눌러1，눌러 중지)");
        scanf("%d", &loop);
        //if(loop==0)
        //back=1;
        //순환을 계속할지 결정
    } while (loop);

}



void Revise()        //제품 정보 편집
{
    system("cls");
    FILE* fp;
    FILE* dfp;
    int i = 0;
    int j;
    char name[10];
    struct product newpro;

    if ((fp = fopen("E:\information.txt", "rb+")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if ((dfp = fopen("E:\delete.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }

    ShowAll();
    printf("정보를 편집하려는 항목의 이름을 입력하십시오.:\n");
    scanf("%s", name);
    while (fread(&pros[i], sizeof(struct product), 1, fp))  //제품 정보를 순환
    {
        if (strcmp(name, pros[i].name) != 0)   //수정 될 제품 정보인지 확인
        {
            fwrite(&pros[i], sizeof(struct product), 1, dfp);
            i++;
            //새 파일로 수정할 필요가없는 제품 정보 작성
        }
        else
        {
            rewind(fp);  //파일 포인터를 처음으로 재설정
            fseek(fp, sizeof(struct product)*(i + 1), 1);
            //항목을 삭제 한 후 파일 포인터를 놓습니다.
            //fseek(fp,0,1);
        }
    }

    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (fclose(dfp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
    remove("e:\information.txt");
    //원본 파일 삭제
    rename("e:\delete.txt", "e:\information.txt");
    //새로 만든 파일의 이름을 원래 파일 이름으로 바꿉니다.
    printf("새로운 제품 정보를 입력하십시오(이름,색깔,크기와 가격): ");
    scanf("%s%s%s%s", newpro.name, newpro.color, newpro.size, newpro.price);
    if ((fp = fopen("E:\information.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if (fwrite(&newpro, sizeof(struct product), 1, fp) != 1)
        printf("제품 정보 수정 실패\n");
    else
        printf("제품 정보가 성공적으로 수정되었습니다\n\n");

    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
}



void Delete()            //제품 정보 삭제
{
    system("cls");
    FILE* fp;
    FILE* dfp;
    int i = 0;
    int j;
    char name[10];
    int judge = 0;
    int confirm;

    if ((fp = fopen("E:\information.txt", "rb+")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if ((dfp = fopen("E:\delete.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    ShowAll();       //제품 목록 표시
    printf("삭제하려는 항목의 이름을 입력하십시오.:");
    scanf("%s", name);
    printf("항목을 제거하십시오？\n");
    printf("1을 눌러 확인，취소하려면 0을 누르십시오\n");
    scanf("%d", &confirm);
    if (confirm == 1)
    {
        while (fread(&pros[i], sizeof(struct product), 1, fp))  //제품 정보를 순환
        {
            if (strcmp(name, pros[i].name) != 0)   //삭제할 제품 정보인지 판별하십시오.
            {
                fwrite(&pros[i], sizeof(struct product), 1, dfp);
                i++;
                //새 파일로 삭제할 필요가없는 제품 정보를 작성하십시오
            }
            else
            {
                rewind(fp);  //파일 포인터를 처음으로 재설정
                fseek(fp, sizeof(struct product)*(i + 1), 0);
                //항목을 삭제 한 후 파일 포인터를 놓습니다.
                // fseek(fp,sizeof(struct product),1);
                // fseek(fp,0,1);
            }
        }
        if (fclose(fp))
        {
            printf("can not close the file\n");
            exit(0);
        }
        if (fclose(dfp))
        {
            printf("can not close the file\n");
            exit(0);
        }
        //파일을 닫을 수 있는지 확인
        remove("e:\information.txt");
        //원본 파일 삭제
        rename("e:\delete.txt", "e:\information.txt");
        //새로 만든 파일의 이름을 원래 파일 이름으로 바꿉니다.
        printf("제품이 성공적으로 판매되었습니다！\n");
    }
    else
        printf("\n\n취소 된 항목 제거\n");
}


void Search()              //제품 정보 쿼리
{
    system("cls");
    int way;
    FILE* fp;
    int i = 0;

    //파일을 열 수 있는지 확인
    printf("원하는 방법을 선택하십시오：\n");
    printf("이름으로 검색하세요1，");
    printf("색상을 눌러 찾으십시오.2，");
    printf("크기로 검색하세요3");
    scanf("%d", &way);
    switch (way)
    {
        case 1:searchbyname();
            break;
        case 2:searchbycolor();
            break;
        case 3:searchbysize();
            break;
        default:break;
    }
}

void searchbyname()
{
    int judge = 0;     //判断是否查询到的中间变量
    system("cls");
    FILE* fp;
    int i = 0;
    char name[10];
    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("중간 변수가 쿼리되는지 확인：");
    scanf("%s", name);
    for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 0; i++)
    {
        //파일에서 제품 정보를 읽는 루프
        if (strcmp(name, pros[i].name) == 0)
        {
            judge = 1;
            printf("찾고있는 제품 정보는 다음과 같습니다.：\n");
            printf("%10s%10s%10s%10s\n", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
        }
    }
    if (judge == 0)
    {
        printf("미안，제품 정보를 찾을 수 없습니다\n");
    }
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
}

void searchbycolor()
{
    int judge = 0;     //중간 변수가 쿼리되는지 확인
    system("cls");
    FILE* fp;
    int i = 0;
    char color[10];
    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("확인하려는 항목의 색상을 입력하십시오.：");
    scanf("%s", color);
    for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 0; i++)
    {
        //파일에서 제품 정보를 읽는 루프
        if (strcmp(color, pros[i].color) == 0)
        {
            judge = 1;
            printf("찾고있는 제품 정보는 다음과 같습니다.：\n");
            printf("%10s%10s%10s%10s\n", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
        }
    }
    if (judge == 0)
    {
        printf("미안，제품 정보를 찾을 수 없습니다\n");
    }
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
}



void searchbysize()
{

    int judge = 0;     //중간 변수가 쿼리되는지 확인
    system("cls");
    FILE* fp;
    int i = 0;
    char size[10];
    int low;
    int mid;
    int high;
    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("확인하려는 항목의 크기를 입력하십시오.：");
    scanf("%s", size);
    int j;
    int n;
    int k1;
    int k2;
    struct product temp;

    n = ShowAll();
    low = 0;
    high = n - 1;
    printf("위의 원래 제품 정보\n\n\n");
    while (fread(&pros[i], sizeof(struct product), 1, fp) != 0)
    {
        i++;
    }
    //파일에서 제품 정보 읽기
    for (i = 0; i<n - 1; i++)
    {
        for (j = 0; j<n - 1 - i; j++)
        {
            k1 = convert(pros[j].size);
            k2 = convert(pros[j + 1].size);
            //문자열에서 정수로 항목 크기 변환
            if (k1>k2)
            {
                temp = pros[j + 1];
                pros[j + 1] = pros[j];
                pros[j] = temp;
                //인접한 제품 위치 교환
            }
        }
    }
    //거품 정렬을 사용하여 크기별로 항목 정렬

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (convert(pros[mid].size) == convert(size))
        {
            judge = 1;
            printf("성공 찾기，이 상품은%s  %s  %s  %s\n", pros[mid].name, pros[mid].color, pros[mid].size, pros[mid].price);
        }
        if (convert(size)>convert(pros[mid].size))
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (judge == 0)
    {
        printf("입력 한 항목을 찾을 수 없습니다\n");
    }




    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
}

void Buy()              //상품 구매
{
    system("cls");
    FILE *fp;
    FILE *newfp;
    FILE *dfp;
    char buyname[10];
    char buycolor[10];
    char buysize[10];
    int money;            //지불 금액
    int change;           //금액 변경
    int prices;           //실제 가격
    int judge = 0;
    int i = 0;

    ShowAll();
    printf("구매하려는 품목의 이름을 입력하십시오：");
    scanf("%s", buyname);
    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if ((newfp = fopen("E:\soldlist.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    for (i = 0; judge != 1; i++)
    {
        fread(&pros[i], sizeof(struct product), 1, fp);
        //파일이 완료 될 때까지 파일에서 제품 정보를 순환하십시오.
        if ((strcmp(buyname, pros[i].name) == 0))
        {
            if (fwrite(&pros[i], sizeof(struct product), 1, newfp) != 1)
                printf("file write error\n");
            judge = 1;
            printf("제품 가격은 %s입니다. 지폐를 넣으십시오.\n", pros[i].price);
            printf("받았습니다:");
            scanf("%d", &money);      //지불 금액을 입력하십시오
            prices = convert(pros[i].price);     //문자열에서 정수로 가격 변환
            change = money - prices;       //변화량 계산

            if (change >= 0)
                printf("구매해 주셔서 감사합니다，% d 위안 찾기n", change);
            else
            {
                printf("% d 위안 부족합니다.\n계속 지불하십시오\n", -change);
                printf("받았습니다:");
                scanf("%d", &money);
                change = money + change;
                printf("구입해 주셔서 감사합니다. % d 위안을 찾으십시오.\n", change);
            }

            //지불 금액이 충분한 지 확인
        }
    }
    i = 0;
    if ((dfp = fopen("E:\delete.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    while (fread(&pros[i], sizeof(struct product), 1, fp))  //제품 정보를 순환
    {
        if (strcmp(buyname, pros[i].name) != 0)   //삭제할 제품 정보인지 판별하십시오.
        {
            fwrite(&pros[i], sizeof(struct product), 1, dfp);
            i++;
            //새 파일로 삭제할 필요가없는 제품 정보를 작성하십시오
        }
        else
        {
            rewind(fp);  //파일 포인터를 처음으로 재설정
            fseek(fp, sizeof(struct product)*(i + 1), 0);
            //항목을 삭제 한 후 파일 포인터를 놓습니다.
            // fseek(fp,sizeof(struct product),1);
            //fseek(fp,0,1);
        }
    }

    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (fclose(dfp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
    remove("e:\information.txt");
    //원본 파일 삭제
    rename("e:\delete.txt", "e:\information.txt");
    //새로 만든 파일의 이름을 원래 파일 이름으로 바꿉니다.
    printf("제품 구매 성공！\n");
    if (fclose(newfp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (judge == 0)
        printf("구매하려는 상품이 없습니다\n");
}


void Service()            //소비자 피드백
{
    FILE *fp;
    char name[10];
    int like;
    int n;
    int i = 0;
    struct product temp;

    system("cls");
    n = ShowAll();
    printf("\n\n검토 할 제품 이름을 입력하십시오：");
    scanf("%s", name);
    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("\n\n당신의 평가를 적어주세요（찬양1，나쁜 검토0）：");
    scanf("%d", &like);
    while (fread(&pros[i], sizeof(struct product), 1, fp) != 0)
    {
        i++;
    }
    //파일에서 제품 정보 읽기
    for (i = 0; i<n; i++)
    {
        if (strcmp(name, pros[i].name) == 0)
            break;
    }
    //원래 목록에서 검토하려는 항목의 위치를 찾으십시오.
    if (like == 1)
    {
        temp = pros[i];
        pros[i] = pros[0];
        pros[0] = temp;
    }
        //평가 항목을 첫 번째 항목 위치로 교체
    else
    {
        temp = pros[n - 1];
        pros[n - 1] = pros[i];
        pros[i] = temp;
    }
    //평가 항목을 마지막 항목 위치로 교체
    printf("평가 성공\n\n");
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    printf("\n\n\n\n\n");
    printf("\t -------------------------------------------\n");
    printf("\t|          Welcome to this machine          |\n");
    printf("\t|     제품이름 제품색상 제품크기 제품가격      |\n");
    printf("\t|-------------------------------------------|\n");
    for (i = 0; i<n; i++)
    {
        printf("\t|%10s%10s%10s%10s   |\n", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
    }
    //제품 정보를 살펴보고 파일에서 인쇄
    printf("\t -------------------------------------------\n\n\n");

}

void sort()
{
    system("cls");
    int way;
    system("cls");
    printf("\n\n정렬 방법을 선택하십시오：\n");
    printf("가격 오름차순을 눌러주십시오1，크기별로 오름차순으로 누르십시오2：");
    scanf("%d", &way);
    switch (way)
    {
        case 1:sortbyprice();
            break;
        case 2:sortbysize();
            break;
        default:break;
    }
}

void sortbyprice()
{
    FILE *fp;
    int i = 0;
    int j;
    int n;
    int k1;
    int k2;
    struct product temp;

    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    n = ShowAll();
    printf("위의 원래 제품 정보\n\n\n");
    while (fread(&pros[i], sizeof(struct product), 1, fp) != 0)
    {
        i++;
    }
    //파일에서 제품 정보 읽기
    for (i = 0; i<n - 1; i++)
    {
        for (j = 0; j<n - 1 - i; j++)
        {
            k1 = convert(pros[j].price);
            k2 = convert(pros[j + 1].price);
            //아이템 가격을 문자열에서 정수로 변환
            if (k1>k2)
            {
                temp = pros[j + 1];
                pros[j + 1] = pros[j];
                pros[j] = temp;
                //인접한 제품 위치 교환
            }
        }
    }
    //버블 정렬을 사용하여 가격별로 품목 정렬
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
    printf("\n\n\n\n\n");
    printf("\t -------------------------------------------\n");
    printf("\t|          Welcome to this machine          |\n");
    printf("\t|     제품이름 제품색상 제품크기 제품가격      |\n");
    printf("\t|-------------------------------------------|\n");
    for (i = 0; i<n; i++)
    {
        printf("\t|%10s%10s%10s%10s   |\n", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
    }
    //제품 정보를 살펴보고 파일에서 인쇄
    printf("\t -------------------------------------------\n\n\n");
    //정렬 후 모든 제품 정보 인쇄
    printf("\n\n낮은 가격에서 높은 가격으로 항목을 정렬\n");
}

void sortbysize()
{
    FILE *fp;
    int i = 0;
    int j;
    int n;
    int k1;
    int k2;
    struct product temp;

    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    n = ShowAll();
    printf("위의 원래 제품 정보\n\n\n");
    while (fread(&pros[i], sizeof(struct product), 1, fp) != 0)
    {
        i++;
    }
    //파일에서 제품 정보 읽기
    for (i = 0; i<n - 1; i++)
    {
        for (j = 0; j<n - 1 - i; j++)
        {
            k1 = convert(pros[j].size);
            k2 = convert(pros[j + 1].size);
            //문자열에서 정수로 항목 크기 변환
            if (k1>k2)
            {
                temp = pros[j + 1];
                pros[j + 1] = pros[j];
                pros[j] = temp;
                //인접한 제품 위치 교환
            }
        }
    }
    //거품 정렬을 사용하여 크기별로 항목 정렬
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
    printf("\n\n\n\n\n");
    printf("\t -------------------------------------------\n");
    printf("\t|          Welcome to this machine          |\n");
    printf("\t|     제품이름 제품색상 제품크기 제품가격      |\n");
    printf("\t|-------------------------------------------|\n");
    for (i = 0; i<n; i++)
    {
        printf("\t|%10s%10s%10s%10s   |\n", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
    }
    //제품 정보를 살펴보고 파일에서 인쇄
    printf("\t -------------------------------------------\n\n\n");
    printf("\n\n크기를 기준으로 낮음에서 높음으로 항목 정렬\n");
}


void turnover()
{
    system("cls");
    FILE *fp;
    int i;
    int sum = 0;
    int money;

    if ((fp = fopen("E:\soldlist.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("판매되는 상품은 다음과 같습니다：\n");
    printf("\n\n\n\n\n");
    printf("\t -------------------------------------------\n");
    printf("\t|          Welcome to this machine          |\n");
    printf("\t|     제품이름 제품색상 제품크기 제품가격      |\n");
    printf("\t|-------------------------------------------|\n");
    for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 0; i++)
    {
        printf("\t|%10s%10s%10s%10s   |\n", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
        money = convert(pros[i].price);
        sum = sum + money;
    }
    //제품 정보를 읽고 매출 합계 계산
    printf("\t -------------------------------------------\n\n\n");
    printf("\n\n현재 총 회전율은 %d입니다.\n", sum);
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
}

void shoppingcar()
{
    FILE *sfp;
    FILE *fp;
    int n;
    int i = 0;
    int judge = 0;
    system("cls");
    n = ShowAll();
    char name[10];
    int loop = 1;
    if ((sfp = fopen("E:\shoppingcar.txt", "ab")) == NULL)
    {
        printf("can not open the file");
        exit(0);
    }
    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    while ((fread(&pros[i], sizeof(struct product), 1, fp)) != 0)
    {
        i++;
    }
    //제품 정보를 순환
    do
    {
        printf("\n\n장바구니에 추가 할 품목의 이름을 입력하십시오.：");
        scanf("%s", name);
        for (i = 0; judge != 1; i++)
        {
            if (strcmp(name, pros[i].name) == 0)
            {
                judge = 1;
                fwrite(&pros[i], sizeof(struct product), 1, sfp);
            }
            else
                continue;
        }
        //항목을 찾아 파일에 씁니다.
        printf("계속 추가하고 1을 누르고 추가를 중단하고 0을 누릅니다.：");
        scanf("%d", &loop);
        judge = 0;
    } while (loop);

    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
    if (fclose(sfp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
}


void account()       //결제 쇼핑 카트
{
    FILE *sfp;
    FILE *fp;
    int i;
    int sum = 0;
    int price;
    int money;
    int change;
    int j;
    system("cls");
    if ((sfp = fopen("E:\shoppingcar.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if ((fp = fopen("E:\soldlist.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    printf("\n\n\n\n\n");
    printf("\t -------------------------------------------\n");
    printf("\t|          Welcome to this machine          |\n");
    printf("\t|     제품이름 제품색상 제품크기 제품가격      |\n");
    printf("\t|-------------------------------------------|\n");
    for (i = 0; (fread(&pros[i], sizeof(struct product), 1, sfp)) != 0; i++)
    {
        price = convert(pros[i].price);
        sum = sum + price;
        printf("\t|%10s%10s%10s%10s   |\n", pros[i].name, pros[i].color, pros[i].size, pros[i].price);
    }
    //제품 정보를 살펴보고 파일에서 인쇄
    printf("\t -------------------------------------------\n\n\n");
    printf("           장바구니에 총 %d 개의 항목이 있습니다.\n", i);
    printf("           %d 위안을 지불하십시오\n", sum);
    printf("           받았습니다：");
    scanf("%d", &money);
    loop:change = money - sum;
    if (change >= 0)
    {
        printf("  구매 성공, %d 위안 찾기\n", change);

    }
    else
    {
        printf("구매 실패, %d 위안을 계속 지불하십시오", -change);
        printf("받았습니다：");
        scanf("%d", &money);
        sum = -change;
        goto loop;
    }
    for (j = 0; j<i; j++)
    {
        fwrite(&pros[j], sizeof(struct product), 1, fp);
        //shoppingcar 파일에서 soldlist 파일로 데이터 쓰기
        deletes(pros[j].name);
        //shoppingcar를 사용하여 정보 파일의 일치 부분을 삭제하십시오.
    }

    if (fclose(sfp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    remove("E:\shoppingcar.txt");
}

void deletes(char name[])
{
    FILE* fps;
    FILE* dfps;
    int i = 0;
    int j;
    int judge = 0;
    int confirm;
    struct product products[50];

    if ((fps = fopen("E:\information.txt", "rb+")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if ((dfps = fopen("E:\delete.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인

    while (fread(&products[i], sizeof(struct product), 1, fps))  //제품 정보를 순환
    {
        if (strcmp(name, products[i].name) != 0)   //삭제할 제품 정보인지 판별하십시오.
        {
            fwrite(&products[i], sizeof(struct product), 1, dfps);
            i++;
            //새 파일로 삭제할 필요가없는 제품 정보를 작성하십시오
        }
        else
        {
            rewind(fps);  //파일 포인터를 처음으로 재설정
            fseek(fps, sizeof(struct product)*(i + 1), 0);
            //항목을 삭제 한 후 파일 포인터를 놓습니다.
            // fseek(fp,sizeof(struct product),1);
            // fseek(fp,0,1);
        }
    }
    if (fclose(fps))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (fclose(dfps))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
    remove("E:\information.txt");
    //원본 파일 삭제
    rename("E:\delete.txt", "E:\information.txt");
    //새로 만든 파일의 이름을 원래 파일 이름으로 바꿉니다.
}


int convert(char num[])         //문자열 형태의 숫자를 정수로 변환
{
    int a, b, c, e;
    int sum = 0;
    int d = 1;
    int i, j;
    c = strlen(num);      //문자열의 길이, 즉 자릿수를 찾습니다
    e = c;
    for (i = 0; i<c; i++)
    {
        b = num[i] - 48;     //ASCII에서 정수로 숫자 변환
        d = 1;
        for (j = 1; j<e; j++)
        {
            d = d * 10;     //자릿수에 곱하고 더하기
        }
        e--;
        sum = sum + b*d;
    }
    return sum;         //최종 변환 결과를 반환
}