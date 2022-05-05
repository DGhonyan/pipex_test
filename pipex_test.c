#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "colors.h"
#include "pipex.h"

#define TEST1 "ls -l"

void	error_exit(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

char	*read_from_fd(int fd)
{
	char	*s;
	char	c;
	int		a;

	s = NULL;
	while (1)
	{
		a = read(fd, &c, 1);
		free_error(NULL, s, a == -1, "read() failed at read_from_fd()");
		if (a == 0)
			break ;
		s = ft_strjoin_for_read(s, c);
		free_error(NULL, NULL, !s, "malloc failed at read_from_fd");
	}
	return (s);
}

char	*test1(int fileFROM, int fileTO)
{
	int	status;
	//int	fileFROM;
	//int	fileTO;
	pid_t	pid;

	if ((pid = fork()) < 0)
		error_exit("Can't fork process");
	if (pid == 0)
	{
		//close(pipes[0]);
	//	if ((fileFROM = open("test1FROM", O_RDONLY)) < 0)
	//		error_exit("Can't open file test1FROM");
	//	if ((fileTO = open("test1TO", O_TRUNC | O_WRONLY)) < 0)
	//		error_exit("Can't open file test1TO");
		if (dup2(fileFROM, STDIN_FILENO) < 0)
			error_exit("Failed to redirect output STDIN");
		if (dup2(fileTO, STDOUT_FILENO) < 0)
			error_exit("Failed to redirect output STDOUT");
		system("");
		exit(EXIT_SUCCESS);
	}
	else
	{
		//close(pipes[1]);
		waitpid(pid, &status, 0);
	}
	return (NULL);
}


void	check(char *command)
{
	int	fd;

	fd = open("test", O_TRUNC | O_RDWR | O_CREAT);
	if ((fd = open("test", O_TRUNC | O_RDWR)) < 0)
		error_exit("Failed to open file");
	if (dup2(fd, STDOUT_FILENO) < 0)
		error_exit("Failed to redirect output");
	system(command);
	close(fd);
}

int	main()
{
	int		pipes[2];
	int		result_files[10];
	char	filename[] = "result \0";
	char	files_from[] = "testFROM \0";
	char	files_to[] = "testTO \0";

	for (int i = 0; i < 10; i++)
	{
		filename[6] = i + 48;
		if ((result_files[i] = open(filename, O_RDWR)) < 1)
			error_exit("Can't open result files");
	}
	if (pipe(pipes) < 0)
		error_exit("Failed at creating pipes");
	//system("echo $PATH | grep aaaaaaaaaaaaaa");
	printf(RED "KO" GREEN " OK " CYAN "IDI NAXUY" COLOR_RESET "\n");
}
