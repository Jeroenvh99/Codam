/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_utils_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 12:05:12 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/04 16:19:33 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"./sources/libft.h"
#include"ft_printf.h"
#include<unistd.h>
#include<stdlib.h>

int	printpreformatting(int strlen, t_padding *padinfo)
{
	int		i;
	int		formlen;
	char	*form;

	formlen = 0;
	if (padinfo->width > -1 && padinfo->adj == 'r' && strlen < padinfo->width)
	{
		i = padinfo->width - strlen;
		form = ft_calloc(i + 1, 1);
		if (!form)
			return (-1);
		formlen = i;
		while (i > 0)
		{
			--i;
			form[i] = padinfo->padc;
		}
		write(1, form, formlen);
		free(form);
	}
	return (formlen);
}

int	printpostformatting(int strlen, t_padding *padinfo)
{
	int		i;
	int		formlen;
	char	*form;

	formlen = 0;
	if (padinfo->width > -1 && padinfo->adj == 'l' && strlen < padinfo->width)
	{
		i = padinfo->width - strlen;
		form = ft_calloc(i + 1, 1);
		if (!form)
			return (-1);
		formlen = i;
		while (i > 0)
		{
			--i;
			form[i] = padinfo->padc;
		}
		write(1, form, formlen);
		free(form);
	}
	return (formlen);
}
