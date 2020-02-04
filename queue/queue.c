/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:33:54 by exam              #+#    #+#             */
/*   Updated: 2019/04/16 11:44:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void			*content;
	struct s_node	*next;
};

struct s_queue {
	struct s_node	*first;
	struct s_node	*last;
};

struct s_queue		*init(void)
{
	struct s_queue		*queue;

	queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	if (!queue)
		return (0);
	queue->first = 0;
	queue->last = 0;
	return (queue);
}

void				enqueue(struct s_queue *queue, void *content)
{
	struct s_node		*node;

	if (!queue)
		return ;
	node = (struct s_node *)malloc(sizeof(struct s_node));
	if (!node)
		return ;
	node->content = content;
	node->next = 0;
	if (!(queue->first))
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = queue->last->next;
	}
}

void				*dequeue(struct s_queue *queue)
{
	struct s_node	*temp;
	void			*content;

	if (!queue || !(queue->first))
		return (0);
	temp = queue->first;
	content = queue->first->content;
	queue->first = queue->first->next;
	free((void *)temp);
	return (content);
}

void				*peek(struct s_queue *queue)
{
	if (!queue || !(queue->first))
		return (0);
	return (queue->first->content);
}

int					isEmpty(struct s_queue *queue)
{
	if (!queue || !(queue->first))
		return (1);
	return (0);
	
}
