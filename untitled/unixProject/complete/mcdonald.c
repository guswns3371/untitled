
#include "main.h"

int main(void)
{
    int n;
    char password[20];
    char *correctpassword = "1";
    backtomain:
    mainmenu(); //메인 메뉴 표시
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
        backtomenu0:
        displayAdmin();
        //관리자 모드
        scanf("%d", &n);

        switch (n)
        {
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
        //관리자 모드 메뉴 표시
    else
    {
        backtomenu1:
        showmenu1();
        scanf("%d", &n);
        switch (n){
            case 1:Buy();
                break;
            case 2:sort();
                break;
            case 3:shoppingcart();
                break;
            case 4:account();
                break;
            case 5:exit(0);
                break;
            default:break;
        }//소비자 메뉴 모드
    }
    printf("\n\n\n");
    printf("\t메인 메뉴로 돌아가기 0\n\tAdmin 메뉴로 돌아가기 1\n\t손님 메뉴로 돌아가기 2\n\t:");
    scanf("%d", &back);
    if (back == 0)
        goto backtomain;
    else if (back == 1)
        goto backtomenu0;
    else if (back == 2)
        goto backtomenu1;

    return 0;
}