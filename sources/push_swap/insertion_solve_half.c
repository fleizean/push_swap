/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_solve_half.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:58:04 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/05 18:58:04 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_and_push_to_a(t_frame *frame)
{
	if (frame->s_rotate >= 0)
		while (frame->s_rotate--)
			do_rb(frame);
	else if (frame->s_rrotate >= 0)
		while (frame->s_rrotate--)
			do_rrb(frame);
	else if (frame->b_rotate >= 0)
		while (frame->b_rotate--)
			do_rb(frame);
	else if (frame->b_rrotate >= 0)
		while (frame->b_rrotate--)
			do_rrb(frame);
	do_pa(frame);
	if (frame->s_flag)
		do_ra(frame);
	if (frame->b_flag || !frame->b)
		frame->after_rotate++;
	reset_moves(frame);
}

static void	push_big_small(t_frame *frame, t_stack *stack, t_stack *stack_end)
{
	while (1)
	{
		while (stack->num != frame->smallest && stack->num != frame->biggest)
			stack = stack->next;
		if (stack->num == frame->smallest || stack->num == frame->biggest)
		{
			rotate_and_push_to_a(frame);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = frame->b;
	}
}

void	insertion_solve_half(t_frame *frame)
{
	int	split;

	split = 1;
	median(frame, 'a');
	while (frame->a)
	{
		push_median(frame, split);
		while (frame->b)
		{
			find_biggest_smallest(frame, 'b');
			find_moves(frame, 'b');
			if (frame->b && (frame->s_rotate >= 0 || frame->s_rrotate >= 0
					|| frame->b_rotate >= 0 || frame->b_rrotate >= 0))
				push_big_small(frame, frame->b, frame->b->prev);
		}
		while (--frame->after_rotate)
			do_ra(frame);
		split++;
		if (split == 3)
			break ;
	}
}
