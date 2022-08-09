/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:07:48 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/05 19:07:48 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	moves_to_start(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = my_returner_aorb(frame, stack_name);
	if (stack)
	{
		tmp = my_returner_aorb(frame, stack_name);
		element = my_returner_bigorsmall(frame, flag);
		while (tmp->num != element)
		{
			if (flag == 1)
				frame->s_rotate++;
			else
				frame->b_rotate++;
			tmp = tmp->next;
		}
	}
}

void	moves_to_end(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = my_returner_aorb(frame, stack_name);
	if (stack)
	{
		tmp = my_returner_prevaorb(frame, stack_name);
		element = my_returner_bigorsmall(frame, flag);
		while (tmp->num != element)
		{
			if (flag == 1)
				frame->s_rrotate++;
			else
				frame->b_rrotate++;
			tmp = tmp->prev;
		}
		if (flag == 1)
			frame->s_rrotate++;
		else
			frame->b_rrotate++;
	}
}

static void	moves_smallest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		flag;

	stack = my_returner_aorb(frame, stack_name);
	flag = 1;
	if (stack)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
		if (frame->s_rotate <= frame->s_rrotate)
			frame->s_rrotate = -1;
		else
			frame->s_rotate = -1;
	}
}

static void	moves_biggest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		flag;

	stack = my_returner_aorb(frame, stack_name);
	flag = 2;
	if (stack)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
		if (frame->b_rotate <= frame->b_rrotate)
			frame->b_rrotate = -1;
		else
			frame->b_rotate = -1;
	}
}

void	find_moves(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = my_returner_aorb(frame, stack_name);
	moves_smallest(frame, 'b');
	moves_biggest(frame, 'b');
	if (frame->b_rotate != -1 && (frame->b_rotate >= frame->s_rotate
			&& frame->b_rotate >= frame->s_rrotate))
		frame->b_rotate = -1;
	else if (frame->b_rrotate != -1 && (frame->b_rrotate >= frame->s_rotate
			&& frame->b_rrotate >= frame->s_rrotate))
		frame->b_rrotate = -1;
	else if (frame->s_rotate != -1 && (frame->s_rotate >= frame->b_rotate
			&& frame->s_rotate >= frame->b_rrotate))
		frame->s_rotate = -1;
	else if (frame->s_rrotate != -1 && (frame->s_rrotate >= frame->b_rotate
			&& frame->s_rrotate >= frame->b_rrotate))
		frame->s_rrotate = -1;
	if (frame->s_rotate != -1 || frame->s_rrotate != -1)
		frame->s_flag = 1;
	else if (frame->b_rotate != -1 || frame->b_rrotate != -1)
		frame->b_flag = 1;
}
