/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexerchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/07/21 17:48:56 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// return index of closing quote or puts error!
int	check_quotes(char *line, int i)
{
	int	j;

	// char	*line;
	// line = tools->line;
	j = 1;
	while (line[i + j])
	{
		if (line[i] == line[i + j])
			return (i + j);
		j++;
	}
	// error_exit(tools, 2);
	ft_putstr_fd("msh: Unclosed Quotes\n", 2); // changed
	return (0);
}
char	*get_redir_error(char *line, int i)
{
}
int	check_redirects(t_tools *tools)
{
	int len = ft_strlen(tools->line);
	int i = 0;
	while (tools->line[i])
	{
		if (tools->line[i] == "\"" || tools->line[i] == "\"")
			i = check_quotes(tools->line, i);
		if (istoken(tools->line[i]))
		{
			if (ft_strncmp(&tools->line[i], "<<|", 3)
				|| ft_strncmp(&tools->line[i], ">>>", 3)
				|| ft_strncmp(&tools->line[i], ">>>>", 4)
				|| ft_strncmp(&tools->line[i], "||", 2)
				|| ft_strncmp(&tools->line[i], ">>>>", 4)
				|| ft_strncmp(&tools->line[i], ">>>>", 4)
				|| ft_strncmp(&tools->line[i], ">>>>", 4))
				new_line("syntax error near unexpected token ",
					get_redir_error(tools->line, i));
		}
	}
	/*
	"<<|",
	"<<<<",
	">>>",
	"||",
	";;",
	"><",
	"<>",
	*/
}