/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 13:08:00 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/03/21 16:05:19 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include"pipex.h"

static char	*get_command_ext(char *command)
{
	int		i;
	int		len;
	char	*c;

	len = ft_strlen(command);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	i = 0;
	c[i] = '/';
	++i;
	while (i <= len + 1)
	{
		c[i] = *command;
		++command;
		++i;
	}
	return (c);
}

char	*get_path(char **paths, char *command)
{
	int		i;
	char	*error;
	char	*path;
	char	*commandext;

	if (access(command, X_OK) == 0)
		return (command);
	commandext = get_command_ext(command);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], commandext);
		if (access(path, X_OK) == 0)
		{
			free(commandext);
			return (path);
		}
		free(path);
		++i;
	}
	error = ft_strjoin(command, ": command not found\n");
	write(2, "pipex: ", 7);
	write(2, error, ft_strlen(error));
	free(error);
	exit(127);
}

char	**ft_env_backup(void)
{
	char	**env;

	env = (char **)ft_calloc(8, sizeof(char *));
	env[0] = ft_strdup("/usr/local/bin");
	env[1] = ft_strdup("/usr/bin");
	env[2] = ft_strdup("/bin");
	env[3] = ft_strdup("/usr/sbin");
	env[4] = ft_strdup("/sbin");
	env[5] = ft_strdup("/usr/local/munki");
	env[6] = ft_strdup("/opt/X11/bin");
	return (env);
}

char	**get_paths(char **env)
{
	char	**split;
	char	*paths;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			paths = ft_strtrim(env[i], "PATH=");
			split = ft_split(paths, ':');
			free(paths);
			return (split);
		}
		++i;
	}
	return (ft_env_backup());
}

int	open_outfile(t_info *state)
{
	int	outfd;

	if (state->heredoc)
		outfd = open(state->argv[state->index + state->offset + 1], O_WRONLY
				| O_CREAT | O_APPEND, 0644);
	else
		outfd = open(state->argv[state->index + state->offset + 1], O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	if (outfd == -1)
	{
		perror("File");
		exit(EXIT_FAILURE);
	}
	return (outfd);
}
