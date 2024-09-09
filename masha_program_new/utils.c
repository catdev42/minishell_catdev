/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:15:14 by myakoven          #+#    #+#             */
/*   Updated: 2024/09/04 00:12:13 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/* PRINTS A 2D ARRAY*/
int	print_tab(char **envp)
{
	size_t	i;

	i = 0;
	if (!envp || !*envp)
		return (0);
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (1);
}

int	istoken(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	isquote(char c)
{
	return (c == '\'' || c == '\"');
}


int	get_matrix_len(char **matrix)
{
	int	i;

	if (!matrix || !*matrix)
		return (0);
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}


// /* Returns the number of spaces to skip -> add this to current index */
// int	skip_spaces(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s || !*s)
// 		return (0);
// 	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
// 		i++;
// 	return (i);
// }
