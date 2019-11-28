#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h> 

int g = 6; 
char buf[] = "a write to stdout\n"; 

int main(void)
{
	int var;
	pid_t pid;
	var = 88;
	
	printf("before fork\n");

	/* we don't flush stdout */
	if ( (pid = vfork()) < 0) {
		perror("vfork error"); 
		exit(1); 
	}
	else if (pid == 0) {
		/* child */
		g++;
		/* modify variables */
		var++;
		_exit(0);
		/*child terminates*/
	}
	/* parent */
	printf("pid = %d, glob = %d, var = %d\n", getpid(), g, var);
	exit(0);
}
