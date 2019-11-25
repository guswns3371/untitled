#include "main.h"

int ShowAll()//��� ��ǰ ǥ��
{
	system("cls");
	FILE *fp;
	int i;

	if ((fp = fopen("E:\information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//������ �� �� �ִ��� Ȯ��
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|  ��ȣ   ��ǰ����       ��ǰ�̸�       ��ǰ����  |\n");
	printf("\t|-------------------------------------------|\n");
	for (i = 0; (fread(&pros[i], sizeof(struct product), 1, fp)) != 0; i++)
	{
		printf("\t|%10s%10s%10s%10s   |\n",pros[i].index,pros[i].category, pros[i].name, pros[i].price);
	}
	//��ǰ ������ ���캸�� ���Ͽ��� �μ�
	printf("\t--------------------------------------------------\n");

	printf("                        �� %d ���� �׸��� �ֽ��ϴ�\n",i);
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	return i;
	//������ ���� �� �ִ��� Ȯ��
}
void Add() //��ǰ ���� �߰�
{
	FILE *fp;
	int i = 0;
	int loop = 1; //������ �����Ǿ� �ִ��� Ȯ��
	system("cls");

	do
	{
		printf("�߰��� ��ǰ�� ��ȣ ����,�̸�,������ �Է��Ͻÿ�: \n");
		scanf("%s%s%s%s",pros[i].index, pros[i].category, pros[i].name, pros[i].price);
		//��ǰ ���� �Է�
		if ((fp = fopen("E:\information.txt", "ab")) == NULL)//�̹� �����ϴ� ���������� ������� ����
		{
			printf("can not open the file\n");
			exit(0);
		}
		//������ �� �� �ִ��� Ȯ��
		if (fwrite(&pros[i], sizeof(struct product), 1, fp) != 1)
			printf("file write error\n");
		//�迭�� �׸� ������ ���Ͽ� ���ϴ�.���׸��� ���� ���� ���θ� ����
		if (fclose(fp))
		{
			printf("can not close the file\n");
			exit(0);
		}
		//������ ���� �� �ִ��� Ȯ��
		printf("�ٸ� ��ǰ �߰�1, �޴��� ���ư���0");
		scanf("%d", &loop);
	} while (loop);
}

void Revise() //��ǰ ���� ����
{
	system("cls");
	FILE *fp;
	FILE *dfp;
	int i = 0;
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
	printf("�����Ϸ��� �׸��� �̸��� �Է��ϼ���:\n");
	scanf("%s", name);
	while (fread(&pros[i], sizeof(struct product), 1, fp)!=0)//��ǰ ������ �˻�
	{
		if (strcmp(name, pros[i].name) != 0) //������ ��ǰ �������� Ȯ��
		{
			fwrite(&pros[i], sizeof(struct product), 1, dfp);
			i++;
			//�� ���Ϸ� ������ �ʿ䰡 ���� ��ǰ ���� ����
		}
		else
		{
			rewind(fp); //���� �����͸� �ʱ�ȭ
			fseek(fp, sizeof(struct product)*(i + 1), 1);
			//�׸��� ���� �� �� ���� �����͸� �����ϴ�.
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
	//������ ���� �� �ִ��� Ȯ��
	remove("E:\information.txt");
	//���� ���� ����
	rename("E:\delete.txt", "E:\information.txt");
	//���� ���� ������ �̸��� ���� ���� �̸����� �ٲߴϴ�.
	printf("�� ��ǰ�� ������ �Է��ϼ���(����,�̸�,����)");
	scanf("%s%s%s", newpro.category, newpro.name, newpro.price);
	if ((fp = fopen("E:\information.txt", "ab")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	if (fwrite(&newpro, sizeof(struct product), 1, fp) != 1)
		printf("��ǰ ���� ���� ����\n");
	else
		printf("��ǰ ������ ���������� �����Ǿ����ϴ�.\n\n");

	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
}

void Delete() //��ǰ ���� ����
{
	system("cls");
	FILE* fp;
	FILE* dfp;
	int i = 0;
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
	//������ �� �� �ִ��� Ȯ��

	ShowAll(); //��ǰ ��� ǥ��
	printf("�����Ϸ��� ��ǰ�� �̸��� �Է��ϼ���:");
	scanf("%s", name);
	printf("��ǰ�� �����ϰڽ��ϱ�?\n");
	printf("Y/N(1/0)\n");
	scanf("%d", &confirm);
	if (confirm == 1)
	{
		while (fread(&pros[i], sizeof(struct product), 1, fp) != 1) //��ǰ ������ �˻�
		{
			if (strcmp(name, pros[i].name) != 0)
			{
				fwrite(&pros[i], sizeof(struct product), 1, dfp);
				i++;
				//�� ���Ϸ� ������ �ʿ䰡 ���� ��ǰ ������ �ű�
			}
			else
			{
				rewind(fp); //���� �����͸� �ʱ�ȭ
				fseek(fp, sizeof(struct product)*(i + 1), 0);
				//������ ��ǰ�� ���� ��ġ�� ���� �����͸� �����ϴ�.
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
		//������ ���� �� �ִ��� Ȯ��
		remove("E:\information.txt");
		//���� ���� ����
		rename("E:\delete.txt", "E:\information.txt");
		//���� ���� ������ �̸��� ���� ���� �̸����� ����
		printf("���������� �����Ǿ����ϴ�\n");
	}
	else
	{
		printf("\n\n���� ���\n\n");
	}
}

void Search()
{
	system("cls");
	int way;
	int i = 0;

	printf("\t -------------------------------------------\n");
	printf("\t|         ���ϴ� ����� �����ϼ���:           |\n");
	printf("\t|        1.������ �˻��ϱ�                   |\n");
	printf("\t|        2.�̸����� �˻��ϱ�                 |\n");
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
	//������ �� �� �ִ��� Ȯ��
	printf("ã�� ��ǰ�� ���� �Է�");
	scanf("%s", category);
	for (i = 0; fread(&pros[i].category, sizeof(struct product), 1, fp) == 1; i++)
	{
		//���Ͽ��� ��ǰ ������ �д� �˰���
		if (strcmp(category, pros[i].category) == 0)
		{
			judge = 1;
			printf("ã���� ��ǰ ������ ������ �����ϴ�.\n");
			printf("%10s%10s%10s\n", pros[i].category, pros[i].name, pros[i].price);
		}
	}
	if (judge == 0)
	{
		printf("��ǰ ������ ã�� �� �����ϴ�\n");
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
	//������ �� �� �ִ��� Ȯ��
	printf("ã�� ��ǰ�� �̸� �Է�");
	scanf("%s", name);
	for (i = 0; fread(&pros[i].name, sizeof(struct product), 1, fp) == 1; i++)
	{
		//���Ͽ��� ��ǰ ������ �д� �˰���
		if (strcmp(name, pros[i].name) == 0)
		{
			judge = 1;
			printf("ã���� ��ǰ ������ ������ �����ϴ�.\n");
			printf("%10s%10s%10s\n", pros[i].category, pros[i].name, pros[i].price);
		}
	}
	if (judge == 0)
	{
		printf("��ǰ ������ ã�� �� �����ϴ�\n");
	}
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
}

void Buy()  //��ǰ ����
{
	system("cls");
	FILE *fp;
	FILE *newfp;
	char buyname[10];
	int money; //���� �ݾ�
	int change; //�Ž�����
	int prices; // ��ǰ ����
	int judge = 0;
	int i = 0;

	ShowAll();
	printf("�����Ϸ��� ��ǰ�� �̸��� �Է��Ͻʽÿ� :");
	scanf("%s", buyname);
	if ((fp = fopen("E:\information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//���� �� �� �ִ��� Ȯ��
	for (i = 0; judge != 1; i++)
	{
		fread(&pros[i], sizeof(struct product), 1, fp);
		//������ ���� ������ ���Ͽ��� ��ǰ�� ������ �о����
		if ((strcmp(buyname, pros[i].name)) == 0)
		{
			if (fwrite(&pros[i], sizeof(struct product), 1, newfp) != 1)
			{
				printf("file write error\n");
			}
			judge = 1;
			printf("��ǰ ������ %s�Դϴ�. ���� �����ʽÿ�.\n", pros[i].price);
			printf("������ �ݾ�:"); //���� �ݾ��� �Է��ϼ���.
			scanf("%d", &money);
			prices = atoi(pros[i].price); //���ڿ����� ������ ���� ��ȯ
			change = money - prices;//��ȭ�� ���

			if (change >= 0)
				printf("������ �ּż� �����մϴ�, �Ž������� %d���Դϴ�.\n", change);
			else
			{
				printf("%d���� �����մϴ�.\n ���� �־��ֽʽÿ�", -change);
				printf("������ �ݾ�:");
				printf("%d", &money);
				change = money + change;
				printf("������ �ּż� �����մϴ�. �Ž������� %d���Դϴ�.\n");
			}

			//���� �ݾ��� ������� Ȯ��
		}
	}
	if (judge == 0)
		printf("�����Ϸ��� ��ǰ�� �����ϴ�.\n");
}

void sort()
{
	system("cls");
	int way;
	printf("\n\n���� ����� �����Ͻʽÿ�:\n");
	printf("������1,���ݺ�2");
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
	int i = 0, j, index=1;
	if ((fp = fopen("E:\information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//������ �� �� �ִ��� Ȯ��
	for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 1; i++)
	{
		
	}
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|  ��ȣ   ��ǰ����       ��ǰ�̸�       ��ǰ����  |\n");
	printf("\t|-------------------------------------------|\n");
	for (j = 0; j <= i; j++)
	{
		if (pros[i].category == "Burger")
		{
			printf("\t|%10d,%10s,%10s,%10s  |\n", index++, pros[j].category, pros[j].name, pros[j].price);
		}
	}
	for (j = 0; j <= i; j++)
	{
		if (pros[i].category == "Beverage")
		{
			printf("\t|%10d,%10s,%10s,%10s  |\n", index++, pros[j].category, pros[j].name, pros[j].price);
		}
	}
	for (j = 0; j <= i; j++)
	{
		if (pros[i].category == "Side")
		{
			printf("\t|%10d,%10s,%10s,%10s  |\n", index++, pros[j].category, pros[j].name, pros[j].price);
		}
	}
	printf("\t -------------------------------------------\n");
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	//������ ���� �� �ִ��� Ȯ��
}

void sortbyprice()
{
	FILE *fp;
	int i = 0, j, index=1,k;
	struct product temp;
	if ((fp = fopen("E:\information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//������ �� �� �ִ��� Ȯ��
	for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 1; i++)
	{
		
	}
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|  ��ȣ   ��ǰ����       ��ǰ�̸�       ��ǰ����  |\n");
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
			printf("\t|%10d,%10s,%10s,%10s  |\n", index++, pros[j].category, pros[j].name, pros[j].price);
	}
	printf("\t -------------------------------------------\n");
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	//������ ���� �� �ִ��� Ȯ��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}

void receipt()
{
	system("cls");
	FILE *fp;
	int i, sum = 0, money;

	fp = fopen("E:\receipt.txt", "w+b");//������ ����
	printf("\n\n\n\n\n");
	printf("\t -----------------------------------------------\n");
	printf("\t|                �����Ͻ� ��ǰ ���               |\n");
	printf("\t|    ��ǰ����       ��ǰ�̸�      ����     ��ǰ����|\n");
	printf("\t|-----------------------------------------------|\n");



}
void soldproducts()
{
	system("cls");
	FILE *fp;
	int i, sum = 0, money,number;

	if ((fp = fopen("E:\soldlist.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	//������ �� �� �ִ��� Ȯ��
	printf("�Ǹŵ� ��ǰ�� ������ �����ϴ٣�\n");
	printf("\n\n\n\n\n");
	printf("\t -------------------------------------------\n");
	printf("\t|          Welcome to this machine          |\n");
	printf("\t|        ��ǰ�̸�  ��ǰ����  �ǸŵȰ���        |\n");
	printf("\t|-------------------------------------------|\n");
	for (i = 0; fread(&pros[i], sizeof(struct product), 1, fp) != 0; i++)
	{
		printf("\t|%10s%10s%10d   |\n", pros[i].name, pros[i].price, number);
		money = atoi(pros[i].price)*number;
		sum += money;
	}
	printf("\t -------------------------------------------\n\n\n");
	printf("\n\n���� �� �Ǹű��� %d�Դϴ�.\n", sum);
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	//������ ���� �� �ִ��� Ȯ��
}
void shoppingcart()
{
	FILE *sfp, *fp;
	int n, i = 0, judge = 0,loop=1;
	n = ShowAll();
	char name[10];
	system("cls");
	if ((sfp = fopen("E:\shoppingcart.txt", "ab")) == NULL)
	{
		printf("can not open the file");
		exit(0);
	}
	if ((fp = fopen("E:\information.txt", "rb")) == NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}//���� �� �� �ִ��� Ȯ��
	while (fread(&pros, sizeof(struct product), 1, fp) != 1)
	{
		i++;
	}//��ǰ ���� ����
	do
	{
		printf("\n\n ��ٱ��Ͽ� �߰� �� ��ǰ�� �̸��� �Է��Ͻʽÿ�.:");
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
		//��ǰ�� ã�� ��ٱ��Ͽ� ����ϴ�.
		printf("�ٸ� ��ǰ �����ϱ�1,�Ϸ��ϱ�0");
		scanf("%d", &loop);
		judge = 0;
	} while (loop);
	if (fclose(fp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	//������ ���� �� �ִ��� Ȯ��
	if (fclose(sfp))
	{
		printf("can not close the file\n");
		exit(0);
	}
	//������ ���� �� �ִ��� Ȯ��
}
void account() // ��ٱ��� ����
{
	FILE *sfp, *fp;
	int i, j, sum = 0, price, money, change,number=1;
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
	printf("\t|        ��ǰ�̸�     ��ǰ����    ����        |\n");
	printf("\t|-------------------------------------------|\n");
	for (i = 0; (fread(&pros[i], sizeof(struct product), 1, sfp)) != 0; i++)
	{
		price = atoi(pros[i].price);
		sum = sum + price;
		printf("\t|%10s%10s%10d   |\n", pros[i].name, pros[i].price, number);
	}
	//��ٱ��� ����� ���
	printf("\t -------------------------------------------\n\n\n");
	printf("           ��ٱ��Ͽ� �� %d ���� ��ǰ�� �ֽ��ϴ�.\n", i);
	printf("           %d ���� �����Ͻʽÿ�\n", sum);
	printf("           ������ �ݾף�");
	scanf("%d", &money);
loop:change = money - sum;
	if (change >= 0)
	{
		printf("  ���� ����, �Ž��� ��:%d \n", change);

	}
	else
	{
		printf("���� ����, %d���� �� �����Ͻʽÿ�", -change);
		printf("�޾ҽ��ϴ٣�");
		scanf("%d", &money);
		sum = -change;
		goto loop;
	}
	for (j = 0; j<i; j++)
	{
		fwrite(&pros[j], sizeof(struct product), 1, fp);
		//shoppingcar ���Ͽ��� soldlist ���Ϸ� ������ ����
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