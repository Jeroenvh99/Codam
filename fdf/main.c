/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 10:55:36 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/23 11:50:18 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"fdf.h"

void	printcoords(t_list *coords)
{
	t_coord	*coord;

	while (coords)
	{
		coord = (t_coord *)coords->content;
		ft_printf("x: %i, y: %i\n", coord->x, coord->y);
		coords = coords->next;
	}
}

void	del(void *node)
{
	if (node)
		free(node);
	node = NULL;
}

int	free_fdf(t_fdf *fdf)
{
	if (fdf->img[0])
		mlx_delete_image(fdf->mlx, fdf->img[0]);
	if (fdf->texture[0]->pixels)
		free(fdf->texture[0]->pixels);
	if (fdf->texture[0])
		free(fdf->texture[0]);
	if (fdf->img[1])
		mlx_delete_image(fdf->mlx, fdf->img[1]);
	if (fdf->texture[1]->pixels)
		free(fdf->texture[1]->pixels);
	if (fdf->texture[1])
		free(fdf->texture[1]);
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

	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			write(2, "no input file specified\n", 24);
		else
			write(2, "too many arguments\n", 19);
		return (1);
	}
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		return (1);
	get_input(argv[1], fdf);
	fdf->mlx = mlx_init(1400, 1300, "FDF", true);
	if (!fdf->mlx)
		return (free_fdf(fdf));
	start_fdf(fdf);
	draw_legend(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img[0], min_sx(fdf->coords)
		+ fdf->trans_x, min_sy(fdf->coords) + fdf->trans_y);
	hooks(fdf);
	free_fdf(fdf);
	return (0);
}
