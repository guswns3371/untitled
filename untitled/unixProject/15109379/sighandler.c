#include        <signal.h> 
void myhandler(int signo);
void myhandler(int signo)

/* argument is signal number */
{
	switch (signo) {
	case SIGINT:
		printf("SIGINT(%d) is caught\n", SIGINT);
		signal(SIGINT,myhandler);
		sleep(2);
		kill(getpid(), SIGUSR1);
		break;
	case SIGQUIT:
		printf("SIGQUIT(%d) is caught\n", SIGQUIT);
		break;
	case SIGTSTP:
		printf("SIGTSTP(%d) is caught\n", SIGTSTP);
		break;
	case SIGTERM:
		printf("SIGTERM(%d) is caught\n", SIGTERM);
		signal(SIGTERM,myhandler);
		break;
	case SIGUSR1:
		printf("SIGUSR1(%d) is caught\n", SIGUSR1);
		break;
	case SIGALRM:
		printf("SIGUSR1(%d) is caught\n", SIGALRM);
		break;
	default:
		printf("other singal\n");
	}
	return;
}
int main(void) {
	signal(SIGALRM, myhandler);
	alarm(5);
	//alarm(0);
	signal(SIGINT, myhandler);
	//  signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, myhandler);
	signal(SIGTSTP, myhandler);
	// signal(SIGTERM, SIG_DFL); 
	signal(SIGTERM, myhandler);
	signal(SIGUSR1, myhandler);
	for (;;)
	    pause();
}
