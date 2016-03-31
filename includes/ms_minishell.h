/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:35:06 by hponcet           #+#    #+#             */
/*   Updated: 2016/03/31 15:06:06 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_MINISHELL_H
# define MS_MINISHELL_H
# include "libft.h"
# include "get_next_line.h"

#define DEBUG ft_printf("__DEBUG : %s : line %d\n", __FILE__, __LINE__);

typedef struct		s_env
{
	char			**path;
	char			*home;
	char			*user;
	char			*pwd;
}					t_env;

t_env				g_env;

int					ms_get_nbc(char *buf);
char				**ms_get_cmd(char *buf);
void				ms_get_env(char **env);

int					ms_exec(char *buf, char **env);
char				*ms_search_bin(char *cmd);

#endif
