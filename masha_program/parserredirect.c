/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserredirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:05 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/23 20:49:14 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token get_token(char *redirect)
{
    if (strcmp(redirect, ">") == 0)
        return GREAT;
    if (strcmp(redirect, ">>") == 0)
        return GREAT_GREAT;
    if (strcmp(redirect, "<") == 0)
        return LESS;
    if (strcmp(redirect, "<<") == 0)
        return LESS_LESS;
    if (strcmp(redirect, "<<<") == 0)
        return LESS_LESS_LESS;
    return NONE;
}