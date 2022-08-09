/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_smallest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:41:15 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/05 18:41:15 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_smallest(t_frame *frame, char s_name)
{
	t_stack	*stck;
	t_stack	*tmp;
	t_stack	*end;

	if (s_name == 'a')
		stck = frame->a;
	else
		stck = frame->b;
	tmp = stck;
	if (s_name == 'a')
		end = frame->a->prev;
	else
		end = frame->b->prev;
	frame->smallest = frame->biggest;
	while (1)
	{
		if (tmp->num <= frame->smallest)
			frame->smallest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest(t_frame *frame, char s_name)
{
	t_stack	*stck;
	t_stack	*tmp;
	t_stack	*end;

	if (s_name == 'a')
		stck = frame->a;
	else
		stck = frame->b;
	tmp = stck;
	frame->biggest = tmp->num;
	if (s_name == 'a')
		end = frame->a->prev;
	else
		end = frame->b->prev;
	while (1)
	{
		if (tmp->num > frame->biggest)
			frame->biggest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest_smallest(t_frame *frame, char s_name)
{
	t_stack	*stck;

	if (s_name == 'a')
		stck = frame->a;
	else
		stck = frame->b;
	find_biggest(frame, s_name);
	find_smallest(frame, s_name);
}
