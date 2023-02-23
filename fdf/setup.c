/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:14:07 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/23 11:46:34 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include"fdf.h"

void	set_start_view(t_fdf *fdf)
{
	fdf->rot_x = -25;
	fdf->rot_y = 30;
	fdf->rot_z = 38;
	fdf->zoom = 4;
	fdf->trans_x = 150;
	fdf->trans_y = 150;
	rot_map(fdf, fdf->rot_x, fdf->rot_y, fdf->rot_z);
}

int	get_input(char *file, t_fdf *fdf)
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

void	hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx, &keyhook, fdf);
	mlx_scroll_hook(fdf->mlx, &scrollhook, fdf);
	mlx_loop(fdf->mlx);
}

void	start_fdf(t_fdf *fdf)
{
	init_map(fdf->coords);
	set_start_view(fdf);
	fdf->img[0] = generate_image(fdf);
	if (!fdf->img[0])
	{
		(free_fdf(fdf));
		exit(EXIT_FAILURE);
	}
}
