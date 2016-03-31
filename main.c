/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:55:44 by hponcet           #+#    #+#             */
/*   Updated: 2016/03/31 15:03:18 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*buf;
	char	*ms_name;

	ac = 0;
	av = NULL;
	ms_name = ft_strdup("ms$> ");
	ft_putstr(ms_name);
	while (get_next_line(0, &buf) >= 0)
	{
		ms_exec(buf, env);
		ft_putstr(ms_name);
	}
	return (1);
}
