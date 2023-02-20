/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 10:55:36 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/20 11:59:27 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<math.h>
#include"fdf.h"

static void	draw_line(t_coord *start, t_coord *end, mlx_texture_t *texture)
{
	if (abs(end->sy - start->sy) < abs(end->sx - start->sx))
	{
		if (start->sx > end->sx)
			draw_line_low(end, start, texture);
		else
			draw_line_low(start, end, texture);
	}
	else
	{
		if (start->sy > end->sy)
			draw_line_high(end, start, texture);
		else
			draw_line_high(start, end, texture);
	}
}

static void	draw_x_lines(t_list *coords, mlx_texture_t *texture)
{
	t_coord	*start;
	t_coord	*end;

	while (coords->next)
	{
		start = (t_coord *)(coords->content);
		coords = coords->next;
		end = (t_coord *)(coords->content);
		draw_line(start, end, texture);
		if (coords->next && ((t_coord *)(coords->next->content))->y != end->y)
			coords = coords->next;
	}
}

static void	draw_y_lines(t_list *coords, mlx_texture_t *texture)
{
	t_list	*temp;
	t_coord	*start;
	t_coord	*end;

	while (coords->next)
	{
		start = (t_coord *)(coords->content);
		coords = coords->next;
		temp = coords;
		while (temp->next && ((t_coord *)(temp->content))->x != start->x)
			temp = temp->next;
		end = (t_coord *)(temp->content);
		if (start->y == end->y)
			break ;
		draw_line(start, end, texture);
	}
}

static void	merror(t_fdf *fdf)
{
	free_fdf(fdf);
	errno = ENOMEM;
	perror("Error");
	exit(EXIT_FAILURE);
}

mlx_image_t	*generate_image(t_fdf *fdf)
{
	int	width;
	int	height;

	width = (max_sx(fdf->coords) - min_sx(fdf->coords)) + 1;
	height = (max_sy(fdf->coords) - min_sy(fdf->coords)) + 1;
	fdf->texture = (mlx_texture_t *)malloc(sizeof(mlx_texture_t));
	if (!fdf->texture)
		merror(fdf);
	fdf->texture->height = height;
	fdf->texture->width = width;
	fdf->texture->bytes_per_pixel = 4;
	fdf->texture->pixels = (uint8_t *)ft_calloc(width * height * 4,
			sizeof(uint8_t));
	if (!fdf->texture->pixels)
		merror(fdf);
	normalize_sc(fdf->coords);
	draw_x_lines(fdf->coords, fdf->texture);
	draw_y_lines(fdf->coords, fdf->texture);
	return (mlx_texture_to_image(fdf->mlx, fdf->texture));
}
