/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:14:22 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/28 15:12:52 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdint.h>

char	*getstr_hex(long long int n, int ptr, char format);
char	*ft_ptrtoa(uintptr_t ptr);
char	*ft_uitoa(unsigned int n);
void	ft_writestr(char *s);
int		ft_printf(const char *s, ...);

#endif
