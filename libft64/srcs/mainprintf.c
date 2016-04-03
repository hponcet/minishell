/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:14:57 by hponcet           #+#    #+#             */
/*   Updated: 2016/03/20 19:01:03 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <locale.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>
int		main(void)
{
	int i = 0;
	char	*str;
	str = ft_strdup("coucou");
	//unsigned int	str = -42;
	char *env;
	char c;
	
	env = setlocale(LC_ALL, "en_US.UTF-8");

	i = ft_printf("{%05s}", "abc");
	ft_putendl("");
	ft_putnbr(i), ft_putendl("");
	//
	i =    printf("{%05s}", "abc");
	ft_putnbr(i), ft_putendl("");
	//ft_printf("{%30S}", L"我是一只猫。");
	   //printf("{%30S}", L"我是一只猫。");

	
	return (0);
}
