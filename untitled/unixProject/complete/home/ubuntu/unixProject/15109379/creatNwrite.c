#include <unistd.h>
#include <fcntl.h>
#define BUFFSIZE 8192 
int main(void)
{
int n,fd; 
char buf[BUFFSIZE]; 
fd = open("output",O_WRONLY|O_CREAT|O_APPEND,0644);
//fd = creat("output", 0644);

while ((n=read(STDIN_FILENO,buf,BUFFSIZE))>0) 
if (write(fd,buf,n)!=n) 
printf("write error\n"); 
if (n<0) 
printf("read error\n"); 
exit(0); 
}
