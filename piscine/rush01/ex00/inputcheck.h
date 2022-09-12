/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inputcheck.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 20:00:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/07/17 16:49:18 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTCHECK_H
# define INPUTCHECK_H

int		getnumberofintegers(char *argv);
void	getinput(char *argv, int *input);
int		isvalidinput(int *input, int size);

#endif