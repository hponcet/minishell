/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:55:44 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/02 15:24:53 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*buf;
	char	**cmd;
	char	*ms_name;
	t_env	*lenv;

	ac = 0;
	av = NULL;
	ms_name = ft_strdup("ms$> ");
	ft_putstr(ms_name);
	while (get_next_line(0, &buf) >= 0)
	{
		cmd = ms_get_cmd(buf);
		lenv = ms_get_env(env);
		ms_exec(cmd, lenv);
		ft_putstr(ms_name);
	}
	return (1);
}
