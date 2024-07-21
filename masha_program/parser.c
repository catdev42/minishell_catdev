/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:05 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/21 21:45:28 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	parser(t_tools *tools)
{
	int		i;
	char	**matrix;
	int		comm_index;
	int		num_words;

	i = 0;
	comm_index = 0;
	matrix = tools->lexed;
	// spaces_cleanup(tools);
	while (matrix[i])
	{
		while (ft_strchr(matrix[i], '$'))
			if (!expand_command(&matrix[i], tools))
				error_exit(tools, 1);
		i++;
	}
	i = 0;
	tools->parsed = ft_calloc((tools->num_pipes + 1), sizeof(t_parsed *));
	/* !!!!! */
	while (matrix[i])
	{
		if (istoken(matrix[i][0]))
			handle_token(tools, i);
		else
			handle_command(tools, i);
		i++;
	}
	return (1);
}

int	write_command_matrix(t_tools *tools, int command_index)
{
	char	*line;
	int		i;
	int		count;

	line = NULL;
	line = make_full_line(tools);
	i = 0;
	count = count_arguments(line);
	tools->parsed_commands[command_index]->argv =
	// count words
	// while (line[i])
	// {
	// 	while (ft_isspace())
	// 		i++;
	// 	if (line[i] == "\"" || line[i] == "\'")
	// 	{
	// 		i = check_quotes(line, i);
	// 		count++;
	// 	}
	// }
}

char	**create_argv(t_tools *tools, char *line, int c_index)
{
	int		i;
	int		j;
	int		k;
	int		in_quotes;
	char	quote_char;

	i = 0;
	j = 0;
	k = 0;
	// line = make_full_line(tools);
	tools->parsed_commands[c_index].argc = count_arguments(line);
	tools->parsed_commands[c_index].argv = ft_calloc((tools->parsed_commands[c_index].argc
				+ 1), sizeof(char *));
	in_quotes = 0;
	quote_char = '\0';
	while (line[i])
	{
		while (isspace(line[i]))
			i++;
		if (line[i] == '\0')
			break ;
		j = i;
		while (line[i] && (!isspace(line[i]) || in_quotes))
		{
			if ((line[i] == '"' || line[i] == '\'') && !in_quotes)
			{
				in_quotes = 1;
				quote_char = line[i];
			}
			else if (line[i] == quote_char && in_quotes)
			{
				in_quotes = 0;
				quote_char = '\0';
			}
			i++;
		}
		argv[k] = strndup(&line[j], i - j);
		k++;
	}
	argv[k] = NULL;
	return (argv);
}

int	count_arguments(char *line)
{
	int		count;
	int		i;
	int		in_quotes;
	char	quote_char;

	count = 0;
	i = 0;
	in_quotes = 0;
	quote_char = '\0';
	while (line[i])
	{
		while (isspace(line[i]))
			i++;
		if (line[i] == '\0')
			break ;
		count++;
		while (line[i] && (!isspace(line[i]) || in_quotes))
		{
			if ((line[i] == '"' || line[i] == '\'') && !in_quotes)
			{
				in_quotes = 1;
				quote_char = line[i];
			}
			else if (line[i] == quote_char && in_quotes)
			{
				in_quotes = 0;
				quote_char = '\0';
			}
			i++;
		}
	}
	return (count);
}

// char	**quotes_split(line)
// {
// 	int	i;
// char **matrix;
// 	i = 0;
// 	if (line[i] == "\"" || line[i] == "\'")

// }
// int	write_command_matrix(t_tools *tools)
// {
// }

char	*make_full_line(t_tools *tools)
{
	int		i;
	int		j;
	char	*command;
	int		comm_index;

	command = NULL;
	i = 0;
	j = 0;
	comm_index = 0;
	// make full line
	while (tools->lexed[i] && tools->lexed[i][0] != '|')
	{
		if (!istoken(tools->lexed[i][0] && j > 0))
		{
			tools->lexed[comm_index] = ft_strjoin(command, tools->lexed[i]);
			if (tools->lexed[comm_index] == NULL)
				error_exit(tools, 1);
			ft_bzero(tools->lexed[i], ft_strlen(tools->lexed[i]));
			free(command);
			command = tools->lexed[comm_index];
			j++;
		}
		else if (!istoken(tools->lexed[i][0]) && j == 0)
		{
			command = tools->lexed[i];
			comm_index = i;
			j++;
		}
		i++;
	}
	ft_bzero(tools->lexed[i], ft_strlen(tools->lexed[i]));
	return (command);
}

// DON'T NEED?
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
