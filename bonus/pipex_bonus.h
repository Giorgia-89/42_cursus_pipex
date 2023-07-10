/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:17:34 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/19 10:06:23 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
//file related functions (open, access)
# include <fcntl.h>
// wait(), waitpid()
# include <sys/wait.h>
//process-related functions (fork)
# include <sys/types.h>
//memory-related functions (malloc and free)
# include <stdlib.h>
//system calls (close, dup2, pipe, execve)
# include <unistd.h>
//standard input/output operations and perror
# include <stdio.h>
# include <errno.h>
//int max
# include <limits.h>

//checks_bonus.c
void	check_argc(int argc);
int		check_arg(char *cmds);
int		check_slash(char **cmds);
int		check_cmdpath(char **cmds, char *cmdpath);
//fd_helpers_bonus
void	check_fds(int fd);
int		check_and_close_fds(int fd_check, int fd_close);
void	close_fds(int fd1, int fd2);
//pipex_bonus.c
int		open_infile(char **argv);
void	main_process(char *cmd, char **envp);
void	child_process(int *fd, char *cmd, char **envp);
void	parent_process(int argc, char **argv, int *fd_dup, char **envp);
//utils.c
void	print_err(int n, char *cmd);
int		execute_command(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);

#endif