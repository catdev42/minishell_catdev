/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:26:33 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/13 20:09:15 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "structs.h"

void	lexer(t_tools *tools);
int		getlen_command(t_tools *tools, int i);
int		getlen_redirect(t_tools *tools, int i);
int		check_quotes(t_tools *tools, int i);
int		count_parts(t_tools *tools);

#endif