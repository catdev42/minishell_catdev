/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/08/22 17:50:03 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int		copy_quotes(char *c_line, char *line);
// int	copy_pipe(char *c_line, char *line, int current_line_index);
// char	*exp_c_line(char *cleanline, int *c_len, int extra_space);
// int		copy_redirect(char *c_line, char *line, int current_line_index);

char	*clean_line(char *line, int linelen, t_tools *tools)
{
	char	*c_line;
	int		i;
	int		j;
	int		c_len;

	init_zero(&i, &j, NULL, &c_line);
	c_len = linelen + 10;
	c_line = ft_calloc(c_len + 2, 1);
	if (!c_line)
		error_exit(tools, 1);
	while (line[i] && j < c_len)
	{
		if (i > 0 || j > 0)
			j = ft_strlen(c_line);
		if (c_len - j < (int)ft_strlen(line) + 10 - i)
			c_line = exp_c_line(c_line, &c_len, ft_strlen(line) - i + 20);
		if (line[i] == '\'' || line[i] == '"')
			i = i + copy_quotes(&c_line[j], &line[i]);
		else if (line[i] == '|')
			i = i + copy_pipe(&c_line[j], &line[i], i);
		else if (line[i] == '>' || line[i] == '<')
			i = i + copy_redirect(&c_line[j], &line[i], i);
		else
			c_line[j++] = line[i++];
	}
	return (c_line);
}

int	copy_quotes(char *c_line, char *line)
{
	char	quote_char;
	int		i;
	int		j;

	i = 0;
	j = 0;
	quote_char = line[i];
	// if (current_line_index > 0)
	// 	if (!isspace(line[i - 1]))
	// 		c_line[j++] = ' ';
	c_line[j++] = line[i++];
	while (line[i] && line[i] != quote_char)
		c_line[j++] = line[i++];
	c_line[j++] = line[i++];
	// if (!isspace(line[i]))
	// 	c_line[j++] = ' ';
	return (i);
}
int	copy_pipe(char *c_line, char *line, int current_line_index)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (current_line_index > 0)
		if (!isspace(line[i - 1]))
			c_line[j++] = ' ';
	c_line[j++] = line[i++];
	if (!isspace(line[i]))
		c_line[j++] = ' ';
	return (1);
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
		while (isspace(line[i]))
			i++;
	return (i);
}

char	*exp_c_line(char *cleanline, int *c_len, int extra_space)
{
	char *new_cleanline;

	new_cleanline = ft_calloc(ft_strlen(cleanline) + extra_space + 1, 1);
	ft_strlcpy(new_cleanline, cleanline, ft_strlen(cleanline) + extra_space);
	free(cleanline);
	*c_len = *c_len + 10;
	return (new_cleanline);
}