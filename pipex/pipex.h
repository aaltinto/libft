
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include "libft/libft.h"

int		open_file(char *argv, int where);
void	close_fds(int *fds);
void	exit_function(int error);
char	free_things(char **str);

#endif