/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:22 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/11/04 12:04:35 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdint.h>

typedef struct padding_info
{
	char	alternate;
	int		width;
	char	adjustment;
	char	sign;
	char	padchar;
	char	blank;
	int		precision;
}	t_padding;

char	*getstr_hex(long long int n, char format, char alternate,
			int precision);
char	*getstr_ptr(uintptr_t ptr, char format, int precision);
char	*ft_uitoa(unsigned int n, int precision);
char	*ft_itoa_format(int n, t_padding *padinfo);
char	*chartostr(int c);
int		ft_writestr(char *s, char format, t_padding *padinfo);
int		getformat(const char *s, t_padding *padinfo);
int		printpreformatting(int strlen, t_padding *padinfo);
int		printpostformatting(int strlen, t_padding *padinfo);
int		ft_printf(const char *s, ...);

#endif
