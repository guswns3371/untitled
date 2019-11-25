#include "main.h"

int main(void)
{
	int n;
	char password[20];
	char *correctpassword = "123456";
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
		showmenu0();
		//관리자 모드
		scanf("%d", &n);

		switch (n)
		{
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
		case 6:turnover();
			break;
		case 7:exit(0);
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
		case 3:shoppingcar();
			break;
		case 4:account();
			break;
		case 5:exit(0);
			break;
		default:break;
		}//소비자 메뉴 모드
	}
	printf("\n\n\n");
	printf("메인 메뉴로 돌아갑니다0,관리자메뉴로 가기1,소비자메뉴로가기2： ");
	scanf("%d", &back);
	if (back == 0)
		goto backtomain;
	else if (back == 1)
		goto backtomenu0;
	else if (back == 2)
		goto backtomenu1;

	return 0;
}