/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:15:14 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/09 19:19:19 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **env)
{
	char **envp;
	int len_pointers;
	int lenTemp;
	// TODO
	len_pointers = 0;
	// len_pointers = ft_strlen(env) / sizeof(char *);
	while (env[len_pointers] != NULL)
	{
		len_pointers++;
	}
	envp = malloc((len_pointers + 1) * sizeof(char *));
	if (!envp)
		return (NULL);
	return (envp);
}