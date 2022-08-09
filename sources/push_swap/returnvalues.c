/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returnvalues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:46:47 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:46:50 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	my_returner_flag(t_stack *stack_a_end, t_stack *stack_a)
{
	int	flag;

	flag = 0;
	if (stack_a == stack_a_end)
		flag = 1;
	else
		flag = 0;
	return (flag);
}

int	my_returner_frameflag(t_frame *frame, t_stack *stack_a_end)
{
	int	flag;

	flag = 0;
	if (frame->a == stack_a_end)
		flag = 1;
	else
		flag = 0;
	return (flag);
}

void	my_returner_swap_error(int len, t_frame *frame)
{
	if (len > 10)
		push_swap_error(frame);
}

int	my_returner_bigorsmall(t_frame *frame, int flag)
{
	int	element;

	element = 0;
	if (flag == 1)
		element = frame->smallest;
	else
		element = frame->biggest;
	return (element);
}
