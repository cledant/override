#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>

int		main(void)
{
	int		arg_wait;		//esp + 0x1c
	char	buff[128];		//esp + 0x20
	int		arg_2;			//esp + 0xa0
	int		arg_3;			//esp + 0xa4
	int		arg_1;			//esp + 0xa8
	pid_t	fork_pid;		//esp + 0xac

	fork_pid = fork();
	bzero(buff, 128);
	arg_wait = 0;
	arg_1 = 0;
	if (pid == 0)
	{
		prctl(PR_SET_PDEATHSIG, SIGHUP);
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buff);
	}
	else
	{
		while (arg_1 != 0xb)
		{
			wait(arg_wait);
			arg_2 = arg_1;
			if (arg_1 & 0x7f != 0)
			{
				arg_3 = arg_1;
				if (((arg_3 & 0x7f + 0x1) >> 1) > 0)
				{
					puts("child is exiting...");
					return (0);
				}	
				arg_1 = ptrace(PTRACE_PEEKUSER, fork_pid, 0x2c, 0x0);	//arg_1 = orig_eax
			}
			else
			{
				puts("child is exiting...");
				return (0);
			}
		}
		puts("no exec() for you");
		kill(fork_pid, 9);
	}
	return (0);
}
