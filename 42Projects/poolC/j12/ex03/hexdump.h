/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckupfers <ckupfers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:12:04 by ckupfers          #+#    #+#             */
/*   Updated: 2015/12/10 22:01:22 by ckupfers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{
	char		p[16];
	char		n[16];
	int			fd;
	int			i;
	int			char16;
	int			ctt;
	int			star;
}				t_list;

int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);
void			ft_hexa(int num);
void			ft_numchar(int num, int c);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_special(char c);
void			ft_bis(int i, char *base, int mod[100]);
int				ft_error(int ac, char **av, int i);
int				ft_mainbis(t_list a, t_list pn, char *av);
int				print(t_list pn, int nbchar, int star, int c);
int				ft_check(char p[16], char n[16]);
t_list			ft_init(t_list pn);
t_list			ft_change(t_list pn);

#endif
