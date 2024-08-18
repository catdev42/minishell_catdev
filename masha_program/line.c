/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/08/18 22:41:51 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clean_line(char *line, int linelen)
{
	char	*cleanline;
	int		i;
	int		j;
	char	quote_char;

	quote_char = 0;
	i = 0;
	j = 0;
	linelen += 10;
	cleanline = ft_calloc(linelen + 2, 1);
	while (line[i] && j < linelen)
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			cleanline[j++] = line[i++];
			quote_char = line[i - 1];
			while (line[i] && line[i] != quote_char)
			{
				cleanline[j++] = line[i++];
				if (j == linelen - 1 && i < ft_strlen(line) - 1)
					cleanline = expand_cleanline(cleanline, &linelen);
			}
		}
		else if (isspace(line[i]))
		{
			cleanline[j++] = ' ';
			while (isspace(line[i]))
				i++;
		}
		else if (line[i] == '|')
		{
			if (j > 0 && cleanline[j - 1] != ' ')
				cleanline[j++] = ' ';
			cleanline[j++] = line[i++];
			if (line[i] != ' ')
				cleanline[j++] = ' ';
		}
		else if (line[i] == '>' || line[i] == '<')
		{
			if (j > 0 && cleanline[j - 1] != ' ')
				cleanline[j++] = ' ';
			cleanline[j++] = line[i++];
			// Handle <<, >>, and <<<
			while (line[i] == '>' || line[i] == '<')
			{
				cleanline[j++] = line[i++];
				if (j == linelen - 1 && i < ft_strlen(line) - 1)
					cleanline = expand_cleanline(cleanline, &linelen);
			}
			if (line[i - 1] == '>' || line[i - 1] == '<')
				while (isspace(line[i]))
					i++;
		}
		else
			cleanline[j++] = line[i++];
		if (j == linelen && i < linelen - 1)
			cleanline = expand_cleanline(cleanline, &linelen);
	}
	return (cleanline);
}

char	*expand_cleanline(char *cleanline, int *linelen)
{
	char *new_cleanline;

	new_cleanline = ft_calloc(ft_strlen(cleanline) + 11, 1);
	ft_strlcpy(new_cleanline, cleanline, ft_strlen(cleanline) + 10);
	free(cleanline);
	*linelen = *linelen + 10;
	return (new_cleanline);
}