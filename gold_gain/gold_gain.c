/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:05:04 by exam              #+#    #+#             */
/*   Updated: 2019/09/17 10:59:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		get_gold(int **solve_mine, int n)
{
	int		gold;
	int		y;

	y = 0;
	gold = 0;
	while (y < n)
	{
		if (solve_mine[y][n - 1] > gold)
			gold = solve_mine[y][n - 1];
		++y;
	}
	return (gold);
}

static void		solve(int **solve_mine, int n)
{
	int		x;
	int		y;

	x = 1;
	while (x < n)
	{
		y = 0;
		while (y < n)
		{
			if (y == 0)
			{
				if (solve_mine[y][x - 1] >= solve_mine[y + 1][x - 1])
					solve_mine[y][x] =  solve_mine[y][x] + solve_mine[y][x - 1];
				else
					solve_mine[y][x] =  solve_mine[y][x] + solve_mine[y + 1][x - 1];
			}
			else if (y + 1 == n)
			{
				if (solve_mine[y - 1][x - 1] >= solve_mine[y][x - 1])
					solve_mine[y][x] =  solve_mine[y][x] + solve_mine[y - 1][x - 1];
				else
					solve_mine[y][x] =  solve_mine[y][x] + solve_mine[y][x - 1];
			}
			else
			{
				if (solve_mine[y - 1][x - 1] >= solve_mine[y][x - 1] && solve_mine[y - 1][x - 1] >= solve_mine[y + 1][x - 1])
					solve_mine[y][x] =  solve_mine[y][x] + solve_mine[y - 1][x - 1];
				else if (solve_mine[y][x - 1] >= solve_mine[y - 1][x - 1] && solve_mine[y][x - 1] >= solve_mine[y + 1][x - 1])
					solve_mine[y][x] =  solve_mine[y][x] + solve_mine[y][x - 1];
				else
					solve_mine[y][x] =  solve_mine[y][x] + solve_mine[y + 1][x - 1];
			}
			++y;
		}
		++x;
	}
}

static int		**copy_mine(int **mine, int n)
{
	int		**solve_mine;
	int		x;
	int		y;

	solve_mine = (int **)malloc(sizeof(int *) * n);
	if (!solve_mine)
		return (0);
	y = 0;
	while (y < n)
	{
		solve_mine[y] = (int *)malloc(sizeof(int) * n);
		if (!solve_mine[y])
			return (0);
		x = 0;
		while (x < n)
		{
			solve_mine[y][x] = mine[y][x];
			++x;
		}
		++y;
	}
	return (solve_mine);
}

int				gold_gain(int **mine, int n)
{
	int		**solve_mine;
	int		gold;

	if (!mine || !*mine || !n)
		return (0);
	if (n == 1)
		return (mine[0][0]);
	gold = 0;
	solve_mine = copy_mine(mine, n);
	if (!solve_mine)
		return (0);
	solve(solve_mine, n);
	gold = get_gold(solve_mine, n);
	return (gold);
}


/*
**	#include <stdio.h>
**	
**	int				main()
**	{
**		int		**mine;
**		int		n;
**	
**		n = 1;
**		mine = (int **)malloc(sizeof(int *) * n);
**		mine[0] = (int *)malloc(sizeof(int) * n);
**	
**		mine[0][0] = 12;
**		printf("gold: %d\n", gold_gain(mine, n));
**		return (0);
**	}
*/
