/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:35:06 by hponcet           #+#    #+#             */
/*   Updated: 2016/03/30 20:43:08 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_GET_CMD_H
# define MS_GET_CMD_H
# include "libft.h"

typedef struct		s_env
{
	char			**g_path;
	char			*home;
	char			*user;
	char			*pwd;
}					t_env;

int					ms_get_nbc(char *buf);
char				**ms_get_cmd(buf);
int					ms_get_env(char **env);


#endif
