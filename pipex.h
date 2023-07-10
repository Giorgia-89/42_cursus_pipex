/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:17:34 by gd-innoc          #+#    #+#             */
/*   Updated: 2023/06/17 11:34:17 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
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

//pipex.c
int		checks(int argc, char **argv);
void	parent_process(char **argv, char **envp, int *fd, int fd_out);
void	child_process(char **argv, char **envp, int *fd);
//utils.c
void	close_fds(int fd1, int fd2);
void	print_err(int n, char *cmd);
int		execute_command(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
//checks.c
void	check_fds(int fd);
void	check_and_close_fds(int fd_check, int fd_close);
int		check_arg(char *cmds);
int		check_slash(char **cmds);
int		check_cmdpath(char **cmds, char *cmdpath);

#endif
