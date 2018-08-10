#include <stdio.h>
#include <stdlib.h>

struct msg
{
	char	msg[140];
	char	name[40];
	int		len;
}

void	secret_backdoor(void)
{
	char	buff[128];

	fgets(buff, 128, stdin);
	system(buff);
}

void	set_msg(struct msg *msg)
{
	char	buff[1024];

	memset(buff, 0, 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buff, 1024, stdin);
	strncpy(msg->msg, buff, msg->len);
}

void	set_username(struct msg *msg)
{
	char	buff[128];
	int		i = 0;

	memset(buff, 0, 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buff, 128, stdin);
	while (i <= 40 && buff[i] != '\0')
	{
		msg->name[i] = buff[i];
		i++;
	}
	printf(">: Welcome, %s", msg->name); 
}

void	handle_msg(void)
{
	struct msg	toto; // rbp - c0; 0x7fffffffe500

	memset(toto->name, 0, 40);
	toto->len = 140;
	set_username(toto);
	set_msg(toto);
	puts(">: Msg sent!");
}

int		main(int argc, char **argv)
{		
	puts("--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------");
	handle_msg();
	return (0);
}
