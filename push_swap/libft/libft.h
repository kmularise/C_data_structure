/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:55:21 by yuikim            #+#    #+#             */
/*   Updated: 2023/03/21 20:43:07 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf.h"

int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
int		ft_isdigit(char c);

#endif