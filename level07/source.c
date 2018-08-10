#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int	get_unum(void)
{
	unsigned int	number;

	fflush(stdin);
	scanf("%u", number);
	return (number);
}

int				store_number(unsigned int *data)
{
    unsigned int	input;
    int 			index;

    printf(" Number: ");
    input = get_unum();
    printf(" Index: ");
    index = (int)get_unum();
    if (index % 3 == 0 || (input >> 24) == 0xb7)
    {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return (1);
    }
    data[index] = input;
    return (0);
}

int				read_number(unsigned int *data)
{
    int index;

    printf(" Index: ");
    index = (int)get_unum();
    printf(" Number at data[%d] is %u\n", index, data[index]);
    return (0);
}

int				main(int argc, char **argv, char **envp)
{
    int 			res;
    char 			cmd[20];
    unsigned int 	data[100];
	int				i = 0;
	
    while (argv[i] != '\0')
	{
		memset(argv[i], 0, strlen(argv[i]));
		i++;
	}
	i = 0;
    while (envp[i] != '\0')
	{
		memset(envp[i], 0, strlen(envp[i]));
		i++;
	}
    puts("----------------------------------------------------
  Welcome to wil's crappy number storage service!
----------------------------------------------------
 Commands:
    store - store a number into the data storage
    read  - read a number from the data storage
    quit  - exit the program
----------------------------------------------------
   wil has reserved some storage :>
----------------------------------------------------");
    while (1)
    {
        printf("Input command: ");
        fgets(cmd, 20, stdin);
        cmd[strlen(cmd) - 1] = '\0';
        if (strncmp(cmd, "store", 5) == 0)
            res = store_number(data);
        else if (strncmp(cmd, "read", 4) == 0)
            res = read_number(data);
        else if (strncmp(cmd, "quit", 4) == 0)
            break;
        if (res == 0)
            printf(" Failed to do %s command\n", cmd);
        else
            printf(" Completed %s command successfully\n", cmd);
    }
    return (0);
}
