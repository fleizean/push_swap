/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quarters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:42:46 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/07 14:24:18 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_quarters(t_frame *frame, t_stack *stack_a, int split)
{
	t_stack	*s_a_end;
	int		flag;

	s_a_end = frame->a->prev;
	flag = 0;
	find_biggest_smallest(frame, 'a');
	ifpusher_quarter(s_a_end, frame, stack_a, split);
	reset_moves(frame);
}
