/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returnvalues_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:46:41 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:46:41 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	throwswaperror(t_frame *frame)
{
	if (!frame->a)
		push_swap_error(frame);
}

t_stack	*my_returner_aorb(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	return (stack);
}

t_stack	*my_returner_prevaorb(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	if (stack_name == 'a')
		stack = frame->a->prev;
	else
		stack = frame->b->prev;
	return (stack);
}
