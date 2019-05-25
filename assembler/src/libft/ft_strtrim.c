/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:30:55 by amartyne          #+#    #+#             */
/*   Updated: 2019/05/16 14:19:31 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*a;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i])
	{
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
	}
	n = len - i + 1;
	a = (char*)malloc(n);
	if (!a)
		return (NULL);
	len = 0;
	while (len < n - 1)
		a[len++] = s[i++];
	a[len] = '\0';
	return (a);
}

char	*ft_strtrim_dop(char const *s, int key)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	if (s)
	{
		j = ft_strlen(s);
		if (key == 1 || key == 3)
		{
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' ||
						s[i] == '\t'))
				i++;
		}
		if (s[i] != '\0' && (key == 2 || key == 3))
		{
			while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
				j--;
		}
		if (!(res = ft_strsub(s, i, j - i)))
			return (NULL);
		return (res);
	}
	return (NULL);
}
