/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 12:01:29 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/23 12:02:05 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"fdf.h"

void	close_fdf(t_fdf *fdf)
{
	mlx_close_window(fdf->mlx);
	free_fdf(fdf);
	exit(EXIT_SUCCESS);
}

void	delete_prev_img(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img[0]);
	fdf->img[0] = NULL;
	free(fdf->texture[0]->pixels);
	free(fdf->texture[0]);
}

void	create_new_image(t_fdf *fdf)
{
	fdf->img[0] = generate_image(fdf);
	if (!fdf->img[0])
		return ;
	mlx_image_to_window(fdf->mlx, fdf->img[0], min_sx(fdf->coords)
		+ fdf->trans_x, min_sy(fdf->coords) + fdf->trans_y);
}
