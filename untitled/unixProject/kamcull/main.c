<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
#include "main.h"

int main(void)
{
	int n;
	char password[20];
	char *correctpassword = "123456";
backtomain:
<<<<<<< Updated upstream
	mainmenu(); //¸ÞÀÎ ¸Þ´º Ç¥½Ã
	if (ID == 0)
	{
		printf("Á¦Ç° °ü¸® ±ÇÇÑÀ» ¾òÀ¸·Á¸é ºñ¹Ð¹øÈ£¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À:\n");
		scanf("%s", password);
		//ºñ¹Ð¹øÈ£ ÀÔ·Â
		while (strcmp(password, correctpassword) != 0)
		{
			printf("ºñ¹Ð¹øÈ£ ÀÔ·ÂÀÌ Àß¸øµÇ¾ú½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ½Ê½Ã¿À:\n");
			scanf("%s", password);
		}
		//¿Ã¹Ù¸¥ ºñ¹Ð¹øÈ£ °áÁ¤
	backtomenu0:
		showmenu0();
		//°ü¸®ÀÚ ¸ðµå
=======
	mainmenu(); //ë©”ì¸ ë©”ë‰´ í‘œì‹œ
	if (ID == 0)
	{
		printf("ì œí’ˆ ê´€ë¦¬ ê¶Œí•œì„ ì–»ìœ¼ë ¤ë©´ ë¹„ë°€ë²ˆí˜¸ë¥¼ ìž…ë ¥í•˜ì‹­ì‹œì˜¤:\n");
		scanf("%s", password);
		//ë¹„ë°€ë²ˆí˜¸ ìž…ë ¥
		while (strcmp(password, correctpassword) != 0)
		{
			printf("ë¹„ë°€ë²ˆí˜¸ ìž…ë ¥ì´ ìž˜ëª»ë˜ì—ˆìŠµë‹ˆë‹¤. ë‹¤ì‹œ ìž…ë ¥í•˜ì‹­ì‹œì˜¤:\n");
			scanf("%s", password);
		}
		//ì˜¬ë°”ë¥¸ ë¹„ë°€ë²ˆí˜¸ ê²°ì •
	backtomenu0:
		showmenu0();
		//ê´€ë¦¬ìž ëª¨ë“œ
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
		case 6:turnover();
=======
		case 6:soldproducts();
>>>>>>> Stashed changes
			break;
		case 7:exit(0);
		default:break;
		}
	}
<<<<<<< Updated upstream
	//°ü¸®ÀÚ ¸ðµå ¸Þ´º Ç¥½Ã
=======
	//ê´€ë¦¬ìž ëª¨ë“œ ë©”ë‰´ í‘œì‹œ
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
		case 3:shoppingcar();
=======
		case 3:shoppingcart();
>>>>>>> Stashed changes
			break;
		case 4:account();
			break;
		case 5:exit(0);
			break;
		default:break;
<<<<<<< Updated upstream
		}//¼ÒºñÀÚ ¸Þ´º ¸ðµå
	}
	printf("\n\n\n");
	printf("¸ÞÀÎ ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù0,°ü¸®ÀÚ¸Þ´º·Î °¡±â1,¼ÒºñÀÚ¸Þ´º·Î°¡±â2£º ");
=======
		}//ì†Œë¹„ìž ë©”ë‰´ ëª¨ë“œ
	}
	printf("\n\n\n");
	printf("ë©”ì¸ ë©”ë‰´ë¡œ ëŒì•„ê°‘ë‹ˆë‹¤0,ê´€ë¦¬ìžë©”ë‰´ë¡œ ê°€ê¸°1,ì†Œë¹„ìžë©”ë‰´ë¡œê°€ê¸°2ï¼š ");
>>>>>>> Stashed changes
	scanf("%d", &back);
	if (back == 0)
		goto backtomain;
	else if (back == 1)
		goto backtomenu0;
	else if (back == 2)
		goto backtomenu1;

	return 0;
}