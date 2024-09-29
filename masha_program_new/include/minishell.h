/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:12:04 by myakoven          #+#    #+#             */
/*   Updated: 2024/09/27 00:38:05 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "builtins.h"
# include "lexer.h"
// # include "parser.h"
# include "structs.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define UNEXP "syntax error near unexpected token "
# define UNCLOSED "unclosed quotes "

// volatile sig_atomic_t	global_signal = 0;

/************************/
/******** main.c ********/
/************************/
int		shell_loop(t_tools *tools);
void	new_line(void);
void	handle_signals(int sig);
void	init_sa(struct sigaction *sa);

/************************/
/******** line.c ********/
/************************/
int		copy_quotes(char *c_line, char *line, t_tools *tools);
int		copy_pipe(char *c_line, char *line, int current_line_index);
int		copy_redirect(char *c_line, char *line, int current_line_index);
char	*clean_line(char *line, int linelen, t_tools *tools);
int		copy_spaces(char *c_line, char *line);

int		copy_var(char *c_line, char *line, t_tools *tools);

/************************/
/******* init.c ********/
/************************/
void	init_tools(t_tools *tools);

/************************/
/*******  env.c  ********/
/************************/
char	**copy_env(t_tools *tools, char **env);
char	*get_var(char **env, char *var);
// char	*get_env_var(t_tools *tools, char *var);

/************************/
/******* utils.c ********/
/************************/

char	*safe_calloc(size_t nmemb, size_t size, t_tools *tools);
int		print_tab(char **envp);
int		istoken(char c);
int		isquote(char c);
int		get_matrix_len(char **matrix);
// int		skip_spaces(char *s);


/************************/
/******* utils2.c ********/
/************************/
int		valid_line(char *line);
void	ft_bspace(void *s, size_t n);
void	init_zero(int *i, int *j, char *c, char **c_line);

/************************/
/******* error.c ********/
/************************/
int		error_exit(t_tools *tools, int error);
void	clean_tools(t_tools *tools);
char	**free_array(char **res, int nb);
int		print_error(char *errline, char *errarg);

/************************/
/******* built_ins.c ********/
/************************/
// void	pwd(t_tools *tools, cmd_t *cmd); //TODO
// void	pwd(t_tools *tools);

#endif