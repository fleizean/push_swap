/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:42:37 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/05 19:42:37 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_median(t_frame *frame, int split)
{
	t_stack	*stack;
	t_stack	*stack_a_end;
	int		flag;

	stack = frame->a;
	stack_a_end = frame->a->prev;
	flag = 0;
	find_smallest(frame, 'a');
	while (1)
	{
		if (stack == stack_a_end)
			flag = 1;
		if (split == 1 && stack->num <= frame->median)
			do_pb(frame);
		else if (split == 2 && stack->num > frame->median)
			do_pb(frame);
		else if (stack->num == frame->smallest)
			break ;
		else
			do_ra(frame);
		if (flag == 1)
			break ;
		stack = frame->a;
	}
	reset_moves(frame);
}
