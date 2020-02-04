/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:03:42 by exam              #+#    #+#             */
/*   Updated: 2020/02/03 23:19:39 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_of_2(int n)
{
	int		twos;
	int		place;

	twos = 0;
	place = 1;
	if (n <= 1)
		return (twos);
	while (n / place)
	{
		twos = twos + ((n / (place * 10)) * place);
	   	if (((n % (place * 10)) / place) > 2)
			twos = twos + place;
		else if (((n % (place * 10)) / place) == 2)
			twos = twos + (n % place) + 1;
		place = place * 10;
	}
	return (twos);
}
