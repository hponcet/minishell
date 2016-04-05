/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:55:44 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/05 17:14:13 by hponcet          ###   ########.fr       */
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
	lenv = NULL;
	ms_name = ms_shell_name();
	ft_putstr(ms_name);
	g_env = ms_get_env(env);
	while (get_next_line(0, &buf) >= 0)
	{
		lenv = ms_copy_env(g_env);
		cmd = ms_get_cmd(buf);
		ms_exec(cmd, lenv);
		ft_putstr(ms_name);
	}
	return (1);
}

t_env	*ms_copy_env(t_env *env)
{
	t_env	*tmp;
	t_env	*list;
	t_env	*ret;
	t_env	*tmp2;

	tmp2 = env;
	if (!env)
		return (NULL);
	list = (t_env*)malloc(sizeof(t_env));
	list->next = NULL;
	list->value = ft_strdup(tmp2->value);
	tmp = list;
	ret = tmp;
	tmp2 = tmp2->next;
	while (tmp2)
	{
		if (!(list = (t_env*)malloc(sizeof(t_env))))
			return (NULL);
		list->next = NULL;
		list->value = ft_strdup(tmp2->value);
		tmp->next = list;
		tmp = list;
		tmp2 = tmp2->next;
	}
	return (ret);
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
