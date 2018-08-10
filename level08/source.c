#include <stdio.h>
#include <stdlib.h>

void	log_wrapper(FILE *log, char *str, char *arg)
{
	//log = $rbp - 0x118
	//str = $rbp - 0x120 
	//arg = $rbp - 0x128
	char	buff[4096]; //$rbp - 0x110
	size_t	len_buff;i

	strcpy(buff, str);
	len = strlen(buff);
	snprintf(buff + len, 0xfe - len, argv[1]);
	buff[strcspn(buff, "\n")] = '\0';
	fprintf(file, "LOG: %s\n", buff);
}

int		main(int argc, char **argv)
{
	FILE	*file_log;			//rbp - 0x88
	FILE	*file_pass;			//rdp - 0x80
	char	buff_name[4098] = "./backups/";
	char	buff_file[4098];
	size_t	len_backup;
	int		fd_bak_file;		//rbp - 0x78
	char	letter;

	if (argc != 2)
		printf("Usage: %s filename\n", argv[0]);
	if ((file_log = fopen("./backups/.log", "w")) == NULL)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(file_log, "Starting back up: ", argv[1]);
	if ((file_pass = fopen(argv[1], "r")) == NULL)
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	len_backup = strlen(buff_name);
	len_backup = 0x63 - len_backup;
	strncat(buff_name, argv[1], len_backup);
	if ((fd_bak_file = open(buff, O_WRONLY | O_CREAT, 432)) == NULL)
	{
		printf("ERROR : Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}
	while ((letter = fgetc(file_pass)) != EOF)
		write(fd_bak_file, &letter, 1);
	log_wrapper(file_log, "Finished back up ", argv[1]);
	fclose(file_pass);
	close(fd_bak_file);
	return (0);
}
