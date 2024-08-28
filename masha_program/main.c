/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:51:01 by myakoven          #+#    #+#             */
/*   Updated: 2024/08/28 23:53:41 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

volatile sig_atomic_t	global_signal = 0;

int	main(int argc, char **argv, char **env)
{
	t_tools				tools;
	struct sigaction	sa;

	if (argc > 1 || argv[1])
		ft_putstr_fd("This program does not accept arguments\n", 2);
	init_tools(&tools);
	tools.env = copy_env(&tools, env);
	if (!tools.env)
		return (error_exit(&tools, 1));
	init_sa(&sa);
	shell_loop(&tools);
	print_tab(tools.lexed);
	clear_history();
	return (0);
}

int	shell_loop(t_tools *tools)
{
	char *c_line;
	while (1)
	{
		if (tools->line)
			free(tools->line);
		tools->line = readline("minishell: ");
		if (!tools->line || !strncmp(tools->line, "exit", 5))
			error_exit(tools, 3);
		global_signal = 0;
		if (valid_line(tools->line))
			add_history(tools->line);
		else
			continue ;
		c_line = clean_line(tools->line, ft_strlen(tools->line), tools);
		ft_putstr_fd(c_line, 1);
		ft_putstr_fd("\n", 1);

		// if (lexer(tools))
		// {
		// 	printf("%s\n", tools->line);
		// 	print_tab(tools->lexed);
		// 	parser(tools);
		// }
		if (global_signal == SIGTERM) // TODO
			break ;
	}
	clean_tools(tools);
	return (0);
}

/*
Input NULL or errline and/or errarg.
If errline is provided, an error is printed to the screen,
	is errarg is provided, it is appended to the error string*/
void	new_line(void)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_signals(int sig)
{
	if (sig == SIGINT)
	{
		new_line();
		global_signal = SIGINT;
	}
	else if (sig == SIGTERM)
		global_signal = SIGTERM;
}

void	init_sa(struct sigaction *sa)
{
	sa->sa_handler = handle_signals;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = 0;
	if (sigaction(SIGINT, sa, NULL) == -1)
	{
		global_signal = SIGINT;
		perror("sigaction");
		exit(1);
	}
}
