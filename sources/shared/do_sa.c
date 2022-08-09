/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:48:28 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:48:28 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_sa(t_frame *frame)
{
	long int	tmp;

	if (frame->a && frame->a->next != frame->a)
	{
		tmp = frame->a->num;
		frame->a->num = frame->a->next->num;
		frame->a->next->num = tmp;
	}
	write(1, "sa\n", 3);
}
