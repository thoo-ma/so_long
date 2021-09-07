/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobin <trobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:58:54 by trobin            #+#    #+#             */
/*   Updated: 2021/08/31 11:31:36 by trobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;

	if (s == 0)
		return (0);
	len = ft_strlen(s);
	dest = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	ft_memcpy(dest, s, len);
	dest[len] = '\0';
	return (dest);
}
