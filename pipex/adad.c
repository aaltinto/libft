#include <stdio.h>
#include "pipex.h"

int	main(int ac, char **argv, char **env)
{
	char	*path;
	char	**sub_paths;
	char	*this_is_the_way;
	int		i;

	i = -1;
	while (env[++i] != 0)
		if (ft_strncmp("PATH", env[i], 4) == 0)
			break ;
	path = ft_strdup(env[i]);
	if (path == NULL)
		return (-1);
	i = -1;
	sub_paths = ft_split(path, ':');
	while (sub_paths[++i])
	{
		this_is_the_way = ft_strjoin(sub_paths[i], "/");
		this_is_the_way = ft_strjoin(this_is_the_way, argv[1]);
		if (access(this_is_the_way, F_OK) == 0)
			return (this_is_the_way);
	}
}

