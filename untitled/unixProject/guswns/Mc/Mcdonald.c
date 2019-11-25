#include <stdio.h>
#include <string.h>
//#include <process.h>
#include <stdlib.h>

#define INFO_FILE "information.txt"
struct product
{
    char idx[20];
    char kind[20];
    char name[20];
    char price[20];
}pros[100];

int count = 0;
int ID;
int back;
int kind;
char kinds[3][10] ={"버거","사이드","음료"};
int convert(char num[]);
int GetNextIdx(char *filename);

void displayAdmin();
void displayCustomer();
void displayMainMenu();
void displayBurgerMenu();
void displayInput();
int  displayAll();

void Add2();
void Search2();
void Revise2();
void Delete2();


void shoppingcar();
void searchbyname();
void searchbykind();


int main()
{
    int n;
    char password[20];
    char *correctpassword = "123";
    backtoMainMenu:displayMainMenu();                         //메인 메뉴 표시

    if (ID == 0)
    {
        printf("\tAdmin 계정으로 들어가려면 비밀번호를 입력하십시오:\n");
        scanf("%s", password);
        //비밀번호 입력
        while (strcmp(password, correctpassword) != 0)
        {
            printf("\t비밀번호 입력이 잘못되었습니다. 다시 입력하십시오:\n");
            scanf("%s", password);
        }
        //올바른 비밀번호 결정

        backtoAdminMenu:displayAdmin();
        scanf("%d", &n);
        switch (n){
            case 1:displayAll();
                break;
            case 2:Add2();
                break;
            case 3:Revise2();
                break;
            case 4:Delete2();
                break;
            case 5:Search2();
                break;
            case 6:exit(0);
            default:break;
        }
    }
        //공급 업체 사이드 메뉴 표시
    else
    {
        backtoCustomerMenu: displayCustomer();
        scanf("%d", &n);
        switch (n){
            case 1:displayAll();
                break;
            case 2://Buy();
                break;
            case 3://Service();
                break;
            case 4:Search2();
                break;
            case 5://sort();
                break;
            case 6://shoppingcar();
                break;
            case 7://account();
                break;
            case 8:exit(0);
                break;
            default:break;
        }
    }
    //소비자 메뉴 표시
    printf("\n\n\n");
    printf("\t메인 메뉴로 돌아가기 0\n\tAdmin 메뉴로 돌아가기 1\n\t손님 메뉴로 돌아가기 2\n\t:");
    scanf("%d", &back);
    if (back == 0)
        goto backtoMainMenu;
    else if (back == 1)
        goto backtoAdminMenu;
    else if (back == 2)
        goto backtoCustomerMenu;

    return 0;
}

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

int GetNextIdx(char *filename)
{
    FILE *fpr;
    int j,i=0;
    if ((fpr = fopen(filename, "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    for (j = 0; (fread(&pros[i], sizeof(struct product), 1, fpr)) != 0; j++);

    if (fclose(fpr))
    {
        printf("can not close the file\n");
        exit(0);
    }
    return j;
}
void Add2()      //제품 정보 추가
{
    FILE *fp;
    int i = 0;
    int loop = 1;     //루프가 설정되어 있는지 확인
    system("clear");

    do
    {

        sprintf(pros[i].idx,"%d" ,GetNextIdx(INFO_FILE));//번호 지정
        printf("추가하려는 제품의 종류 \n버거 0\n사이드 1\n음료 2: ");
        scanf("%d",&kind);
        strcpy(pros[i].kind,kinds[kind]);
        printf("추가하려는 제품의 이름 : ");
        scanf("%s",pros[i].name);
        printf("추가하려는 제품의 가격 : ");
        scanf("%s",pros[i].price);
        //키보드에서 제품 정보 읽기

        if ((fp = fopen(INFO_FILE, "ab")) == NULL)
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
        printf("계속 입력하기 => 1 그만 입력하기 => 0 : ");
        scanf("%d", &loop);
    } while (loop);

}

void Revise2()
{
    system("clear");
    FILE *fp,*fp2;
    FILE *dfp,*dfp2;
    int i=0;
    char idx[20];
    struct product newpro;

    if ((fp = fopen(INFO_FILE, "rb+")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }

    if ((dfp = fopen("delete.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if ((dfp2 = fopen("delete2.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }

    displayAll();
    printf("편집하려는 제품의 번호을 입력하십시오:\n");
    scanf("%s", idx);

    int after =0;
    while (fread(&pros[i], sizeof(struct product), 1, fp))
    {
        if ((strcmp(idx, pros[i].idx) != 0) && (after ==0))
        {
            fwrite(&pros[i], sizeof(struct product), 1, dfp);
            i++;
        }
        else  if ((strcmp(idx, pros[i].idx) == 0) && (after ==0))
        {
            after =1;
        }
        else if ((strcmp(idx, pros[i].idx) != 0) && (after ==1))
        {
            fwrite(&pros[i], sizeof(struct product), 1, dfp2);
            i++;
        }
    }

    if (fclose(dfp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (fclose(dfp2))
    {
        printf("can not close the file\n");
        exit(0);
    }

    /***********/

    if ((fp2 = fopen("information0.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }

    printf("새로운 제품 정보를 입력하십시오\n");
    printf("새로운 제품의 종류 : ");
    scanf("%s",newpro.kind);
    printf("새로운 제품의 이름 : ");
    scanf("%s",newpro.name);
    printf("새로운 제품의 가격 : ");
    scanf("%s",newpro.price);
    sprintf(newpro.idx,"%d",GetNextIdx("delete.txt")); // 새제품의 idx


    if ((dfp = fopen("delete.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if ((dfp2 = fopen("delete2.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }

    i=0;
    while (fread(&pros[i], sizeof(struct product), 1, dfp))
    {
        fwrite(&pros[i], sizeof(struct product), 1, fp2);
        i++;
    }
    fwrite(&newpro, sizeof(struct product), 1, fp2);
    i=0;
    while (fread(&pros[i], sizeof(struct product), 1, dfp2))
    {
        fwrite(&pros[i], sizeof(struct product), 1, fp2);
        i++;
    }

    if (fclose(fp2))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (fclose(dfp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (fclose(dfp2))
    {
        printf("can not close the file\n");
        exit(0);
    }

    remove("delete.txt");
    remove("delete2.txt");
    rename("information0.txt",INFO_FILE);
    remove("information0.txt");

}
void Delete2()            //제품 정보 삭제
 {
    system("clear");
    FILE* fp;
    FILE* dfp;
    int i = 0;
    char idx[10];
    int confirm;

    if ((fp = fopen(INFO_FILE, "rb+")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if ((dfp = fopen("delete.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    displayAll();       //제품 목록 표시
    printf("삭제하려는 제품의 번호를 입력하십시오.:");
    scanf("%s", idx);
    printf("선택한 제품을 삭제하시겠습니까？\n");
    printf("돌아가기 0\n삭제하기 1 :\n");
    scanf("%d", &confirm);
    if (confirm == 1)
    {
        while (fread(&pros[i], sizeof(struct product), 1, fp))  //제품 정보를 순환
        {
            if (strcmp(idx, pros[i].idx) != 0)   //삭제할 제품 정보인지 판별하십시오.
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
        remove(INFO_FILE);
        //원본 파일 삭제
        rename("delete.txt", INFO_FILE);
        //새로 만든 파일의 이름을 원래 파일 이름으로 바꿉니다.
        printf("제품이 성공적으로 삭제되었습니다\n");
    }
    else
        printf("\n\n제품 삭제를 취소하였습니다\n");
}

void Search2()              //제품 정보 쿼리
{
    system("clear");
    int way;

    printf("원하는 방법을 선택하십시오：\n");
    printf("이름으로 검색 1\n");
    printf("종류로   검색 2:");
    scanf("%d", &way);
    switch (way)
    {
        case 1:searchbyname();
            break;
        case 2:searchbykind();
            break;
        default:break;
    }}

void searchbyname()
{
    int judge = 0;
    system("clear");
    FILE* fp;
    int i = 0;
    char name[10];
    if ((fp = fopen(INFO_FILE, "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("찾으려는 제품의 이름을 입력하세요：");
    scanf("%s", name);
    printf("\t -----------------------------------------------\n");
    printf("\t|   Welcome to McDonald                          |\n");
    printf("\t|  번호   종류            제품명           상품 가격   |\n");
    printf("\t|------------------------------------------------|\n");
    for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 0; i++)
    {
        //파일에서 제품 정보를 읽는 루프
        if (strstr(pros[i].name,name) != NULL )
        {
            judge = 1;
            printf("\t|%5s %8s%20s%20s   |\n", pros[i].idx,pros[i].kind, pros[i].name, pros[i].price);
        }
    }
    if (judge == 0)
    {
        printf("찾으려는 제품 정보를 찾을 수 없습니다\n");
    }
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
}
void searchbykind()
{
    int judge = 0;
    system("clear");
    FILE* fp;
    int i = 0;

    if ((fp = fopen(INFO_FILE, "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("찾으려는 제품의 종류를 입력하세요\n버거 0\n사이드 1\n음료 2：");
    scanf("%d", &kind);

    printf("\t -----------------------------------------------\n");
    printf("\t|   Welcome to McDonald                          |\n");
    printf("\t|  번호   종류            제품명           상품 가격   |\n");
    printf("\t|------------------------------------------------|\n");
    for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 0; i++)
    {
        //파일에서 제품 정보를 읽는 루프
        if (strcmp(kinds[kind], pros[i].kind) == 0)
        {
            judge = 1;
            printf("\t|%5s %8s%20s%20s   |\n", pros[i].idx,pros[i].kind, pros[i].name, pros[i].price);
        }
    }
    if (judge == 0)
    {
        printf("찾으려는 제품 정보를 찾을 수 없습니다\n");
    }
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
}