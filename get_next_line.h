/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:59:47 by hponcet           #+#    #+#             */
/*   Updated: 2016/02/11 13:35:54 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"

int		get_next_line(int const fd, char **line);
int		ft_afternext(char **afternext, char **line);
void	ft_tormoilzboub(char *buf, int eof, char **line, char **afternext);

#endif
