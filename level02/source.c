#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	buff_1[112];		//$rbp - 0x70
	char	buff_2[48];			//$rbp - 0xa0
	char	buff_3[112];		//$rbp - 0x110
	FILE	*pass;
	size_t	read_char;

	bzero(buff_1, 48);
	bzero(buff_2, 20);
	bzero(buff_3, 48);
	if ((pass = fopen("/home/users/level03/.pass", "r")) == NULL)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	read_char = fread(buff_2, 1, 41, pass);
	buff_2[strcspn(buff_2, "\n")] = '\0';
	if (read_char != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 24, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 24, stderr);
		exit(1);
	}
	fclose(pass);
	puts("===== [ Secure Access System v1.0 ] =====""]");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(buff_1, 100, stdin);
	buff_1[strcspn(buff_1, "\n")] = '\0';
	printf("--[ Password: ");
	fgets(buff_3, 100, stdin);
	buff_3[strcspn(buff_3, "\n")] = '\0';
	if (strncmp(buff_3, buff_2, 41) != 0)
	{
		printf(buff_1);
		puts(" does not have access!");
		exit(1);
	}
	else
	{
		printf("Greetings, %s!\n", buff);
		system("/bin/sh");
	}
}
