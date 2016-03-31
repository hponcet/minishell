/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 07:24:49 by hponcet           #+#    #+#             */
/*   Updated: 2016/03/31 15:15:10 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

int			ms_exec(char *buf, char **env)
{
	char	**cmd;
	char	*pathbin;
	int		i;

	i = 0;
	cmd = NULL;
	cmd = ms_get_cmd(buf);
	ms_get_env(env);
	pathbin = ms_search_bin(cmd[0]);
	if (pathbin)
		ft_putendl(pathbin);
	else
		return (0);
	return (1);
}

char		*ms_search_bin(char *cmd)
{
	char	*pathbin;
	char	*tmp;
	int		i;

	i = 0;
	while (g_env.path[i])
	{
		tmp = g_env.path[i];
		pathbin = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = pathbin;
		pathbin = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(pathbin, X_OK) > -1)
			return (pathbin);
		else
			i++;
		free(pathbin);
	}
	return (NULL);
}
