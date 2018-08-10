#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int		pwd;

void	decrypt(int nb)
{
	char		buff[17] = "Q}|u`sfg~sf{}|a3";	//0xffffd67b
	size_t		len_buff;
	size_t		c = 0;

	len_buff = strlen(buff);
	while (c < len_buff)
	{
		buff[c] = buff[c] ^ (pwd + c);
		c++;
	}
	if (strcmp(buff, "Congratulations!") == 0)
		system("/bin/sh");
	else
		puts("\nInvalid Password");
}

void	test(int read, int salt)
{
	if ((pwd = salt - pwd) >= 7 && pwd <= 21)
		decrypt(pwd);
	else
		decrypt(rand());
}

int		main(void)
{
	time_t	t;

	t = 0;
	srand(time(&t));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &pwd);
	test(pwd, 0x1337d00d);
	return (0);
}
