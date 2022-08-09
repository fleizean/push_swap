/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ifquarter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:54:46 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/07 13:41:44 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_first_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > frame->quar / 2)
		do_rb(frame);
	do_pb(frame);
}

static void	push_second_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (frame->median / 4) * 3)
		do_rb(frame);
	do_pb(frame);
}

static void	push_third_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (frame->median / 4) * 5)
		do_rb(frame);
	do_pb(frame);
}

static void	push_fourth_quarter(t_frame *frame)
{
	if (frame->b && frame->b->num > (frame->median / 4) * 7)
		do_rb(frame);
	do_pb(frame);
}

void	ifpusher_quarter(t_stack *s_a_end, t_frame
*frame, t_stack *stack_a, int split)
{
	int	flag;

	flag = 0;
	while (flag != 1)
	{
		flag = my_returner_flag(s_a_end, stack_a);
		if (split == 1 && stack_a->num <= frame->quar)
			push_first_quarter(frame);
		else if (split == 2 && stack_a->num > frame->quar
			&& stack_a->num <= frame->median)
			push_second_quarter(frame);
		else if (split == 3 && stack_a->num > frame->median
			&& stack_a->num <= frame->t_quar)
			push_third_quarter(frame);
		else if (split == 4 && stack_a->num > frame->t_quar)
			push_fourth_quarter(frame);
		else if (split == 4 && stack_a->num == frame->smallest)
			break ;
		else
			do_ra(frame);
		stack_a = frame->a;
	}
}
