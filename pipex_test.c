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

void	test1(int fileFROM, int fileTO, char *command)
{
	int	status;
	pid_t	pid;

	if ((pid = fork()) < 0)
		error_exit("Can't fork process");
	if (pid == 0)
	{
		if (dup2(fileFROM, STDIN_FILENO) < 0)
			error_exit("Failed to redirect output STDIN");
		if (dup2(fileTO, STDOUT_FILENO) < 0)
			error_exit("Failed to redirect output STDOUT");
		system("");
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
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
	int		results_arr[10];
	int		files_from_arr[10];
	int		files_to_arr[10];
	char	results[] = "results/result \0";
	char	files_from[] = "files_from/testFROM \0";
	char	files_to[] = "files_to/testTO \0";
	char	*tests[] = {
		"echo $PATH | grep /usr",
		"els -l | cat",
		"ls -lamp | grep a",
		"echo \"HEWOOOOOO HOW ARE YOU\" | grep HOW",
		"cat pipex_test.c | cat",
		"echo $PATH | grep /usr",
		"echo $PATH | grep /usr",
		"echo $PATH | grep /usr",
		"echo $PATH | grep /usr",
		"echo $PATH | grep /usr",
	};
	for (int i = 0; i < 10; i++)
	{
		results[14] = i + 48;
		files_from[19] = i + 48;
		files_to[15] = i + 48;
		if ((results_arr[i] = open(results, O_RDWR)) < 1)
			error_exit("Can't open RESULT files");
		if ((files_from_arr[i] = open(files_from, O_RDWR)) < 1)
			error_exit("Can't open FROM files");
		if ((files_to_arr[i] = open(files_to, O_RDWR)) < 1)
			error_exit("Can't open TO files");
		
	}
	printf(YELLOW "KO" GREEN " OK " CYAN "AAAAAA" COLOR_RESET "\n");
}
