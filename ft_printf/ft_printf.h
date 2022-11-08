/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:22 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/08 10:08:25 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdint.h>

typedef struct padding_info
{
	char	alt;
	int		width;
	char	adj;
	char	sign;
	char	padc;
	char	blank;
	int		prec;
}	t_padding;

char	*getstr_hex(long long int n, char type, t_padding *padinfo);
char	*getstr_ptr(uintptr_t ptr, char type, t_padding *padinfo);
char	*ft_uitoa(unsigned int n, t_padding *padinfo);
char	*ft_itoa_format(int n, t_padding *padinfo);
int		ft_writestr(char *s, char type, t_padding *padinfo);
int		getformat(const char *s, t_padding *padinfo);
int		ft_printf(const char *s, ...);

#endif
