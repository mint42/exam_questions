/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:23:23 by exam              #+#    #+#             */
/*   Updated: 2019/08/13 09:49:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

static void		recursive_flood_fill(char **tab, t_point size, t_point position, char c)
{
	if (!tab)
		return ;
	if (tab[position.y][position.x] == c)
		tab[position.y][position.x] = 'F';
	if (position.x > 0 && tab[position.y][position.x - 1] == c)
	{
		--position.x;
		recursive_flood_fill(tab, size, position, c);
		++position.x;
	}
	if (position.x < size.x - 1 && tab[position.y][position.x + 1] == c)
	{
		++position.x;
		recursive_flood_fill(tab, size, position, c);
		--position.x;
	}
	if (position.y > 0 && tab[position.y - 1][position.x] == c)
	{
		--position.y;
		recursive_flood_fill(tab, size, position, c);
		++position.y;
	}
	if (position.y < size.y - 1 && tab[position.y + 1][position.x] == c)
	{
		++position.y;
		recursive_flood_fill(tab, size, position, c);
		--position.y;
	}
		
}

void			flood_fill(char **tab, t_point size, t_point begin)
{
	recursive_flood_fill(tab, size, begin, tab[begin.y][begin.x]);
}

/*
**	#include <stdlib.h>
**	#include <stdio.h>
**	
**	char			**make_area(char** zone, t_point size)
**	{
**		char** new;
**	
**		new = malloc(sizeof(char*) * size.y);
**		for (int i = 0; i < size.y; ++i)
**		{
**			new[i] = malloc(size.x + 1);
**			for (int j = 0; j < size.x; ++j)
**				new[i][j] = zone[i][j];
**			new[i][size.x] = '\0';
**		}
**	
**		return new;
**	}
**	
**	int 			main(void)
**	{
**		t_point size = {8, 5};
**		char 	*zone[] = {
**			"11111111",
**			"10001001",
**			"10010001",
**			"10110001",
**			"11100001",
**		};
**		char	**area = make_area(zone, size);
**	
**		for (int i = 0; i < size.y; ++i)
**			printf("%s\n", area[i]);
**		printf("\n");
**	
**		t_point begin = {1, 1};
**		flood_fill(area, size, begin);
**		for (int i = 0; i < size.y; ++i)
**			printf("%s\n", area[i]);
**		return (0);
**	}
*/
