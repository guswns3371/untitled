#include "main.h"

int main(void)
{
    int id;
    int n;
    char password[20];
    char correctpassword[] = "1";
    backtomain:

    mainmenu(); //메인 메뉴 표시
    scanf("%d",&id);
    switch(id) {
        case 1: {
            printf("제품 관리 권한을 얻으려면 비밀번호를 입력하십시오:\n");
            scanf("%s", password);
            //비밀번호 입력
            while (strcmp(password, correctpassword) != 0) {
                printf("비밀번호 입력이 잘못되었습니다. 다시 입력하십시오:\n");
                scanf("%s", password);
            }
            //올바른 비밀번호 결정
            displayAdmin();
            //관리자 모드
            scanf("%d", &n);

            switch (n) {
                case 1:
                    displayAll();
                    break;
                case 2:
                    Add2();
                    break;
                case 3:
                    Revise2();
                    break;
                case 4:
                    Delete2();
                    break;
                case 5:
                    Search2();
                    break;
                case 6:
                   // getMsgFromCustomer();
                case 7:
                    exit(0);
                default:
                    break;
            }
            break;
        }
        //관리자 모드 메뉴 표시
        case 2: {
            backtomain1:
            CustomerMenu();
            scanf("%d", &n);
            switch (n) {
                case 1:
                    Buy();
                    break;
                case 2:
                    shoppingcart();
                    break;
                case 3:
                   // sendMsgToAdmin();
                    break;
                case 4:
                    viewshoppinglist();
                    break;
                case 5:
                    goto backtomain;//뒤로가기 눌렀을 시 메인메뉴 선택으로 돌아감
                    break;
                default:
                    goto backtomain1;//다른 키를 눌렀을 시 고객메뉴 선택으로 돌아감
            }
        }//소비자 메뉴 모드
        goto backtomain1;
        break;
        default:
            goto backtomain;
    }
    goto backtomain;
}
