/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:51:20 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/24 16:51:22 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stdlib.h>

//int		ft_printf(const char *s, ...);
//int		ptr_arr_len(char **arr);
//int		check_args(char *s1, char *s2, int argc);
//int		free_error_args(int *pipes, char *path, char **args, char *errmsg);
//int		*create_pipes(int *pipes, int condition);
//int		child1(char *path, char **args, int *pipes, char *file);
//int		child2(char *path, char **args, int *pipes, char *file);
//char	*new_path(char *path);
char	*ft_strjoin(char *s1, char *s2, char *s3, char *s4, char *s5);
char	*ft_strjoin_for_read(char *s1, char c);
char	**ft_split(char const *s, char c);
//char	**ft_kinda_split(char **s, char *new);
//void	whereis(int *pipes, char *command, char **envp);
void	perror_exit(int condition, char *errmsg);
void	free_ptr_arr(char **arr);
void	free_error(int *pipes, char *path, int condition, char *errmsg);
void	free_not_error(int *pipes, char *path);
void	free_pipes_error(int *pipes1, int *pipes2, int condition, char *errmsg);
//void	child_fork_first(int *pipes, char **envp, char **argv);
//void	child_fork_last(int *pipes, char **envp, char **argv);
//void	child_fork_loop(int *pipes, char **envp, char **argv, int j);
//char	*read_from_pipe_path(int pipe);
size_t	ft_strlen(char *s);

#endif
