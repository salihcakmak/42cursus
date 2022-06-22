/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:28:49 by scakmak           #+#    #+#             */
/*   Updated: 2022/02/15 09:41:30 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* library */
# include <signal.h> // signal()
# include <unistd.h> // getpid(), write()

/* utils */
void	ft_itoa(int pid);
int		ft_atoi(char *str);

#endif