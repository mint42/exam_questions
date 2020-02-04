/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:25:54 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 01:01:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct				s_node
{
	int				value;
	struct s_node	*next;
};

int					is_looping(struct s_node *node)
{
	int		i;

	i = 0;
	while (node)
	{
		if (i == 600000)
			return (1);
		++i;
		node = node->next;
	}
	return (0);	
}
