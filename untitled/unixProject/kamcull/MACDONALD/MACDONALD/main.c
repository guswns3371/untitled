#include "main.h"

int main(void)
{
	int n;
	char password[20];
	char *correctpassword = "123456";
backtomain:
	mainmenu(); //���� �޴� ǥ��
	if (ID == 0)
	{
		printf("��ǰ ���� ������ �������� ��й�ȣ�� �Է��Ͻʽÿ�:\n");
		scanf("%s", password);
		//��й�ȣ �Է�
		while (strcmp(password, correctpassword) != 0)
		{
			printf("��й�ȣ �Է��� �߸��Ǿ����ϴ�. �ٽ� �Է��Ͻʽÿ�:\n");
			scanf("%s", password);
		}
		//�ùٸ� ��й�ȣ ����
	backtomenu0:
		showmenu0();
		//������ ���
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
		case 6:soldproducts();
			break;
		case 7:exit(0);
		default:break;
		}
	}
	//������ ��� �޴� ǥ��
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
		}//�Һ��� �޴� ���
	}
	printf("\n\n\n");
	printf("���� �޴��� ���ư��ϴ�0,�����ڸ޴��� ����1,�Һ��ڸ޴��ΰ���2�� ");
	scanf("%d", &back);
	if (back == 0)
		goto backtomain;
	else if (back == 1)
		goto backtomenu0;
	else if (back == 2)
		goto backtomenu1;

	return 0;
}