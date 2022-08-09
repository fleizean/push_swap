/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:49:10 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:49:10 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	**stack_namereturn(t_frame *frame, char stack_name)
{
	t_stack	**top;

	if (stack_name == 'a')
		top = &frame->a;
	else
		top = &frame->b;
	return (top);
}

void	stack_add_top(t_frame *frame, char stack_name, int num)
{
	t_stack		**top;
	t_stack		*tmp;

	top = stack_namereturn(frame, stack_name);
	if (*top)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!(tmp))
			push_swap_error(frame);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->num = num;
		*top = (*top)->prev;
	}
	else
	{
		*top = (t_stack *)malloc(sizeof(t_stack));
		if (!(*top))
			push_swap_error(frame);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->num = num;
	}
}
