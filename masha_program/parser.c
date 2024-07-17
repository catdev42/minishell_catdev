/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:05 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/17 22:30:48 by myakoven         ###   ########.fr       */
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
			if (!handle_command(&matrix[i], tools))
				error_exit(tools, 1);
		i++;
	}
	return (1);
}

int	handle_command(char **line, t_tools *tools)
{
	int		i;
	char	*full_line;
	int		expand_len;
	char	*env_var;
	char	*variable_alloc;
	int		j;

	i = 0;
	expand_len = 0;
	full_line = *line;
	env_var = NULL;
	while (full_line[i])
	{
		if (full_line[i] == '$')
		{
			i++;
			j = 0;
			while (full_line[i + j] && !ft_isspace(full_line[i + j]))
				j++;
			if (j > 0)
				variable_alloc = ft_substr(full_line, i, j);
			
			if (is_expand(full_line, i))
				env_var = get_var(tools->env, variable_alloc);
			else
				free()
		}
		i++;
	} // *line = newthing;
}

// check for single quptes and stuff, returns 1 if should expand
int	is_expand(char *line, int index)
{
}

/* cleans the first spaces of a command and puts 0's at the end;
returns 1 on sucess */
int	spaces_cleanup(t_tools *tools)
{
	int		i;
	int		j;
	int		len;
	char	**matrix;

	matrix = tools->lexed;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		len = ft_strlen(matrix[i]);
		while (matrix[i][j])
		{
			if (matrix[i][j] == "\"")
				while ((matrix[i][j]) == "\"" && (matrix[i][j]) == "\"")
					j += 2;
			// j = 0;
			if (ft_isspace(matrix[i][j]))
				while (ft_isspace(matrix[i][j++]))
					;
			if (!ft_strlen(matrix[i]))
				break ;
		}
		if (j > 0)
		{
			ft_memmove(&matrix[i][0], &matrix[i][j], len - j);
			j = len - j;
			while (j < len)
				matrix[i][j++] = 0;
		}
		i++;
	}
	return (1);
}

int	isquote(char c)
{
	return (c == "\'|")
}
