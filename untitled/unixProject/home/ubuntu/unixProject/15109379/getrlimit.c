#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main()
{
	struct rlimit rlim;

	getrlimit(RLIMIT_FSIZE, &rlim);
	printf("soft :%d, hard  %d \n", rlim.rlim_cur, rlim.rlim_max);

	getrlimit(RLIMIT_NOFILE, &rlim);
	printf("soft :%d, hard  %d \n", rlim.rlim_cur, rlim.rlim_max);

	getrlimit(RLIMIT_CPU, &rlim);
	printf("soft :%d, hard  %d \n", rlim.rlim_cur, rlim.rlim_max);

	getrlimit(RLIMIT_DATA, &rlim);
	printf("soft :%d, hard  %d \n", rlim.rlim_cur, rlim.rlim_max);
}
