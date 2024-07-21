/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:05 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/21 15:44:09 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	parser(t_tools *tools)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = tools->lexed;
	// spaces_cleanup(tools);
	while (matrix[i])
	{
		if (!istoken(matrix[i][0]))
			if (!expand_command(&matrix[i], tools))
				error_exit(tools, 1);
		i++;
	}
	return (1);
}





//DON'T NEED?
// /* cleans the first spaces of a command and puts 0's at the end;
// returns 1 on sucess */
// int	spaces_cleanup(t_tools *tools)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	**matrix;

// 	matrix = tools->lexed;
// 	i = 0;
// 	while (matrix[i])
// 	{
// 		j = 0;
// 		len = ft_strlen(matrix[i]);
// 		while (matrix[i][j])
// 		{
// 			if (matrix[i][j] == "\"")
// 				while ((matrix[i][j]) == "\"" && (matrix[i][j]) == "\"")
// 					j += 2;
// 			// j = 0;
// 			if (ft_isspace(matrix[i][j]))
// 				while (ft_isspace(matrix[i][j++]))
// 					;
// 			if (!ft_strlen(matrix[i]))
// 				break ;
// 		}
// 		if (j > 0)
// 		{
// 			ft_memmove(&matrix[i][0], &matrix[i][j], len - j);
// 			j = len - j;
// 			while (j < len)
// 				matrix[i][j++] = 0;
// 		}
// 		i++;
// 	}
// 	return (1);
// }
