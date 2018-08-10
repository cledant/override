#include <stdio.h>
#include <stdlib.h>

int		auth(char *login, unsigned int serial)
{
	size_t			len;			//ebp - 0xc
	int				i;				//ebp - 0x14
	unsigned int	compare_value;	//ebp - 0x10
	unsigned int	tmp_1;
	unsigned int	tmp_2;
	unsigned int	tmp_3;

	login[strcspn(login, "\n")] = '\0';
	len = strnlen(login, 32);
	if (len < 0x5)
		return (1);
	if (ptrace(PTRACE_TRACE_ME, 0, 1, 0) == 0xffffffff)
	{
		puts("\033[32m.---------------------------");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------");
		return (1);
	}
	compare_value = login[3] ^ 0x1337 + 0x5eeded;
	i = 0;
	while (i < len)
	{
		if (buff[i] <= 0x1f)
			return (1);
		tmp_1 = (buff[i] ^ compare_value);
		tmp_2 = tmp_1 * 0x88233b2b;
		tmp_3 = tmp_1 - 1337 * ((tmp_1 - tmp_2) / 2 + tmp_2) / 1024 + compare_value;
		if (tmp_3 == compare_value)
			return (0);
		compare_value = tmp_3;
		i++;
	}
	return (1);
}

int 	main(int argc, char **argv)
{
	char			*argv_0;		//esp + 0x1c
	char			buff[32];		//esp + 0x2c
	unsigned int	serial;			//esp + 0x28

	argv_0 = argv[0];
	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(buff, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", serial);
	if (auth(buff, serial) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
	}
}
