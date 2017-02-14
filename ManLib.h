/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:53:01 by tjacquin          #+#    #+#             */
/*   Updated: 2017/02/13 06:09:43 by tjacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void	*ft_memset(void *b, int c, size_t len);
/*			remplit len premiers octects de la zone b avec c */
void	ft_bzero(void *s, size_t n);
/*			met '\0' aux n premiers octets de s */
void	*ft_memcpy(void *dst, const void *src, size_t n);
/*			copie n octet depuis la memoire src vers dst */
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
/*			copie n octet depuis la memoire src vers dst, stop au car n */
void	*ft_memmove(void *dst, const void *src, size_t len);
/*			copie n octet de src vers dst en copiant sur une zone temporaire */
void	*ft_memchr(const void *s, int c, size_t n);
/*			examine les n premiers octets pour trouver c */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*			compare les n premiers octets, if s1 > s2 return (int > 0) */



size_t	ft_strlen(const char *s);
/*			taille d'une chaine */
char	*ft_strdup(const char *s1);
/*			copie chaine s1 dans une autre et free s1 */
char	*ft_strcpy(char *dst, const char *src);
/*			copie une chaine */
char	*ft_strncpy(char *dst, const char *src, size_t len);
/*			copie une chaine jusqu'a len caracteres */
char	*ft_strcat(char *s1, const char *s2);
/*			ajoute s2 a la fin de s1 */
char	*ft_strncat(char *s1, const char *s2, size_t n);
/*			ajoute n caracteres de s2 a la fin de s1 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
/*			recherche little dans big et renvois little[occurence] */
int		ft_strcmp(const char *s1, const char *s2);
/*			compare les chaines s1 et s2 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*			compare les n premiers caracteres de s1 et s2 */



int		ft_atoi(const char *str);
/*			char to int un nb */
int		ft_isalpha(int c);
/*			verif si le numero ascii c est une lettre */
int		ft_isdigit(int c);
/*			verif si le numero ascii c est un chiffre */
int		ft_isalnum(int c);
/*			verif si le numero c est un alphanumerique (isdigit || isalpha) */
int		ft_isascii(int c);
/*			verif si le numero ascii c existe */
int		ft_isprint(int c);
/*			verif si le numero ascii c est imprimable */
int		ft_toupper(int c);
/*			converti le numero ascii c en majuscule */
int		ft_tolower(int c);
/*			converti le numero ascii c en minuscule */
char	*ft_strtolower(char *str);


void	*ft_memalloc(size_t size);
/*			alloue une taille size de memoire */
void	ft_memdel(void **ap);
/*			efface une zone memoire */
char	*ft_strnew(size_t size);
/*			creer une chaine de caractere vide avec sa memoire */
void	ft_strdel(char **as);
/*			efface la memoire d'une chaine de caractere */
void	ft_strclr(char *s);
/*			clear une chaine de caractere */
void	ft_striter(char *s, void (*f)(char *));
/*			applique la fonction f a chaque caracter de s */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
/*			applique f a chaque caractere de s */
char	*ft_strmap(char const *s, char (*f)(char));
/*			applique f a chaque caractere de s dans une new str */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*			applique f a chaque caractere de s dans une new str avec index */
int		ft_strequ(char const *s1, char const *s2);
/*			compare 2 chaine: return(1) si identique */
int		ft_strnequ(char const *s1, char const *s2, size_t n);
/*			compare 2 chaine jusqua n, return(1) si identique */
char	*ft_strsub(char const *s, unsigned int start, size_t len);
/*			alloue, retourne la copie de s a partir de start et longueur len */
char	*ft_strjoin(char const *s1, char const *s2);
/*			associe s1 et s2 dans une nouvelle chaine */
char	*ft_strtrim(char const *s);
/*			copie une chaine en enlevant espaces au debut et a la fin */
char	**ft_strsplit(char const *s, char c);
/*			ft_strsplit("*salut*les***etudiants*", ’*’) renvoie
 *			le tableau ["salut", "les", "etudiants"] */
char	*ft_itoa(int n);
/*			int to char*/
void	ft_putchar(char c);
/*			Affiche le caractère c sur la sortie standard */
void	ft_putstr(char const *s);
/*			Affiche la chaine s sur la sortie standard */
void	ft_putendl(char const *s);
/*			Affiche la chaine s sur la sortie standard suivi d’un ’\n’ */
void	ft_putnbr(int nb);
/*			affiche un chiffre */
void	ft_putchar_fd(char c, int fd);
/* 			Ecrit le caractère c sur le descripteur de fichier fd */
void	ft_putstr_fd(char const *s, int fd);
/*			Ecrit la chaine s sur le descripteur de fichier fd */
void	ft_putendl_fd(char const *s, int fd);
/*			Ecrit la chaine s sur le descripteur de fichier fd suivi d’un \n */
void	ft_putnbr_fd(int n, int fd);

#endif
