/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:13:16 by spitul            #+#    #+#             */
/*   Updated: 2024/07/15 00:01:40 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Wanted to make a note on this for later:

	c4a6c10% pwd ok
	pwd: too many arguments

	After the have the 2d command array maybe we can stick it in there?

	void	pwd(t_tools *tools, char **cmd)?

	i have to change all my perrors to ft_putstr_fd(str, 2) - oops

*/

void	pwd(t_tools *tools)
{
	char	*pos;
	size_t	i;

	i = 0;
	pos = get_env_var(tools, "PWD");
	if (pos != NULL)
	{
		ft_putstr_fd(pos, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		// perror("pwd: error retrieving current directory:");
		ft_putstr_fd("pwd: error retrieving current directory\n", 2);
}
