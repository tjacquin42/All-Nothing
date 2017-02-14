/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 18:56:35 by tjacquin          #+#    #+#             */
/*   Updated: 2015/10/31 18:57:17 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		eval_expr(char *str);
char	*sup_spaces(char *str);
int		partial_eval(char **str);
int		do_op(char op, int f, int s);
int		find_nbr(char **str);
int		eval_bis(char **str);

#endif
