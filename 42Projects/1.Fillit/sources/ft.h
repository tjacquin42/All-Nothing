/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 09:21:35 by tjacquin          #+#    #+#             */
/*   Updated: 2016/06/12 21:27:06 by blo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFF_SIZE 545

# define Y (fline + line - originline)
# define X (fkase + kase - originkase)
# define LENRESO sizemap(finalmap)

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		main(int argc, char **argv);

int		go(char *argv);
char	***tab_map(char *buff);
void	map_to_tab(char *buff, char ***tab);
void	alpha_tab(char ***tab, int ntetris);

int		check(char *map);
int		checkbloc(char *map, int nbrtetri);
int		blocbybloc(char *map);
int		crosslinked(char *map, int i);
int		checkform(char *map, int compt, int line);

char	*ft_strsub(char *s, int start, int len);

int		strlentris(char *map);
int		tetrislen(char *map);

void	resolution(char ***tab, int ntretris);
int		lower(int ntetris);
void	process(char ***tab, char **final, int nbtetris, int fouillamerde);
int		sizemap(char **final);

int		asciitetris(char **tetrisinc);
void	print_finalmap(char **finalmap, int lenreso);
void	ccleanmap(char **finalmap, int ascii, int lenreso);
char	**finalmap(int lenmap);

int		addtetrisinc(char **finalmap, int fline, int fkase, char **tetrisinc);
int		origin_kase(char **tetrisinc);
int		origin_line(char **tetrisinc);
void	delete_tetrisinc(char **finalmap, int ascii, int lenreso);

#endif
