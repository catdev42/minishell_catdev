/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:22:37 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/14 20:53:28 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//changes added error 3
int	error_exit(t_tools *tools, int error)
{
	clean_tools(tools);
	clear_history();
	if (error == 1)
	{
		perror("Problem with malloc");
		exit(1);
	}
	else if (error == 2)
	{
		perror("Unclosed quotes, please try again");
		exit(1);
	}
	else if (error == 3)
	{
		// perror("Control D was pressed");
		exit(0);
	}
	return (1);
}
void	clean_tools(t_tools *tools)
{
	if (tools->env)
		ft_freetab(tools->env, INT_MAX);
	if (tools->line)
		free(tools->line);
}

char	**free_array(char **res, int nb)
{
	int	i;

	i = 0;
	if (!res)
		return (NULL);
	while (i <= nb && res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}
