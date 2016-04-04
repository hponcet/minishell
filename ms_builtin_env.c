/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 08:09:30 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/04 13:51:59 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

void	ms_builtin_env(char **cmd, t_env **env)
{
	if(!(cmd = ms_del_cmd(cmd, 1)))
	{
		ms_print_env(env);
		return;
	}
	while (cmd && cmd[0])
	{
		if (cmd[0][0] == '-')
		{
			cmd[0] = ft_strcut(cmd[0], 1);
			cmd = ms_builtin_env_opt(cmd, env);
		}

		if (ft_cindex(cmd[0], '=') > -1)
		{
			cmd = ms_builtin_setenv(cmd, env);
			break ;
		}
	}
	if (cmd)
		ms_exec(cmd, *env);
	else
		ms_print_env(env);
}

char	**ms_builtin_setenv(char **cmd, t_env **env)
{
	t_env	*tmp;
	t_env	*list;
	int		i;

	if (cmd[0][0] == '=' && cmd[0][1] != '\0')
	{
		cmd[0] = ft_strcut(cmd[0], 1);
		return (cmd);
	}
	if (cmd[0][0] == '=' && cmd[0][1] == '\0')
	{
		ft_printf("env: setenv =: Invalid argument\n");
		cmd = ms_free_tab(cmd);
		ms_free_env(env);
		return (cmd);
	}
	i = ft_cindex(cmd[0], '=');
	if (!(list = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	list->value = ft_strdup(cmd[0]);
	list->next = NULL;
	tmp = *env;
	if (!tmp)
	{
		*env = list;
		cmd = ms_del_cmd(cmd, 1);
		return (cmd);
	}
	while (tmp->next)
	{
		if (ft_strncmp(cmd[0], tmp->value, i) == 0 && tmp->value[i] == '=')
		{
			free(tmp->value);
			tmp->value = ft_strdup(cmd[0]);
			cmd = ms_del_cmd(cmd, 1);
			return (cmd);
		}
		tmp = tmp->next;
	}
	tmp->next = list;
	cmd = ms_del_cmd(cmd, 1);
	return (cmd);
}

char	**ms_builtin_env_opt(char **cmd, t_env **env)
{
	if (cmd[0][0] == 'i')
	{
		if (cmd[0][1] != '\0')
			cmd[0] = ft_strcut(cmd[0], 1);
		else
		{
			if (!cmd[1])
				cmd = ms_free_tab(cmd);
			else
				cmd = ms_del_cmd(cmd, 1);
		}
		ms_free_env(env);
	}
	else if (cmd[0][0] == 'u')
		cmd = ms_builtin_env_opt_u(cmd, env);
	else
	{
		ft_printf("\x1B[32m"__PROMPT_NAME__": illegal option -- %c\n", cmd[0][0]);
		ft_printf(" usage: env [-i] [-u name] [name=value ...]\n");
		cmd = ms_free_tab(cmd);
		ms_free_env(env);
	}
	return (cmd);
}

char	**ms_builtin_env_opt_u(char **cmd, t_env **env)
{
	if (cmd[0][1] != '\0')
	{
		cmd[0] = ft_strcut(cmd[0], 1);
		if (env)
			cmd = ms_builtin_env_opt_u_exec(cmd, env);
	}
	else
	{
		if (!cmd[1])
		{
			ft_printf(__PROMPT_NAME__": illegal option -- u\n");
			ft_printf(" usage: env [-i] [-u name] [name=value ...]\n");
			ms_free_env(env);
			cmd = ms_free_tab(cmd);
			return (cmd);
		}
		cmd = ms_del_cmd(cmd, 1);
		if (env)
			cmd = ms_builtin_env_opt_u_exec(cmd, env);
	}
	return (cmd);
}

char	**ms_builtin_env_opt_u_exec(char **cmd, t_env **env)
{
	t_env	*tmp;
	t_env	*prev;

	prev = *env;
	if (ft_strncmp(cmd[0], prev->value, ft_strlen(cmd[0])) == 0)
	{
		if (prev->value[ft_strlen(cmd[0])] == '=')
		{
			*env = prev->next;
			free(prev);
		}
		cmd = ms_del_cmd(cmd, 1);
		return (cmd);
	}
	tmp = prev->next;
	while (tmp)
	{
		if (ft_strncmp(cmd[0], tmp->value, ft_strlen(cmd[0])) == 0)
		{
			if (tmp->value[ft_strlen(cmd[0])] == '=')
			{
				prev->next = tmp->next;
				free(tmp);
			}
			cmd = ms_del_cmd(cmd, 1);
			return (cmd);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	cmd = ms_del_cmd(cmd, 1);
	return (cmd);
}

char	**ms_del_cmd(char **cmd, int l)
{
	int		len;
	char	**ncmd;

	len = 0;
	ncmd = NULL;
	while (cmd[len])
		len++;
	if (len - l < 1)
	{
		cmd = ms_free_tab(cmd);
		return (NULL);
	}
	if (!(ncmd = (char**)malloc(sizeof(char*) * len - l + 1)))
		return (NULL);
	ncmd[len - l] = NULL;
	len = 0;
	while (cmd[l])
	{
		ncmd[len] = ft_strdup(cmd[l]);
		l++;
		len++;
	}
	cmd = ms_free_tab(cmd);
	return (ncmd);
}

void	ms_print_env(t_env **env)
{
	t_env	*tmp;

	if (!env || !*env)
		return ;
	tmp = *env;
	while (tmp)
	{
		ft_putendl(tmp->value);
		tmp = tmp->next;
	}
	ms_free_env(env);
}
