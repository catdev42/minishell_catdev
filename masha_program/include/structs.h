/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:00:21 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/21 18:01:57 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef enum s_tokens
{
	NONE,
	PIPE,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_tools
{
	char	**env;
	size_t	env_len;
	char	*line;
	char	**lexed;
	size_t lex_len;
	int		num_pipes;
}			t_tools;

typedef struct cmd_s
{
	char	**cmds;
}			cmd_t;

// typedef struct s_parsed
// {
// 	int		*redirect_fds;
// 	char	*command;
// } t_parsed;

// typedef struct line_saver
// {
// 	char	**line_pointers;
// 	int		*line_lengths;
// }

#endif