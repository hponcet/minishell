/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:30:37 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/02 17:45:10 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ms_minishell.h"

void	ms_builtin_env(char **cmd, t_env **env)
{
	int		i;
	int		j;
	int		u;
	char	**ncmd;
	t_env	*tmp;

	u = 0;
	i = 1;
	j = 1;
	DEBUG
	while (cmd[i + u] && cmd[i + u][0] == '-')
	{
		DEBUG
		while (cmd[i + u][j])
		{
			DEBUG
			if (cmd[i + u][j] == 'i')
			{
				ms_free_env(*env);
				*env = NULL;
			}
			else if (cmd[i + u][j] == 'u' && cmd[i + u][j + 1] != 'i')
			{
				DEBUG
				tmp = *env;
				// Cas ou il n'y a rien apres u
				if (!cmd[i + u + 1])
				{
					ft_printf("env: illegal option -- u\n usage: env [-i] [-u name] [name=value ...]");
					return ;
				}
				if (tmp && ft_strncmp(tmp->value, cmd[i + u + 1], ft_strlen(cmd[i + u + 1])) == 0)
				{
					DEBUG
					free(tmp->value);
					tmp->value = NULL;
					*env = tmp->next;
					DEBUG
				}
				else
				{
					while (tmp->next && ft_strncmp(tmp->next->value, cmd[i + u + 1], ft_strlen(cmd[i + u + 1])) != 0)
						tmp = tmp->next;
					if (tmp->next)
					{
						DEBUG
						free(tmp->next->value);
						tmp->next->value = NULL;
						tmp->next = tmp->next->next;
					}
					DEBUG
				}
				DEBUG
				u++;
			}
			else
			{
				ft_printf("env: illegal option -- %c\n usage", cmd[i + u][j]);
				ft_printf(": env [-i] [-u name] [name=value ...]");
				return ;
			}
			j++;
		}
		i++;
	}
	DEBUG
	if (cmd[i + u] == NULL)
	{
		DEBUG
		tmp = *env;
		while (tmp)
		{
			ft_putendl(tmp->value);
			tmp = tmp->next;
		}
		DEBUG
		ms_free_env(*env);
	}
	else
	{
		DEBUG
		ncmd = ms_copy_tab(cmd + (i + u));
		free(cmd);
		ms_exec(ncmd, *env);
	}
}
