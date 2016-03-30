/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:55:44 by hponcet           #+#    #+#             */
/*   Updated: 2016/03/30 17:57:41 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av, char **env)
{
	char	*buf;
	char	*ms_name;

	ac = 0;
	av = NULL;
	ms_name = ft_strdup("ms$> ");
	ft_putstr(ms_name);
	while (get_next_line(0, &buf) > 0)
	{
		ms_get_cmd(buf, env);
		ft_putstr(ms_name);
	}
	return (1);
}
