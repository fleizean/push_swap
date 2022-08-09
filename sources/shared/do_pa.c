/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:47:38 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:47:38 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_pa(t_frame *frame)
{
	long int	tmp;

	if (frame->b)
	{
		tmp = frame->b->num;
		stack_del_top(frame, 'b');
		stack_add_top(frame, 'a', tmp);
	}
	write(1, "pa\n", 3);
}
