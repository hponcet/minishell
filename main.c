/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:55:44 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/03 15:48:16 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*buf;
	char	**cmd;
	t_env	*lenv;

	ac = 0;
	av = NULL;
	ft_printf(" "__bld __CYA __PROMPT_NAME__ end__ __bld __WHT" ࿓  "end__);
	while (get_next_line(0, &buf) >= 0)
	{
		cmd = ms_get_cmd(buf);
		lenv = ms_get_env(env);
		ms_exec(cmd, lenv);
		ft_printf(" "__bld __CYA __PROMPT_NAME__ end__ __bld __WHT" ࿓  "end__);
	}
	return (1);
}
