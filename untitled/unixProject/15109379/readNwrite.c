#include <unistd.h>
 #define BUFFSIZE 8192 
int main(void)
{
int n; 
char buf[BUFFSIZE]; 
while ((n=read(STDIN_FILENO,buf,BUFFSIZE))>0)
if (write(STDOUT_FILENOoutput",buf,n)!=n) 
printf("write error\n"); 
if (n<0) 
printf("read error\n"); 
exit(0); 
}
