#include <stdio.h>
#include <time.h>
#define BUFF_SIZE 1000
int main()
{

    time_t t;
    struct tm *lt, *gt;
    char *ct,*act, buf[BUFF_SIZE],buf2[BUFF_SIZE];

    time(&t);
    ct = ctime(&t);
    lt = localtime(&t);
    act = asctime(lt);
    gt = gmtime(&t);

    strftime(buf,BUFF_SIZE,"%Y년 %m월 %d일 - %I시 %M분 %S초 %p %a %A %Z ",lt);

    printf("time(&t) : %ld\n",time(&t));
    printf("strftime : %s\n",buf);
    printf("gmtime : %d/%d/%d, %d:%d:%d\n",
           gt->tm_year+1900,gt->tm_mon+1,gt->tm_wday+1,gt->tm_hour,gt->tm_min,gt->tm_sec);
    printf("localtime : %d/%d/%d, %d:%d:%d\n",
           lt->tm_year+1900,lt->tm_mon+1,lt->tm_wday+1,lt->tm_hour,lt->tm_min,lt->tm_sec);
    printf("ctime(&t) : %s \n",ct);
    printf("asctime(lt) : %s \n",act);
    printf("이름 입력 : ");
    gets(buf2);
    printf("%s \n", buf2);

    return 0;
}
