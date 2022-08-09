/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:47:47 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:47:47 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_pb(t_frame *frame)
{
	long int	tmp;

	if (frame->a)
	{
		tmp = frame->a->num;
		stack_del_top(frame, 'a');
		stack_add_top(frame, 'b', tmp);
	}
	write(1, "pb\n", 3);
}
