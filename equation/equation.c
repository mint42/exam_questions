/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:06:22 by exam              #+#    #+#             */
/*   Updated: 2019/12/17 09:13:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		equation(int n)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 0;
	while (42)
	{
		if ((((a * 10) + b) + ((c * 10) + a)) == n)
			printf("A = %d, B = %d, C = %d\n", a, b, c);
		++c;
		if (c == 10)
		{
			c = 0;
			++b;
			if (b == 10)
			{
				b = 0;
				++a;
				if (a == 10)
					break ;
			}
		}
	}
}


/*
**	int			main()
**	{
**		equation(42);
**		printf("\n");
**		equation(111);
**		printf("\n");
**		equation(0);
**		printf("\n");
**		equation(-1);
**		return (0);
**	}
*/
