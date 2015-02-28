/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:13:58 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/28 08:46:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** signal handling
*/

#include "header.h"

static void			sig_handler(int sig)
{
	if (sig == SIGBUS)
		error(BUS, NULL);
	else if (sig == SIGSEGV)
		error(SEG, NULL);
	else if (sig == SIGFPE)
		error (FPE, NULL);
}

void				sig_init(void)
{
//	signal(SIGINT, sig_handler);
	signal(SIGFPE, sig_handler);
//	signal(29, sig_handler); //SIGINFO
	signal(SIGSEGV, sig_handler);
	signal(SIGBUS, sig_handler);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN); //useless?
	signal(SIGCHLD, SIG_IGN); //zombie shotgun
}
