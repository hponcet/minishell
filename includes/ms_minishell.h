/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:35:06 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/02 14:07:50 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_MINISHELL_H
# define MS_MINISHELL_H
# include "libft.h"
# include "get_next_line.h"

#define DEBUG ft_printf("__DEBUG : %s : line %d\n", __FILE__, __LINE__);

typedef struct		s_env
{
	char			*value;
	struct s_env	*next;
}					t_env;

int					ms_get_nbc(char *buf);
t_env				*ms_get_env(char **env);
char				**ms_get_cmd(char *buf);
char				**ms_get_path(t_env *env);
char				**ms_convert_env(t_env *env);
void				ms_free_tab(char **tab);
void				ms_free_env(t_env *env);
char				**ms_copy_tab(char **tab);

void				ms_exec(char **cmd, t_env *env);
void				ms_exec_bin(char **cmd, char *pathbin, t_env *env);
char				*ms_search_bin(char *cmd, t_env *env);
int					ms_search_builtin_cmd(char **cmd, t_env *env);

void				ms_builtin_env(char **cmd, t_env **env);

#endif
