/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:55:44 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/04 15:44:33 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*buf;
	char	**cmd;
	t_env	*lenv;
	char	*ms_name;

	ac = 0;
	av = NULL;
	ms_name = ms_shell_name();
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

char	*ms_shell_name(void)
{
	char	*name;

	name = ft_strdup(__PROMPT_NAME__);
	if (!name[0])
	{
		free(name);
		name = ft_strdup("ms$> ");
	}
	return (name);
}
