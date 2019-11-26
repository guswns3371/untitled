#include <stdio.h>
#include <string.h>
//#include <process.h>
#include <stdlib.h>
#define NUM 8
struct product
{
    char idx[20];
    char kind[20];
    char name[20];
    char price[20];
}pros[100];

void init(){
    FILE *fp;
    char kind[3][20] = {"버거","음료","사이드"};
    char name[NUM*3][20] = {"빅맥    ","불고기   ","슈슈    ","베이컨토마토","쿼터파운더 ","콰트로치즈 ","치킨    ","에그    ",
                         "스프라이트 ","콜라    ","오렌지주스 ","초코쉐이크 ","우유    ","카페라떼  ","원두커피  ","핫초코   ",
                         "맥윙    ","콘파이   ","애플파이  ","해쉬브라운 ","치킨스낵랩 ","치즈스틱  ","맥너겟   ","콘스프   "};
    //버거 8개 음료 8개 사이드 8개

    char price[NUM*3][20] ={"3500","3200","3500","3400","3100","4000","3900","3000",
                         "1500","1200","1400","1800","1800","1200","1300","1400",
                         "2500","2000","2800","2000","1200","1800","1500","1300"};
    //버거 8개 음료 8개 사이드 8개
    for (int i = 0; i < NUM*3; i++) {
        sprintf(pros[i].idx,"%d" ,i);
        strcpy(pros[i].kind,kind[i/NUM]);
        strcpy(pros[i].name,name[i]);
        strcpy(pros[i].price,price[i]);
        if ((fp = fopen("information.txt", "ab")) == NULL)
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
    }
}
int main()
{
    init();
    return 0;
}