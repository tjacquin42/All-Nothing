/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:41:16 by tjacquin          #+#    #+#             */
/*   Updated: 2016/02/18 03:19:19 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFF_SIZE 2000000
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);
int		superior(int left, int up, int diag);
int		okgo(int k, char *tmp, int fd);
void	check(char *grille, int line, char *param, int i);
void	cross(char *grille, int x, char *param, int *tab);
int		searchsave(char *grille, int *tab);
int		searchtall(char *grille, int *tab);
void	this_is_the_end(char *grille, char *param);
int		verifpar(char *par);
int		standinput(int fd, char *tmp, int k);
int		verif(int fd, char *gr, char *par, int i);
void	cross(char *grille, int x, char *param, int *tab);

#endif
