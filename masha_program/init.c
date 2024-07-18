/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:35:52 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/18 23:15:58 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_tools(t_tools *tools)
{
	tools->line = NULL;
	tools->env = NULL;
	tools->env_len = 0;
	tools->lexed = NULL;
	tools->lex_len = 0;
	tools->num_commands = 0;
}

/* must clean tools first */
void	reset_tools(t_tools *tools)
{
	tools->line = NULL;
	tools->lexed = NULL;
	tools->lex_len = 0;
	tools->num_commands = 0;
}


