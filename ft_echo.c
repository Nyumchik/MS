/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:59:22 by gjohana           #+#    #+#             */
/*   Updated: 2022/07/01 18:06:02 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_all(char **cmd, int fd_out)
{
	int	i;

	i = -1;
	while (cmd && cmd[++i])
	{
		ft_putstr_fd(cmd[i], fd_out);
		if (cmd[i + 1])
			ft_putstr_fd(" ", fd_out);
	}
}

int	nl_echo(char *s)
{
	int	i;

	i = 0;
	while (s && s[0] == '-' && s[++i])
		if (s[i] != 'n')
			return (0);
	if (s && s[1] == 'n' && !s[i])
		return (1);
	return (0);
}

int	ft_echo(char **cmd, int fd_out)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (cmd && cmd[i] && nl_echo(cmd[i]))
	{
		i++;
		flag = 1;
	}
	if (!flag && !cmd[i])
		ft_putstr_fd("\n", fd_out);
	else if ((!flag && cmd[i][0] == '-'))
		ft_putstr_fd("-", fd_out);
	else
		print_all(&cmd[i], fd_out);
	if (!flag && (cmd[i] || !i))
		ft_putstr_fd("\n", fd_out);
	return (0);
}
