/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blatifat <blatifat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 03:53:14 by blatifat          #+#    #+#             */
/*   Updated: 2023/11/20 20:42:27 by blatifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned long	ft_strlen(const char *str)
{
	const char	*l = str;

	while (*l != '\0')
		l++;
	return (l - str);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*string;
	size_t	src_len;

	src_len = ft_strlen(src);
	string = (char *)malloc((src_len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	i = 0 ;
	while (src[i] != '\0')
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*result;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		result[i] = s2[i - len1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;
	char	*nstr;
	int		allocate;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len < ft_strlen(s))
		allocate = len;
	else
		allocate = (int)ft_strlen(s) - (int)start;
	nstr = (char *)malloc(allocate + 1);
	if (!nstr)
		return (NULL);
	i = start;
	n = 0;
	while (s[i] != '\0' && n < len)
		nstr[n++] = s[i++];
	nstr[n] = '\0';
	return (nstr);
}
