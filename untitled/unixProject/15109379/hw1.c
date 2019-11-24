#include <unistd.h>
#include <fcntl.h> 
#define BUFFSIZE 8192 

int main(void) 
{ 
	int fd,n;
	int fda, fdb;
	char buf[BUFFSIZE];

	fd = creat("result", 0644);
	fda = open("inputa", O_RDWR);
	fdb = open("inputb", O_RDWR | O_CREAT, 0644);

	while ((n = read(fda, buf, BUFFSIZE)) > 0)
		if (write(fd, buf, n) != n)
			printf("write error\n");
	lseek(fd, 10, SEEK_SET);
	write(fd, "fighting!\n", 10);

	while ((n = read(fdb, buf, BUFFSIZE)) > 0)
		if (write(fd, buf, n) != n)
			printf("write error\n");
	lseek(fd, 5, SEEK_CUR);
	write(fd, "fighting!\n", 10);

	if (n < 0)
		printf("read error\n");
	close(fd);
	close(fda);
	close(fdb); 
	exit(0);
}
