/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:00:39 by amartyne          #+#    #+#             */
/*   Updated: 2019/05/14 20:33:36 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	j;
	size_t	l1;
	size_t	l2;

	i = 0;
	j = 0;
	a = NULL;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	a = (char*)malloc(l1 + l2 + 1);
	if (!a)
		return (NULL);
	while (i < l1)
	{
		a[i] = s1[i];
		i++;
	}
	while (j < l2)
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}

char	*ft_strjoin_free_one(char **s1, char *s2)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	if (s1 && (s2 || *s1))
	{
		len = ft_strlen(*s1) + ft_strlen(s2) + 1;
		if (!(res = (char*)malloc(sizeof(char) * len)))
			return (NULL);
		while ((*s1)[i] != '\0')
		{
			res[i] = (*s1)[i];
			i++;
		}
		while (s2[i - ft_strlen((*s1))] != '\0')
		{
			res[i] = s2[i - ft_strlen((*s1))];
			i++;
		}
		res[i] = '\0';
		ft_strdel(s1);
		return (res);
	}
	return (NULL);
}

char	*ft_strjoin_free(char **s1, char **s2)
{
	int		i;
	char	*res;

	i = 0;
	if (s1 && s2 && (*s1 || *s2))
	{
		if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(*s1) +
							ft_strlen(*s2) + 1))))
			return (NULL);
		while ((*s1)[i] != '\0')
		{
			res[i] = (*s1)[i];
			i++;
		}
		while ((*s2)[i - ft_strlen((*s1))] != '\0')
		{
			res[i] = (*s2)[i - ft_strlen((*s1))];
			i++;
		}
		res[i] = '\0';
		ft_strdel(s1);
		ft_strdel(s2);
		return (res);
	}
	return (NULL);
}
