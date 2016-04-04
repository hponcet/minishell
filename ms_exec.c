/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 07:24:49 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/04 19:21:59 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void		ms_exec(char **cmd, t_env *env)
{
	char	*pathbin;
	int		i;

	i = 0;
	if (!cmd || !cmd[0])
		return ;
	if (ms_search_builtin_cmd(cmd, env) > 0)
		return ;
	if ((pathbin = ms_search_bin(cmd[0], env)) != NULL)
		ms_exec_bin(cmd, pathbin, env);
	else
		ft_printf("ms: command not found: %s\n", cmd[0]);
}

char		*ms_search_bin(char *cmd, t_env *env)
{
	char	*pathbin;
	char	*tmp;
	int		i;
	char	**path;

	i = 0;
	path = ms_get_path(env);
	while (path[i])
	{
		tmp = path[i];
		pathbin = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = pathbin;
		pathbin = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(pathbin, X_OK) > -1)
		{
			free(path);
			return (pathbin);
		}
		i++;
		free(pathbin);
	}
	return (NULL);
}

void		ms_exec_bin(char **cmd, char *pathbin, t_env *env)
{
	int		i;
	char	**lenv;
	pid_t	pid;

	lenv = ms_convert_env(env);
	i = 0;
	pid = fork();
	if (pid > 0)
		wait(&i);
	if (pid == 0)
		execve(pathbin, cmd, lenv);
	ms_free_tab(lenv);
	ms_free_env(&env);
}

int			ms_search_builtin_cmd(char **cmd, t_env *env)
{
	if (ft_strcmp(cmd[0], "env") == 0)
	{
		ms_builtin_env(cmd, &env);
		return (1);
	}
	else if (ft_strcmp(cmd[0], "cd") == 0)
	{
		ms_builtin_cd(cmd);
		return (1);
	}
	else if (ft_strcmp(cmd[0], "exit") == 0 || ft_strcmp(cmd[0], ":q") == 0)
		exit(0);

	return (0);
}
