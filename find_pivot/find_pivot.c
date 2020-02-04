/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:06:04 by exam              #+#    #+#             */
/*   Updated: 2020/01/14 09:14:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_sum(int *arr, int n)
{
	int		i;
	int		sum;

	if (!n || !arr)
		return (0);
	i = 0;
	sum = 0;
	while (i < n)
	{
		sum = sum + arr[i];
		++i;
	}
	return (sum);
}

int			find_pivot(int *arr, int n)
{
	int		left;
	int		right;
	int		pivot;

	left = 0;
	right = get_sum(arr, n);
	pivot = 0;
	while (pivot < n)
	{
		right = right - arr[pivot];
		if (left == right)
			return (pivot);
		left = left + arr[pivot];
		++pivot;
	}
	return (-1);
}

/*
**	#include <stdio.h>
**	
**	int			main()
**	{
**		int		arr[2] = {0, 1};
**	
**		printf("pivot: %d\n", find_pivot(arr, 2));
**		return (0);
**	}
*/
