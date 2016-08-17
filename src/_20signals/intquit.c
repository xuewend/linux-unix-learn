#include <signal.h>
#include "../lib/tlpi_hdr.h"
#include <unistd.h>
static void
sigHandler(int sig)
{
	static int count = 0;
	
	/*
	  UNSAFE: this handler user non-async-signal-safe functions
	  (printf(),exit(); see Section 21.1.2)
	*/
	
	if(sig == SIGINT){
		count ++;
		printf("Caught SIGINT (%d)\n",count);
		return;
	}

	/* Must be SIGQUIT - printf a message and terminate the progress */
	
	printf("Caught SIGQUIT - that`s all folks!\n");
	exit(EXIT_SUCCESS);
}

int 
main(int argc, char* argv[])
{
	pid_t pid = getpid();
	printf("mypid:%d\n",pid);
	/*Establish same handler for SIGINT and SIGQUIT */
	if(signal(SIGINT, sigHandler) == SIG_ERR) errExit("signal int");
	if(signal(SIGQUIT,sigHandler) == SIG_ERR) errExit("signal quit");

	for(;;) pause();
}
