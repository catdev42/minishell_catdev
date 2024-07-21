/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:00:21 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/21 21:34:28 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef enum s_token
{
	NONE,
	PIPE,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
	LESS_LESS_LESS,
}				t_token;

/* one for each command with its own redirects and argc*/
typedef struct s_parsed_command
{
	int			argc;
	char		**argv;
	char		**redir;
	t_token		*redir_tokens;
}				t_parsed;

typedef struct s_tools
{
	char		**env;
	size_t		env_len;
	char		*line;
	char		**lexed;
	size_t		lex_len;
	int			num_pipes;
	t_parsed	*parsed_commands;
}				t_tools;

// typedef struct line_saver
// {
// 	char	**line_pointers;
// 	int		*line_lengths;
// }

#endif