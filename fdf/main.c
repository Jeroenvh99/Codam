/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 10:55:36 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/20 12:00:14 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include"fdf.h"

void	del(void *node)
{
	if (node)
		free(node);
	node = NULL;
}

static int	get_input(char *file, t_fdf *fdf)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!parse_input(fd, &(fdf->coords)))
	{
		errno = ENOMEM;
		perror("Error");
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (!fdf->coords)
	{
		write(2, "Error: file not loaded\n", 23);
		exit (EXIT_FAILURE);
	}
	return (1);
}

static void	hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx, &keyhook, fdf);
	mlx_scroll_hook(fdf->mlx, &scrollhook, fdf);
	mlx_loop(fdf->mlx);
}

int	free_fdf(t_fdf *fdf)
{
	if (fdf->img)
		mlx_delete_image(fdf->mlx, fdf->img);
	if (fdf->texture->pixels)
		free(fdf->texture->pixels);
	if (fdf->texture)
		free(fdf->texture);
	if (fdf->mlx)
		mlx_terminate(fdf->mlx);
	if (fdf->coords)
		ft_lstclear(&(fdf->coords), del);
	free(fdf);
	return (1);
}

// static void checkleaks()
// {
// 	system("leaks fdf");
// }

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 1)
	{
		write(2, "no input file specified\n", 24);
		return (1);
	}
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		return (1);
	get_input(argv[1], fdf);
	fdf->mlx = mlx_init(2400, 1300, "FDF", true);
	if (!fdf->mlx)
		return (free_fdf(fdf));
	init_map(fdf->coords);
	fdf->img = generate_image(fdf);
	if (!fdf->img)
		return (free_fdf(fdf));
	mlx_image_to_window(fdf->mlx, fdf->img, min_sx(fdf->coords) + fdf->trans_x,
		min_sy(fdf->coords) + fdf->trans_y);
	hooks(fdf);
	free_fdf(fdf);
	return (0);
}
