/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:56:04 by exam              #+#    #+#             */
/*   Updated: 2019/12/06 11:56:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		ft_lower(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int			ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void		ft_putstr(char *string, unsigned int i, unsigned int len)
{
	while (len)
	{
		write(1, &(string[i]), 1);
		++i;
		--len;
	}
}

int			ft_strcmp(char *s1, char *s2, unsigned int len1, unsigned int len2)
{
	char	a;
	char	b;

	if (!s1 || !s2 || !len1 || !len2)
		return (0);
	a = 0;
	b = 0;
	while (len1 && len2 && *s1 && *s2)
	{
		a = ft_lower(*s1);
		b = ft_lower(*s2);
		if (a != b)
			break ;
		++s1;
		++s2;
		--len1;
		--len2;
	}
	return (a - b);
}
