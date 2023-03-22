/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 12:37:34 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/03/21 16:00:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include"./libft/libft.h"

typedef struct s_info{
	int		index;
	int		offset;
	int		heredoc;
	char	**paths;
	char	**comm_paths;
	char	**argv;
	char	***comm_argv;
}	t_info;

t_info	*init_state(char **argv, char **envp, int argc);
int		read_heredoc(t_info *state);
void	free_split(char **arr);
void	free_split_array(char ***split_arr);
void	free_state(t_info *state);
char	**get_paths(char **env);
char	*get_path(char **paths, char *command);
int		open_outfile(t_info *state);
char	*check_double(char *s);
char	*check_single(char *s);
int		skip_quotes(char ***s, int *quotes, int i);
char	**split_args(char *s, char c);
int		exec_command(char **envp, int fd, t_info *state);

#endif
