/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:22 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/31 12:53:29 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdint.h>

typedef struct padding_info
{
	int		side;
	int		length;
	char	padchar;
}	padding;

char	*getstr_hex(long long int n, int ptr, char format);
char	*getstr_ptr(uintptr_t ptr);
char	*ft_uitoa(unsigned int n);
int		ft_writestr(char *s, char format);
int		ft_printf(const char *s, ...);

#endif
