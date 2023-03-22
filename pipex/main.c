/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 16:56:34 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/03/21 15:16:43 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include"pipex.h"

// static void	checkleaks()
// {
// 	system("leaks pipex");
// }

static int	open_fds(char *filename, t_info *state)
{
	int	fd;

	if (ft_strncmp(filename, "here_doc", 9) == 0)
		fd = read_heredoc(state);
	else
		fd = open(filename, O_RDONLY, 0644);
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd;
	t_info	*state;
	char	*error;

	if (argc < 5)
	{
		write(2, "not enough arguments\n", 21);
		return (1);
	}
	state = init_state(argv, envp, argc);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		state->offset = 3;
		state->heredoc = 1;
	}
	fd = open_fds(argv[1], state);
	if (fd == -1)
	{
		error = ft_strjoin("pipex: ", argv[1]);
		perror(error);
		free(error);
	}
	exec_command(envp, fd, state);
	return (1);
}
