/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:00:21 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/17 21:04:16 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef struct s_tools
{
	char	**env;
	size_t	env_len;
	char	*line;
	char	**lexed;
	int		num_commands;
}			t_tools;

typedef struct	cmd_s
{
	char	**cmds;
}				cmd_t;

// typedef struct s_parsed
// {
// 	int		*redirect_fds;
// 	char	*command;
// } t_parsed;

#endif