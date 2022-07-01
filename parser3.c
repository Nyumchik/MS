/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:32:29 by gjohana           #+#    #+#             */
/*   Updated: 2022/07/01 22:36:19 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syn_error_check(char *str, char a)
{
	int		i;
	int		sq;
	int		dq;

	sq = 1;
	dq = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && ft_strchr(SEP, str[i]))
		i++;
	if (str[i] == a || syn_error_util(str, a, &sq, &dq) < 0)
	{
		write(2, "syntax error\n", ft_strlen("syntax error\n"));
		return (-1);
	}
	if (dq == -1 || sq == -1)
	{
		write(2, "quote error\n", ft_strlen("quote error\n"));
		return (-1);
	}
	return (0);
}
