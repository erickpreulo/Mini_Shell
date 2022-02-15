/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:33:50 by egomes            #+#    #+#             */
/*   Updated: 2022/02/15 16:29:33 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		get_ms()->sig_exit = 1;
		get_ms()->final_status = 130;
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		show_pwd();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		get_ms()->sig_exit = 1;
		rl_on_new_line();
		show_pwd();
		rl_redisplay();
	}
}

void	start_signal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
