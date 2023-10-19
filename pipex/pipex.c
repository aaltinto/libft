#include "pipex.h"



static char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	**sub_paths;
	char	*this_is_the_way;
	int		i;

	i = -1;
	while (env[++i] != 0)
		if (ft_strncmp("PATH", env[i], 4) == 0)
			path = ft_strdup(env[i]); //path malloc
	i = -1;
	sub_paths = ft_split(path, ':');//sub_paths malloc
	free(path);//path free
	if (!sub_paths)
		return (NULL);
	while (sub_paths[++i])
	{
		this_is_the_way = ft_strjoin(sub_paths[i], cmd);//titw malloc
		if (access(this_is_the_way, F_OK) == 0)
		{
			free_things(sub_paths);
			return (this_is_the_way);//cant freed titw
		}
		free(this_is_the_way);//free titw
	}
	return ("error");
}



static void	ft_exec(char *cmd, char **env)
{
	char	**splitted_cmd;
	char	*path;
	char	*path_cmd;

	splitted_cmd = ft_split(cmd, ' ');//splitted malloc
	path_cmd = ft_strjoin("/", splitted_cmd[0]);//path_cmd malloc
	path = get_path(path_cmd, env);//path malloc
	free(path_cmd);//free path_cmd
	if (execve(path, splitted_cmd, env) == -1)
		perror("execute problem");
	free(path);
	free_things(splitted_cmd);

}

static void	child_process(int *fd_pipe, char **argv, char **env)
{
	int	fd;

	fd = open_file(argv[1], STDIN_FILENO);
	if (fd == -1)
		perror("Open file error");
	dup2(fd, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close_fds(fd_pipe);
	close(fd);
	ft_exec(argv[2], env);
}

static void	child_process_2(int *fd1, char **argv, char **env)
{
	int	fd;

	fd = open_file(argv[4], STDOUT_FILENO);
	if (fd == -1)
		perror("Open file error");
	dup2(fd, STDOUT_FILENO);
	dup2(fd1[0], STDIN_FILENO);
	close(fd);
	close_fds(fd1);
	ft_exec(argv[3], env);
}

int	main(int ac, char *argv[], char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (ac != 5)
		exit_function(0);
	if (pipe(fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 < 0)
		exit_function(1);
	if (pid1 == 0)
		child_process(fd, argv, env);
	pid2 = fork();
	if (pid2 < 0)
		exit_function(1);
	if (pid2 == 0)
		child_process_2(fd, argv, env);
	close_fds(fd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
