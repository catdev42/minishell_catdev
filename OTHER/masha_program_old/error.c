/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:22:37 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/21 20:04:00 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *errline, char *errarg)
{
	if (errline)
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(errline, 2);
		if (errarg)
		{
			ft_putstr_fd("`", 2);
			ft_putstr_fd(errarg, 2);
			ft_putstr_fd("\'", 2);
			free(errarg);
		}
		ft_putstr_fd("\n", 2);
	}
	return (0);
}

/*
1: malloc
2: quotes (changed behavior now, should delete)
3: control_D (changed behavior, should delete)
*/
int	error_exit(t_tools *tools, int error)
{
	clean_tools(tools);
	clear_history();
	if (error == 1)
	{
		ft_putstr_fd("minishell: Problem with malloc", 2);
		exit(1);
	}
	else if (error == 2)
	{
		ft_putstr_fd("minishell: Unclosed quotes, please try again", 2);
		exit(1);
	}
	else if (error == 3)
	{
		// ft_putstr_fd("Control D was pressed", 2);
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
