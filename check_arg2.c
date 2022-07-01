/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:22:06 by gjohana           #+#    #+#             */
/*   Updated: 2022/07/01 21:20:44 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str && str[i] && (str[i] == '|' || str[i] == '&'))
	{
		p_error(str[i]);
		g_all.orand = 1;
	}
}

void	split_f(char **s, char no_splt)
{
	int	i;
	int	j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (s[i][j] == -2)
				s[i][j] = no_splt;
	}
}

char	**ft_split_shell(char *l, char no_splt)
{
	int		i;
	char	**splt;

	i = -1;
	splt = ft_split(l, no_splt);
	split_f(splt, no_splt);
	return (splt);
}

void	ft_norm2(char *line, int *a)
{
	*a = check_or_and(line);
	free(g_all.herd);
	g_all.herd = NULL;
	if (*a == 0)
		g_all.herd = ft_strdup("cmdand> ");
	else if (*a == -1)
		g_all.herd = ft_strdup("cmdor> ");
}
