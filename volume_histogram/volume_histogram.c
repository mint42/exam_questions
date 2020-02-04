/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:14:56 by exam              #+#    #+#             */
/*   Updated: 2019/12/17 11:59:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			volume_histogram(int *histogram, int size)
{
	int		volume;
	int		mid;
	int		height;
	int		i;

	if (!histogram || !size)
		return (0);
	mid = 0;
	volume = 0;
	i = 0;
	while (i < size)
	{
		if (histogram[i] > histogram[mid])
			mid = i;
		++i;
	}
	i = 0;
	height = histogram[i];
	while (i < mid)
	{
		if (histogram[i] > height)
			height = histogram[i];
		volume = volume + (height - histogram[i]);
		++i;
	}
	i = size - 1;
	height = histogram[i];
	while (i > mid)
	{
		if (histogram[i] > height)
			height = histogram[i];
		volume = volume + (height - histogram[i]);
		--i;
	}
	return (volume);
}

/*
**	#include <stdio.h>
**	
**	static void		print_histogram(int *histogram, int size)
**	{
**		int		i;
**	
**		if (!histogram || !size)
**			return ;
**		i = 0;
**		while (i < size)
**		{
**			printf("%d ", histogram[i]);
**			++i;
**		}
**	}
**	
**	int				main()
**	{
**		int		size;
**	
**	//
**	//            #
**	//            # . . . . #
**	//      # . . # . . . . #
**	//      # . . # # . # . #
**	//      # . . # # . # . # . #
**	//      # . . # # . # . # . # . #
**	//  -------------------------------
**	//  0 0 4 0 0 6 0 0 3 0 5 0 2 0 1 0
**	//
**	
**		int		histogram2[16] = {0, 0, 4, 0, 0, 6, 3, 0, 3, 0, 5, 0, 2, 0, 1, 0};
**		size = 16;
**		print_histogram(histogram2, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram2, size));
**	
**	//
**	//            #
**	//            # 
**	//      # . . # 
**	//      # . . # #
**	//  # . # . . # #
**	//  # . # . . # #
**	//  -------------
**	//  2 0 4 0 0 6 3
**	//
**	
**		int		histogram3[7] = {2, 0, 4, 0, 0, 6, 3};
**		size = 7;
**		print_histogram(histogram3, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram3, size));
**	
**	//
**	//    #       
**	//    #      
**	//    # . . # 
**	//  # # . . # 
**	//  # # . . # 
**	//  # # . . # 
**	//  -------------
**	//  3 6 0 0 4 0 0
**	//
**	
**		int		histogram7[7] = {3, 6, 0, 0, 4, 0, 0};
**		size = 7;
**		print_histogram(histogram7, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram7, size));
**	
**	//
**	//            
**	//           
**	//  #            
**	//  #  
**	//  # . . . . . # 
**	//  # . . . . . # 
**	//  -------------
**	//  4 0 0 0 0 0 2
**	//
**	
**		int		histogram9[7] = {4, 0, 0, 0, 0, 0, 2};
**		size = 7;
**		print_histogram(histogram9, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram9, size));
**	
**	//
**	//      # . #
**	//  # . # . #
**	//  ---------
**	//  1 0 2 0 2
**	//
**	
**		int		histogram1[5] = {1, 0, 2, 0, 2};
**		size = 5;
**		print_histogram(histogram1, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram1, size));
**	
**	//
**	//  # . #
**	//  # . #
**	//  -----
**	//  2 0 2
**	//
**	
**		int		histogram4[3] = {2, 0, 2};
**		size = 3;
**		print_histogram(histogram4, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram4, size));
**	
**	//
**	//  # 
**	//  ---
**	//  0 0 
**	//
**	
**		int		histogram5[2] = {1, 0};
**		size = 2;
**		print_histogram(histogram5, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram5, size));
**	
**	//
**	//    #
**	//  ---
**	//  0 0 
**	//
**	
**		histogram5[0] = 0;
**		histogram5[1] = 1;
**		print_histogram(histogram5, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram5, size));
**	
**	//      
**	//  ---
**	//  0 0 
**	//
**	
**		histogram5[0] = 0;
**		histogram5[1] = 0;
**		print_histogram(histogram5, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram5, size));
**	
**	//
**	//  #
**	//  #
**	//  #
**	//  -
**	//  0 
**	//
**	
**		int    histogram6[1] = {3};
**		size = 1;
**		print_histogram(histogram6, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram6, size));
**	
**	//         
**	//  -
**	//  0 
**	//
**	
**		histogram6[0] = 0;
**		print_histogram(histogram6, size);
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(histogram6, size));
**	
**		size = 0;
**		printf("\n");
**		printf("volume histogram: %d\n", volume_histogram(0, size));
**		return (0);
**	}
*/
