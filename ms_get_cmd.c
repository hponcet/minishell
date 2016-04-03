/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:27:06 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/03 22:29:01 by hponcet          ###   ########.fr       */
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

t_env		*ms_get_env(char **env)
{
	int		i;
	t_env	*list;
	t_env	*tmp;
	t_env	*ret;

	i = 0;
	ret = NULL;
	while (env[i])
	{
		if (!(list = (t_env*)malloc(sizeof(t_env))))
			return (NULL);
		list->value = ft_strdup(env[i]);
		list->next = NULL;
		if (!ret)
			ret = list;
		else
		{
			tmp = ret;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = list;
		}
		i++;
	}
	return (ret);
}

char		**ms_convert_env(t_env *env)
{
	size_t		i;
	char	**ret;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	ret = (char**)malloc(sizeof(char*) * i + 1);
	ret[i] = NULL;
	i = 0;
	while (tmp)
	{
		ret[i] = ft_strdup(tmp->value);
		i++;
		tmp = tmp->next;
	}
	return (ret);
}

char		**ms_get_path(t_env *env)
{
	t_env	*tmp;
	char	**path;

	path = NULL;
	tmp = env;
	while (tmp && ft_strncmp(tmp->value, "PATH=", 5) != 0)
		tmp = tmp->next;
	if (tmp && ft_strncmp(tmp->value, "PATH=", 5) == 0)
		path = ft_strsplit(tmp->value + 5, ':');
	if (!path)
	{
		path = ft_strsplit(__DEFAULT_PATH__, ':');
		return (path);
	}
	return (path);
}

char		**ms_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (NULL);
}

void		ms_free_env(t_env **env)
{
	while (*env)
	{
		free((*env)->value);
		(*env)->value = NULL;
		*env = (*env)->next;
	}
	*env = NULL;
	env = NULL;
}

char		**ms_copy_tab(char **tab)
{
	char	**ret;
	int		i;

	ret = NULL;
	i = 0;
	while (tab[i])
		i++;
	if (!(ret = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	ret[i] = NULL;
	i = 0;
	while (tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	return (ret);
}
