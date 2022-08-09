/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:38:12 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/05 19:38:12 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_stack_len(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	t_stack	*end;
	int		len;

	len = 0;
	stack = my_returner_aorb(frame, stack_name);
	if (stack)
		end = my_returner_prevaorb(frame, stack_name);
	while (stack)
	{
		len++;
		if (stack == end)
			break ;
		stack = stack->next;
	}
	return (len);
}
