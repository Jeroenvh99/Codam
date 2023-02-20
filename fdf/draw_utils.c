/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 12:56:43 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/17 12:01:16 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<math.h>
#include"fdf.h"

static void	plot(unsigned int x, unsigned int y, double z,
				mlx_texture_t *texture)
{
	unsigned int	i;
	uint8_t			*pixels;

	pixels = texture->pixels;
	if (x >= (texture->height - y) * texture->width)
		return ;
	i = (x + (y * texture->width)) * 4;
	if (z > 50)
		pixels[i] = 255;
	else if (z > 20 && z < 50)
		pixels[i] = 160;
	if (z > 20 && z < 50)
		pixels[i + 1] = 160;
	else if (z >= 0)
		pixels[i + 1] = 255;
	if (z < 0 || z > 50)
		pixels[i + 2] = 255;
	else if (z > 20 && z < 50)
		pixels[i + 2] = 160;
	pixels[i + 3] = 255;
}

static int	init_difference_low(int d[], t_coord *start, t_coord *end, int *yi)
{
	int	zdiff;

	d[0] = end->sx - start->sx;
	d[1] = end->sy - start->sy;
	zdiff = (end->z - start->z) / sqrt(pow(d[0], 2) + pow(d[1], 2));
	*yi = 1;
	if (d[1] < 0)
	{
		*yi = -1;
		d[1] = -d[1];
	}
	return (zdiff);
}

void	draw_line_low(t_coord *start, t_coord *end, mlx_texture_t *texture)
{
	int		d[2];
	int		delta;
	int		pos[2];
	int		yi;
	double	zdiff;

	zdiff = init_difference_low(d, start, end, &yi);
	delta = (2 * d[1]) - d[0];
	pos[1] = start->sy;
	pos[0] = start->sx;
	while (pos[0] != end->sx)
	{
		plot(pos[0], pos[1], start->z + (zdiff * sqrt(pow(pos[0] - start->sx,
						2) + pow(pos[1] - start->sy, 2))), texture);
		if (delta > 0)
		{
			pos[1] += yi;
			delta += 2 * (d[1] - d[0]);
		}
		else
			delta += 2 * d[1];
		++pos[0];
	}
}

static int	init_difference_high(int d[], t_coord *start, t_coord *end, int *xi)
{
	int	zdiff;

	d[0] = end->sx - start->sx;
	d[1] = end->sy - start->sy;
	zdiff = (end->z - start->z) / sqrt(pow(d[0], 2) + pow(d[1], 2));
	*xi = 1;
	if (d[0] < 0)
	{
		*xi = -1;
		d[0] = -d[0];
	}
	return (zdiff);
}

void	draw_line_high(t_coord *start, t_coord *end, mlx_texture_t *texture)
{
	int		d[2];
	int		delta;
	int		pos[2];
	int		xi;
	double	zdiff;

	zdiff = init_difference_high(d, start, end, &xi);
	delta = (2 * d[0]) - d[1];
	pos[1] = start->sy;
	pos[0] = start->sx;
	while (pos[1] != end->sy)
	{
		plot(pos[0], pos[1], start->z + (zdiff * sqrt(pow(pos[0] - start->sx,
						2) + pow(pos[1] - start->sy, 2))), texture);
		if (delta > 0)
		{
			pos[0] += xi;
			delta += 2 * (d[0] - d[1]);
		}
		else
			delta += 2 * d[0];
		++pos[1];
	}
}
