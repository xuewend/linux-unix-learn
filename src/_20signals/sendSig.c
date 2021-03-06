#include <signal.h>
#include "../lib/tlpi_hdr.h"
#include <unistd.h>
/*
* 由于历史原因，在最初的unix版本中，一般只发送信号给进程就是终止该进程
  因此名字叫kill
*/



int 
main(int argc, char* argv[])
{	pid_t destPid;
	
	if(argc < 3 || strcmp(argv[1], "--help") == 0)
                usageErr("%s PID -sig\n", argv[0]);
	
		
	destPid = getLong(argv[1],0,"PID");

	for(;;)
	{
		sleep(10);
//		printf("kill pid: %ld\n",(long)destPid);
		kill(destPid,SIGINT);
		printf("kill pid: %ld done\n",(long)destPid);
	}
	
	return 0;


}
