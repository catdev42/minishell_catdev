/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/08/28 23:55:05 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clean_line(char *line, int linelen, t_tools *tools)
{
	char	*c_line;
	int		i;
	int		j;
	int		c_len;

	init_zero(&i, &j, NULL, &c_line);
	c_len = linelen * 2;
	c_line = ft_calloc(c_len + 2, 1);
	if (!c_line)
		error_exit(tools, 1);
	while (line[i] && j < c_len)
	{
		if (line[i] == '\'' || line[i] == '"')
			i = i + copy_quotes(&c_line[j], &line[i]);
		else if (line[i] == '|')
			i = i + copy_pipe(&c_line[j], &line[i], i);
		else if (line[i] == '>' || line[i] == '<')
			i = i + copy_redirect(&c_line[j], &line[i], i);
		else if (ft_isspace(line[i]))
			i = i + copy_spaces(&c_line[j], &line[i]);
		else
			c_line[j++] = line[i++];
		j = ft_strlen(c_line);
	}
	return (c_line);
}

int	copy_spaces(char *c_line, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_isspace(line[i]))
	{
		c_line[j++] = line[i++];
		while (ft_isspace(line[i]))
			i++;
	}
	return (i);
}

int	copy_quotes(char *c_line, char *line)
{
	char	quote_char;
	int		i;
	int		j;

	i = 0;
	j = 0;
	quote_char = line[i];
	c_line[j++] = line[i++];
	while (line[i] && line[i] != quote_char)
		c_line[j++] = line[i++];
	c_line[j++] = line[i++];
	i = i + copy_spaces(&c_line[j], &line[i]);
	return (i);
}

int	copy_pipe(char *c_line, char *line, int current_line_index)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (current_line_index > 0)
		if (!ft_isspace(c_line[j - 1]))
			c_line[j++] = ' ';
	c_line[j++] = line[i++];
	if (!ft_isspace(line[i]))
		c_line[j++] = ' ';
	i = i + copy_spaces(&c_line[j], &line[i]);
	return (i);
}

int	copy_redirect(char *c_line, char *line, int current_line_index)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (current_line_index > 0)
		if (c_line[i - 1] != ' ')
			c_line[j++] = ' ';
	while (line[i] == '>' || line[i] == '<')
		c_line[j++] = line[i++];
	if (line[i - 1] == '>' || line[i - 1] == '<')
		while (ft_isspace(line[i]))
			i++;
	i = i + copy_spaces(&c_line[j], &line[i]);
	return (i);
}
