/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 10:55:36 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/23 12:03:51 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"fdf.h"

static void	update_image_rot(t_fdf *fdf, int x, int y, int z)
{
	delete_prev_img(fdf);
	fdf->rot_x += x;
	fdf->rot_y += y;
	fdf->rot_z += z;
	rot_map(fdf, fdf->rot_x, fdf->rot_y, fdf->rot_z);
	create_new_image(fdf);
}

static void	rotation(mlx_key_data_t keydata, t_fdf *fdf)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		y += 2;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		y -= 2;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		x += 2;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		x -= 2;
	if (keydata.key == MLX_KEY_PAGE_UP && keydata.action == MLX_REPEAT)
		z += 2;
	if (keydata.key == MLX_KEY_PAGE_DOWN && keydata.action == MLX_REPEAT)
		z -= 2;
	if (x != 0 || y != 0 || z != 0)
		update_image_rot(fdf, x, y, z);
}

static void	update_translation(t_fdf *fdf, int x, int y)
{
	fdf->img[0]->instances[0].x += x;
	fdf->trans_x += x;
	fdf->img[0]->instances[0].y += y;
	fdf->trans_y += y;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_fdf(fdf);
	if (keydata.key == MLX_KEY_HOME && keydata.action == MLX_PRESS)
	{
		delete_prev_img(fdf);
		set_start_view(fdf);
		create_new_image(fdf);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
		y -= 5;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		y += 5;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		x -= 5;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		x += 5;
	update_translation(fdf, x, y);
	rotation(keydata, fdf);
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;
	int		zoom;

	fdf = (t_fdf *)param;
	xdelta = 0;
	zoom = 0;
	if (ydelta > 0)
		zoom += 2;
	else if (ydelta < 0 && fdf->zoom >= 2)
		zoom -= 2;
	if (zoom != 0)
	{
		fdf->zoom += zoom;
		delete_prev_img(fdf);
		scale_map(fdf, fdf->zoom);
		rot_map(fdf, fdf->rot_x, fdf->rot_y, fdf->rot_z);
		create_new_image(fdf);
	}
}
