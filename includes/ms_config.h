/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 12:48:34 by hponcet           #+#    #+#             */
/*   Updated: 2016/04/04 15:44:39 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_CONFIG_H
# define MS_CONFIG_H

/* ***************************
** Default path if env is NULL
** ***************************
** In this case, separate paths with ':' if some
** paths are required.
*/
# define __DEFAULT_PATH__ "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

/* ********************
** Name of prompt shell
** ********************
** You can find all the declensions of colors and
** text formatting in the file "../libft/includes
** /ft_colors.h"
*/
# define __PROMPT_NAME__ __GRN"✱  "end__ __bld __CYA"Minishɘll" end__" "

#endif
