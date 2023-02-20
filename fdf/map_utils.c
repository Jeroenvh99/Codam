/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 10:55:36 by jvan-hal      #+#    #+#                 */
/*   Updated: 2023/02/16 13:02:40 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	init_map(t_list *coords)
{
	t_coord	*coord;

	while (coords)
	{
		coord = (t_coord *)(coords->content);
		coord->sx = coord->x;
		coord->sy = coord->y;
		coords = coords->next;
	}
}

int	min_sx(t_list *coords)
{
	int	min_sx;

	min_sx = ((t_coord *)(coords->content))->sx;
	coords = coords->next;
	while (coords)
	{
		if (((t_coord *)(coords->content))->sx < min_sx)
			min_sx = ((t_coord *)(coords->content))->sx;
		coords = coords->next;
	}
	return (min_sx);
}

int	max_sx(t_list *coords)
{
	int	max_sx;

	max_sx = ((t_coord *)(coords->content))->sx;
	coords = coords->next;
	while (coords)
	{
		if (((t_coord *)(coords->content))->sx > max_sx)
			max_sx = ((t_coord *)(coords->content))->sx;
		coords = coords->next;
	}
	return (max_sx);
}

int	min_sy(t_list *coords)
{
	int	min_sy;

	min_sy = ((t_coord *)(coords->content))->sy;
	coords = coords->next;
	while (coords)
	{
		if (((t_coord *)(coords->content))->sy < min_sy)
			min_sy = ((t_coord *)(coords->content))->sy;
		coords = coords->next;
	}
	return (min_sy);
}

int	max_sy(t_list *coords)
{
	int	max_sy;

	max_sy = ((t_coord *)(coords->content))->sy;
	coords = coords->next;
	while (coords)
	{
		if (((t_coord *)(coords->content))->sy > max_sy)
			max_sy = ((t_coord *)(coords->content))->sy;
		coords = coords->next;
	}
	return (max_sy);
}
