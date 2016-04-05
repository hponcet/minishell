/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:16:11 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/05 19:20:43 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

void	ms_builtin_cd(char **cmd, t_env *env)
{
	char	*home;
	char	*tmp;

	cmd = ms_del_cmd(cmd, 1);
	tmp = ms_get_home(env);
	if (cmd && ft_strcmp(cmd[0], "..") != 0 && ft_strcmp(cmd[0], ".") != 0)
		home = ft_strjoin(tmp, cmd[0]);
	if (ft_strcmp(cmd[0], "..") == 0)
		home = ms_builtin_cd_up(tmp);
	free(tmp);
	tmp = NULL;
	if (!home[0])
	{
		ft_printf("cd: environement for HOME is not set");
		cmd = ms_free_tab(cmd);
		return ;
	}
	if (chdir(home) < 0)
		ft_printf("cd: no such file or directory:%s\n", cmd[0]);
	cmd = ms_free_tab(cmd);
}

char	*ms_builtin_cd_up(char *path)
{

}

char	*ms_get_home(t_env *env)
{
	t_env	*tmp;
	char	*home;

	home = NULL;
	tmp = env;
	while (tmp && ft_strncmp(tmp->value, "HOME=", 5) != 0)
		tmp = tmp->next;
	if (tmp && ft_strncmp(tmp->value, "HOME=", 5) == 0)
		home = ft_strdup(tmp->value + 5);
	if (!home)
	{
		home = ft_strdup(__DEFAULT_HOME__);
		return (home);
	}
	return (home);
}
