/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:27:06 by hponcet           #+#    #+#             */
/*   Updated: 2016/03/31 15:03:51 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

int		ms_get_nbc(char *buf)
{
	size_t	count;
	size_t	i;
	
	count = 0;
	i = 0;
	while (buf[i])
	{
		while ((buf[i] == ' ' || buf[i] == '	') && buf[i])
		{
			if (buf[i + 1] && buf[i + 1] != ' ' && buf[i + 1] != '	')
				count++;
			i++;
		}
		while (buf[i] != ' ' && buf[i] != '	' && buf[i])
		{
			if (count == 0)
				count++;
			i++;
		}
	}
	return (count);
}

char	**ms_get_cmd(char *buf)
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
	if (!(cmd = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	cmd[len] = NULL;
	while (buf[i] && j < len)
	{
		while (buf[i] == ' ' || buf[i] == '	')
			i++;
		start = i;
		while (buf[i] != ' ' && buf[i] != '	' && buf[i] != '\0')
			i++;
		cmd[j] = ft_strsub(buf, start, (i - start));
		j++;
	}
	return (cmd);
}

void		ms_get_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			g_env.path = ft_strsplit(env[i] + 5, ':');
		else if (ft_strncmp(env[i], "HOME", 4) == 0)
			g_env.home = ft_strdup(env[i] + 5);
		else if (ft_strncmp(env[i], "USER", 4) == 0)
			g_env.user = ft_strdup(env[i] + 5);
		else if (ft_strncmp(env[i], "PWD", 3) == 0)
			g_env.pwd = ft_strdup(env[i] + 4);
		i++;
	}
}
