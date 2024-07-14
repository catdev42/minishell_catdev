/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:15:14 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/13 20:28:34 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(t_tools *tools, char **env)
{
	char	**envp;
	int		len_pointers;
	int		i;

	i = 0;
	len_pointers = 0;
	while (env[len_pointers] != NULL)
		len_pointers++;
	envp = ft_calloc((len_pointers + 5), sizeof(char *));
	if (!envp)
		return (NULL);
	tools->env_len = len_pointers + 3;
	while (i < len_pointers && env[i])
	{
		envp[i] = ft_strdup(env[i]);
		if (!envp[i])
		{
			free_array(env, len_pointers);
			return (NULL);
		}
		i++;
	}
	return (envp);
}

void	print_tab(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

int	istoken(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	isquote(char c)
{
	return (c == '\'' || c == '\"');
}

int	skip_spaces(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (i);
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (i);
}
