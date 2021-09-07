/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:59:14 by trobin            #+#    #+#             */
/*   Updated: 2021/09/07 10:41:04 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

void	ft_bzero(char *s, int n);
char	*ft_memcpy(char *dest, const char *src, int n);
void	*ft_memchr(const void *s, int c, int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcspn(const char *s1, const char *s2);

#endif
