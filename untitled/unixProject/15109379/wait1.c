#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 
#include <sys/wait.h>

main()
{ 
	pid_t pid;
	int status;
	if ((pid = fork()) == 0) {
		/* child process */ 
		printf("I am a child\n");
		exit(257); 
	} 
	/* parent process */
	pid = wait(&status);
	printf("parent: child(pid = %d) is terminated with status (%d)\n", pid, 
		WEXITSTATUS(status)); 
}
