/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:53:56 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/10 16:54:11 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	len(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

// static void	ft_strcpy(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s2[i])
// 	{
// 		s1[i] = s2[i];
// 		i++;
// 	}
// 	s1[i] = '\0';
// }

char	*ft_strjoin(char * s1, char * s2, char * s3, char * s4, char * s5)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof (*res) * (len(s1) + len(s2) + len(s3) + len(s4) + len(s5) + 1 + 1)); // +1 for spaces
	if (!res)
		return (NULL);
	while (i < len(s1))
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	//res[i++] = ' ';
	while (j < len(s2))
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	j = 0;
	res[i++] = ' ';
	while (j < len(s3))
	{
		res[i] = s3[j];
		i++;
		j++;
	}
	j = 0;
	//res[i++] = ' ';
	while (j < len(s4))
	{
		res[i] = s4[j];
		i++;
		j++;
	}
	j = 0;
	//res[i++] = ' ';
	while (j < len(s5))
	{
		res[i] = s5[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_for_read(char *s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof (*res) * (len(s) + 2));
	if (!res)
		return (NULL);
	while (i < len(s))
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}
