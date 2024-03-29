/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5_or_less.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:45:52 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:45:52 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	solve_2(t_frame *frame)
{
	if (frame->a->num > frame->a->next->num)
		do_sa(frame);
}

static void	solve_3(t_frame *frame)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	find_biggest(frame, 'a');
	moves_to_end(frame, 'a', 2);
	if (frame->b_rrotate >= 1)
		while (frame->b_rrotate-- > 1)
			do_rra(frame);
	stack_a = frame->a;
	tmp = frame->a->next;
	if (stack_a->num > tmp->num)
		do_sa(frame);
}

static void	solve_4(t_frame *frame)
{
	t_stack	*stack_a;

	stack_a = frame->a;
	find_biggest_smallest(frame, 'a');
	while (stack_a->num != frame->smallest)
	{
		do_ra(frame);
		stack_a = stack_a->next;
	}
	do_pb(frame);
	solve_3(frame);
	do_pa(frame);
}

static void	solve_5(t_frame *frame)
{
	t_stack	*stack_a_end;
	t_stack	*tmp;
	int		flag;

	flag = 0;
	stack_a_end = frame->a->prev;
	median(frame, 'a');
	while (flag != 1)
	{
		flag = my_returner_frameflag(frame, stack_a_end);
		if (frame->a->num < frame->median)
			do_pb(frame);
		else
			do_ra(frame);
	}
	solve_3(frame);
	tmp = frame->b->next;
	if (frame->b->num < tmp->num)
		do_sb(frame);
	do_pa(frame);
	do_pa(frame);
}

void	solve_5_or_less(t_frame *frame)
{
	if (find_stack_len(frame, 'a') == 2)
		solve_2(frame);
	else if (find_stack_len(frame, 'a') == 3)
		solve_3(frame);
	else if (find_stack_len(frame, 'a') == 4)
		solve_4(frame);
	else if (find_stack_len(frame, 'a') <= 5)
		solve_5(frame);
}
