#include "main.h"

int ShowAll()//모든 제품 표시
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
    printf("\t|   제품종류        제품이름        제품가격  |\n");
    printf("\t|-------------------------------------------|\n");
    for (i = 0; (fread(&pros[i], sizeof(struct product), 1, fp)) != 0; i++)
    {
        printf("\t|%10s%10s%10s   |\n", pros[i].category, pros[i].name, pros[i].price);
    }
    //제품 정보를 살펴보고 파일에서 인쇄
    printf("\t--------------------------------------------------\n");

    printf("                        총 %d 개의 항목이 있습니다\n",i);
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    return i;
    //파일을 닫을 수 있는지 확인
}
void Add() //제품 정보 추가
{
    FILE *fp;
    int i = 0;
    int loop = 1; //루프가 설정되어 있는지 확인
    system("cls");

    do
    {
        printf("추가할 제품의 종류,이름,가격을 입력하시오: \n");
        scanf("%s%s%s", pros[i].category, pros[i].name, pros[i].price);
        //제품 정보 입력
        if ((fp = fopen("E:\information.txt", "ab")) == NULL)//이미 존재하는 이진파일을 쓰기모드로 열기
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
        printf("다른 제품 추가1, 메뉴로 돌아가기0");
        scanf("%d", &loop);
    } while (loop);
}

void Revise() //제품 정보 편집
{
    system("cls");
    FILE *fp;
    FILE *dfp;
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
    printf("편집하려는 항목의 이름을 입력하세요:\n");
    scanf("%s", name);
    while (fread(&pros[i], sizeof(struct product), 1, fp)!=0)//제품 정보를 검사
    {
        if (strcmp(name, pros[i].name) != 0) //편집할 제품 정보인지 확인
        {
            fwrite(&pros[i], sizeof(struct product), 1, dfp);
            i++;
            //새 파일로 수정할 필요가 없는 제품 정보 전달
        }
        else
        {
            rewind(fp); //파일 포인터를 초기화
            fseek(fp, sizeof(struct product)*(i + 1), 1);
            //항목을 삭제 한 후 파일 포인터를 놓습니다.
        }
    }
    if (fclose(fp))
    {
        printf("can not open the file\n");
        exit(0);
    }
    if (fclose(dfp))
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 닫을 수 있는지 확인
    remove("E:\information.txt");
    //원본 파일 삭제
    rename("E:\delete.txt", "E:\information.txt");
    //새로 만든 파일의 이름을 원래 파일 이름으로 바꿉니다.
    printf("새 제품의 정보를 입력하세요(종류,이름,가격)");
    scanf("%s%s%s", newpro.category, newpro.name, newpro.price);
    if ((fp = fopen("E:\information.txt", "ab")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if (fwrite(&newpro, sizeof(struct product), 1, fp) != 1)
        printf("제품 정보 수정 실패\n");
    else
        printf("제품 정보가 성공적으로 수정되었습니다.\n\n");

    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
}

void Delete() //제품 정보 삭제
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

    ShowAll(); //제품 목록 표시
    printf("삭제하려는 제품의 이름을 입력하세요:");
    scanf("%s", name);
    printf("제품을 제거하겠습니까?\n");
    printf("Y/N(1/0)\n");
    scanf("%d", &confirm);
    if (confirm == 1)
    {
        while (fread(&pros[i], sizeof(struct product), 1, fp) != 1) //제품 정보를 검사
        {
            if (strcmp(name, pros[i].name) != 0)
            {
                fwrite(&pros[i], sizeof(struct product), 1, dfp);
                i++;
                //새 파일로 삭제할 필요가 없는 제품 정보를 옮김
            }
            else
            {
                rewind(fp); //파일 포인터를 초기화
                fseek(fp, sizeof(struct product)*(i + 1), 0);
                //삭제할 제품의 다음 위치에 파일 포인터를 놓습니다.
            }
        }
        if (fclose(fp))
        {
            printf("can not close the file\n");
            exit(0);
        }
        if (fclose(fp))
        {
            printf("can not close the file\n");
            exit(0);
        }
        //파일을 닫을 수 있는지 확인
        remove("E:\information.txt");
        //원본 파일 삭제
        rename("E:\delete.txt", "E:\information.txt");
        //새로 만든 파일의 이름을 원래 파일 이름으로 변경
        printf("성공적으로 삭제되었습니다\n");
    }
    else
    {
        printf("\n\n삭제 취소\n\n");
    }
}

void Search()
{
    system("cls");
    int way;
    int i = 0;

    printf("\t -------------------------------------------\n");
    printf("\t|         원하는 방법을 선택하세요:           |\n");
    printf("\t|        1.종류로 검색하기                   |\n");
    printf("\t|        2.이름으로 검색하기                 |\n");
    printf("\t|-------------------------------------------|\n");
    scanf("%d", &way);
    switch (way)
    {
        case 1:searchbycategory();
            break;
        case 2:searchbyname();
            break;
        default:
            break;
    }
}

void searchbycategory()
{
    system("cls");
    int judge = 0;
    FILE* fp;
    int i = 0;
    char category[10];
    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("찾는 제품의 종류 입력");
    scanf("%s", category);
    for (i = 0; fread(&pros[i].category, sizeof(struct product), 1, fp) == 1; i++)
    {
        //파일에서 제품 정보를 읽는 알고리즘
        if (strcmp(category, pros[i].category) == 0)
        {
            judge = 1;
            printf("찾으신 제품 정보는 다음과 같습니다.\n");
            printf("%10s%10s%10s\n", pros[i].category, pros[i].name, pros[i].price);
        }
    }
    if (judge == 0)
    {
        printf("제품 정보를 찾을 수 없습니다\n");
    }
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
}
void searchbyname()
{
    system("cls");
    int judge = 0;
    FILE* fp;
    int i = 0;
    char name[10];
    if ((fp = fopen("E:\information.txt", "rb")) == NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //파일을 열 수 있는지 확인
    printf("찾는 제품의 이름 입력");
    scanf("%s", name);
    for (i = 0; fread(&pros[i].name, sizeof(struct product), 1, fp) == 1; i++)
    {
        //파일에서 제품 정보를 읽는 알고리즘
        if (strcmp(name, pros[i].name) == 0)
        {
            judge = 1;
            printf("찾으신 제품 정보는 다음과 같습니다.\n");
            printf("%10s%10s%10s\n", pros[i].category, pros[i].name, pros[i].price);
        }
    }
    if (judge == 0)
    {
        printf("제품 정보를 찾을 수 없습니다\n");
    }
    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
}