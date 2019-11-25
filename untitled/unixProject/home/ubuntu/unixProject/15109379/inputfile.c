#include <unistd.h>
#include <fcntl.h>
#define BUFFSIZE 8192 

int main(void)
{
int n,fd1,fd2; 
char buf[BUFFSIZE]; 

fd1 = open("output",O_WRONLY|O_CREAT,0644);
fd2 = open("input",O_RDWR);

while ((n=read(fd1,buf,BUFFSIZE))>0) 
if (write(fd2 ,buf,n)!=n) 
printf("write error\n"); 
if (n<0) 
printf("read error\n"); 
exit(0); 
}
