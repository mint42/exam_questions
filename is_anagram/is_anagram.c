/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:23:02 by exam              #+#    #+#             */
/*   Updated: 2018/08/28 11:14:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

int		check_letter(int i, char *b, char *a, int alen)
{
	int		count;
	int		count2;
	int		j;
	char	*cur;

	count = 0;
	count2 = 0;
	j = 0;
	cur = a;
	while (b[j] != '\0')
	{
		if (b[j] == b[i] && j < i)
			return (1);
		if (b[j] == b[i] && j >= i)
			++count;
		++j;
	}
	j = 0;
	while (j < alen)
	{
		if (*cur == b[i])
		{
			++count2;
			*cur = 0;
		}
		++j;
		++cur;
	}
	return (count == count2 ? 1 : 0);
}

int		is_anagram(char *a, char *b)
{
	int		i;
	int		alen;

	i = 0;
	alen = ft_strlen(a);
	while (b[i] != '\0')
	{
		if (!(check_letter(i, b, a, alen)))
			return (0);
		++i;
	}
	i = 0;
	while (i < alen)
	{
		if (a[i] != 0)
			return (0);
		++i;
	}
	return (1);
}
