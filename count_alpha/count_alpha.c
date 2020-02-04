/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:15:58 by exam              #+#    #+#             */
/*   Updated: 2019/12/17 09:29:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int		ft_isalpha(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

static int		ft_tolower(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

static int		count_alpha(char *s, int i, char alpha)
{
	int		count;

	count = 0;
	while (s[i])
	{
		if (s[i] == alpha || s[i] + 32 == alpha)
		{
			++count;
			s[i] = '7';
		}
		++i;
	}
	return (count);
}

int				main(int argc, char **argv)
{
	char	*s;
	int		i;
	int		count;
	char	alpha;
	int		first;

	if (argc == 2)
	{
		s = argv[1];
		if (s)
		{
			first = 1;
			i = 0;
			while (s[i])
			{
				if (ft_isalpha(s[i]))
				{
					alpha = ft_tolower(s[i]);
					count = count_alpha(s, i, alpha);
					if (first)
						first = 0;
					else
						printf(", ");
					printf("%d%c", count, alpha);
				}
				++i;
			}
		}
	}
	printf("\n");
	return (0);
}
