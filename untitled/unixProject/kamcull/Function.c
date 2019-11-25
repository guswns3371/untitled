#include "main.h"

int ShowAll()//모든 제품 표시
{
<<<<<<< Updated upstream
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
=======
	system("clear");
	FILE *fp;
	int i;

	if ((fp = fopen("information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//파일을 열 수 있는지 확인
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|  번호   제품종류       제품이름       제품가격  |\n");
	printf("\t|-------------------------------------------|\n");
	for (i = 0; (fread(&pros[i], sizeof(struct product), 1, fp)) != 0; i++)
	{
		printf("\t|%20s%20s%20s%20s   |\n",pros[i].idx,pros[i].kind, pros[i].name, pros[i].price);
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
	system("clear");

	do
	{
		printf("추가할 제품의 번호 종류,이름,가격을 입력하시오: \n");
		scanf("%s%s%s%s",pros[i].idx, pros[i].kind, pros[i].name, pros[i].price);
		//제품 정보 입력
		if ((fp = fopen("information.txt", "ab")) == NULL)//이미 존재하는 이진파일을 쓰기모드로 열기
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
>>>>>>> Stashed changes
}

void Revise() //제품 정보 편집
{
<<<<<<< Updated upstream
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
=======
	system("clear");
	FILE *fp;
	FILE *dfp;
	int i = 0;
	char name[20];
	struct product newpro;

	if ((fp = fopen("information.txt", "rb+")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	if ((dfp = fopen("delete.txt", "ab")) == NULL)
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
	remove("information.txt");
	//원본 파일 삭제
	rename("delete.txt", "information.txt");
	//새로 만든 파일의 이름을 원래 파일 이름으로 바꿉니다.
	printf("새 제품의 정보를 입력하세요(종류,이름,가격)");
	scanf("%s%s%s", newpro.kind, newpro.name, newpro.price);
	if ((fp = fopen("information.txt", "ab")) == NULL)
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
>>>>>>> Stashed changes
}

void Delete() //제품 정보 삭제
{
<<<<<<< Updated upstream
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
=======
	system("clear");
	FILE* fp;
	FILE* dfp;
	int i = 0;
	char name[10];
	int judge = 0;
	int confirm;

	if ((fp = fopen("information.txt", "rb+")) == NULL)
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
		remove("information.txt");
		//원본 파일 삭제
		rename("delete.txt", "information.txt");
		//새로 만든 파일의 이름을 원래 파일 이름으로 변경
		printf("성공적으로 삭제되었습니다\n");
	}
	else
	{
		printf("\n\n삭제 취소\n\n");
	}
>>>>>>> Stashed changes
}

void Search()
{
<<<<<<< Updated upstream
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
=======
	system("clear");
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
>>>>>>> Stashed changes
}

void searchbycategory()
{
<<<<<<< Updated upstream
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
=======
	system("clear");
	int judge = 0;
	FILE* fp;
	int i = 0;
	char category[10];
	if ((fp = fopen("information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//파일을 열 수 있는지 확인
	printf("찾는 제품의 종류 입력");
	scanf("%s", category);
	for (i = 0; fread(&pros[i].kind, sizeof(struct product), 1, fp) == 1; i++)
	{
		//파일에서 제품 정보를 읽는 알고리즘
		if (strcmp(category, pros[i].kind) == 0)
		{
			judge = 1;
			printf("찾으신 제품 정보는 다음과 같습니다.\n");
			printf("%20s%20s%20s\n", pros[i].kind, pros[i].name, pros[i].price);
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
	system("clear");
	int judge = 0;
	FILE* fp;
	int i = 0;
	char name[20];
	if ((fp = fopen("information.txt", "rb")) == NULL)
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
			printf("%20s%20s%20s\n", pros[i].kind, pros[i].name, pros[i].price);
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

void Buy()  //상품 구매
{
	system("clear");
	FILE *fp;
	FILE *newfp;
	int idx[20];
	int money; //지불 금액
	int change; //거스름돈
	int prices; // 제품 가격
	int judge = 0;
	int i;

	ShowAll();
	printf("구매하려는 제품의 번호를 입력하십시오 :");
	scanf("%s", idx);
	if ((fp = fopen("information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
    if ((newfp = fopen("shoppingcart.txt", "ab")) == NULL)
    {
        printf("can not open the file");
        exit(0);
    }
	//파일 열 수 있는지 확인
	for (i = 0; judge != 1; i++)
	{
		fread(&pros[i], sizeof(struct product), 1, fp);
		//파일이 끝날 때까지 파일에서 제품의 정보를 읽어오기
		if ((strcmp(idx, pros[i].idx)) == 0)
		{
			if (fwrite(&pros[i], sizeof(struct product), 1, newfp) != 1)
			{
				printf("file write error\n");
			}
			judge = 1;
			printf("제품(%s) 가격은 %s입니다. 지폐를 넣으십시오.\n", pros[i].name,pros[i].price);
			printf("지불할 금액:"); //지불 금액을 입력하세요.
			scanf("%d", &money);
			prices = atoi(pros[i].price); //문자열에서 정수로 가격 변환
			change = money - prices;//변화량 계산

			if (change >= 0)
				printf("구매해 주셔서 감사합니다, 거스름돈은 %d원입니다.\n", change);
			else
			{
				printf("%d원이 부족합니다.\n 돈을 넣어주십시오", -change);
				printf("지불할 금액:");
				printf("%d", money);
				change = money + change;
				printf("구입해 주셔서 감사합니다. 거스름돈은 %d원입니다.\n");
			}

			//지불 금액이 충분한지 확인
		}
	}
	if (judge == 0)
		printf("구매하려는 제품이 없습니다.\n");


    if (fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    if (fclose(newfp))
>>>>>>> Stashed changes
    {
        printf("can not close the file\n");
        exit(0);
    }
<<<<<<< Updated upstream
=======
}

void sort()
{
	system("clear");
	int way;
	printf("\n\n정렬 방식을 선택하십시오:\n");
	printf("종류별1,가격별2");
	scanf("%d", &way);
	switch (way)
	{
	case 1: sortbycategory();
		break;
	case 2: sortbyprice();
		break;
	default:
		break;
	}
}

void sortbycategory()
{
	FILE *fp;
	int i, j, index=1;
	if ((fp = fopen("information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//파일을 열 수 있는지 확인
	for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) == 1; i++)
	{
		
	}
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|  번호   제품종류       제품이름       제품가격  |\n");
	printf("\t|-------------------------------------------|\n");

	for (j = 0; j <= i; j++)
	{
		if (strcmp("버거", pros[j].kind) == 0)
		{
			printf("\t|%10d%20s%20s%20s  |\n", index++, pros[j].kind, pros[j].name, pros[j].price);
		}
	}
	for (j = 0; j <= i; j++)
	{
		if (strcmp("음료", pros[j].kind) == 0)
		{
			printf("\t|%10d%20s%20s%20s  |\n", index++, pros[j].kind, pros[j].name, pros[j].price);
		}
	}
	for (j = 0; j <= i; j++)
	{
		if (strcmp("사이드", pros[j].kind) == 0)
		{
			printf("\t|%10d%20s%20s%20s  |\n", index++, pros[j].kind, pros[j].name, pros[j].price);
		}
	}
	printf("\t -------------------------------------------\n");
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	//파일을 닫을 수 있는지 확인
}

void sortbyprice()
{
	FILE *fp;
	int i = 0, j,k, index=1;
	struct product temp;
	if ((fp = fopen("information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//파일을 열 수 있는지 확인
	for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) == 1; i++)
	{
		
	}
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|  번호   제품종류       제품이름       제품가격  |\n");
	printf("\t|-------------------------------------------|\n");
	for (j = 0; j <= i; j++)
	{
		for (k = j + 1; k <= i; k++)
		{
			memcpy(&temp, &pros[i], sizeof(temp));
			if (atoi(pros[i].price) > atoi(pros[k].price))
			{
				memcpy(&pros[i], &pros[j], sizeof(pros[i]));
				memcpy(&pros[j], &temp, sizeof(pros[i]));
			}
		}
	}
	for (j = 0; j <= i; j++)
	{
			printf("\t|%10d,%20s,%20s,%20s  |\n", pros[j].idx, pros[j].kind, pros[j].name, pros[j].price);
	}
	printf("\t -------------------------------------------\n");
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	//파일을 닫을 수 있는지 확인                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}

void receipt()
{
	system("clear");
	FILE *fp;
	int i, sum = 0, money;

	fp = fopen("receipt.txt", "w+b");//영수증 생성
	printf("\n\n\n\n\n");
	printf("\t -----------------------------------------------\n");
	printf("\t|                구매하신 제품 목록               |\n");
	printf("\t|    제품종류       제품이름      갯수     제품가격|\n");
	printf("\t|-----------------------------------------------|\n");



}
void soldproducts()
{
	system("clear");
	FILE *fp;
	int i, sum = 0, money,number;

	if ((fp = fopen("soldlist.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//파일을 열 수 있는지 확인
	printf("판매된 제품은 다음과 같습니다：\n");
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|        제품이름  제품가격  판매된갯수        |\n");
	printf("\t|-------------------------------------------|\n");
	for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 0; i++)
	{
		printf("\t|%20s%20s%10d   |\n", pros[i].name, pros[i].price, number);
		money = atoi(pros[i].price)*number;
		sum += money;
	}
	printf("\t -------------------------------------------\n\n\n");
	printf("\n\n현재 총 판매금은 %d입니다.\n", sum);
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	//파일을 닫을 수 있는지 확인
}
void shoppingcart()
{
	FILE *sfp, *fp;
	int n, i = 0, judge = 0,loop=1;
	n = ShowAll();
	char name[20];
	system("clear");
	if ((sfp = fopen("shoppingcart.txt", "ab")) == NULL)
	{
		printf("can not open the file");
		exit(0);
	}
	if ((fp = fopen("information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}//파일 열 수 있는지 확인
	while (fread(&pros, sizeof(struct product), 1, fp) != 1)
	{
		i++;
	}//제품 정보 저장
	do
	{
		printf("\n\n 장바구니에 추가 할 제품의 이름을 입력하십시오.:");
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
		//제품을 찾아 장바구니에 담습니다.
		printf("다른 제품 저장하기1,완료하기0");
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
void account() // 장바구니 결제
{
	FILE *sfp, *fp;
	int i, j, sum = 0, price, money, change,number=1;
	system("clear");
	if ((sfp = fopen("shoppingcart.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	if ((fp = fopen("soldlist.txt", "ab")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|        제품이름     제품가격    갯수        |\n");
	printf("\t|-------------------------------------------|\n");
	for (i = 0; (fread(&pros[i], sizeof(struct product), 1, sfp)) != 0; i++)
	{
		price = atoi(pros[i].price);
		sum = sum + price;
		printf("\t|%20s%20s%10d   |\n", pros[i].name, pros[i].price, number);
	}
	//장바구니 목록을 출력
	printf("\t -------------------------------------------\n\n\n");
	printf("           장바구니에 총 %d 개의 제품이 있습니다.\n", i);
	printf("           %d 원을 지불하십시오\n", sum);
	printf("           지불할 금액：");
	scanf("%d", &money);
loop:change = money - sum;
	if (change >= 0)
	{
		printf("  구매 성공, 거스름 돈:%d \n", change);

	}
	else
	{
		printf("구매 실패, %d원을 더 지불하십시오", -change);
		printf("지불할 금액：");
		scanf("%d", &money);
		sum = -change;
		goto loop;
	}
	for (j = 0; j<i; j++)
	{
		fwrite(&pros[j], sizeof(struct product), 1, fp);
		//shoppingcar 파일에서 soldlist 파일로 데이터 쓰기
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
	remove("shoppingcart.txt");
>>>>>>> Stashed changes
}