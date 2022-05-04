#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "colors.h"
#include "../pipex/pipex.h"

#define TEST1 "ls -l"

void	error_exit(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

char	*fork_process(int pipes[2], int fd)
{
	pid_t	pid;
	int	status;

	if ((pid = fork()) < 0)
		error_exit("Can't fork process");
	if (pid == 0)
	{
		close(pipes[0]);
		if (dup2(fd, STDOUT_FILENO) < 0)
			error_exit("Failed to redirect output");
		system("ls -l");
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipes[1]);
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
	printf(YELLOW);
	check(TEST1);
	dup2(STDOUT_FILENO, STDOUT_FILENO);
	printf(RED "KO" GREEN " OK " CYAN "IDI NAXUY" COLOR_RESET "\n");
}
