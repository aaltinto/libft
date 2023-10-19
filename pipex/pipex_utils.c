
#include "pipex.h"

int	open_file(char *argv, int where)
{
	int	fd;

	if (where == 0)
		fd = open(argv, O_RDONLY, 0777);
	if (where == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
}

void	close_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

void	exit_function(int error)
{
	if (error == 0)
		ft_putstr_fd
			("Invalid argument call: ./pipex infile cmd1 cmd2 outfile", 2);
	exit(0);
}

char	free_things(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		free(str[i]);
	free (str);
	return (0);
}
