/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:27:06 by hponcet           #+#    #+#             */
/*   Updated: 2016/03/30 20:43:02 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

int		ms_get_nbc(char *buf)
{
	char	**cmd;
	int		i;
	int		nbc;

	i = 0;
	while (buf[i])
	{
		while (buf[i] != ' ' || buf[i] != '	')
			i++;
		if ((buf[i] == ' ' || buf[i] == '	') && buf[i + 1] != ' ' &&
		buf[i + 1] != '	' && buf[i + 1] != '\0')
			nbc++;
		i++;
	}
}

char	**ms_get_cmd(buf)
{
	char	**cmd;
	int		i;
	int		j;
	int		start;
	int		len;

	i = 0;
	j = 0;
	start = 0;
	len = ms_get_nbc(buf);
	if (!(cmd = (char**)malloc(sizeof(char*) * j + 1)))
		return (NULL);
	cmd[j] = NULL;
	while (buf[i] && j < len)
	{
		while (buf[i] == ' ' || buf[i] == '	')
			i++;
		start = i;
		while (buf[i] != ' ' && buf[i] != '	' && buf[i] != '\0')
			i++;
		tab[j++] = ft_strsub(s, start, (i - start));
	}
	return (tab);
}

int		ms_get_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			t_env->g_pass = ft_strsplit(env[i] + 5, ':');
		else if (ft_strncmp(env[i], "HOME", 4) == 0)
			t_env->home = ft_strdup(env[i] + 5);
		else if (ft_strncmp(env[i], "USER", 4) == 0)
			t_env->user = ft_strdup(env[i] + 5);
		else if (ft_strncmp(env[i], "PWD", 3) == 0)
			t_env->pwd = ft_strdup(env[i] + 4);
		i++;
	}
}

char		*ms_search_bin(char *cmd)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = t_env->g_path[i];
	tmp = ft_strjoin(tmp2, "/");
	free(tmp2);
	tmp
	t_env->g_path[i] = tmp;
}
